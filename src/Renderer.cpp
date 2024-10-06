#include "Renderer.h"
#include "Angles.h"
#include "EdgeCalculation.h"
#include "Point2_Int.h"
#include "RotationQuat.h"
#include "ShapeWithVertices.h"
#include "ShapeWithoutVertices.h"
#include "sys/ioctl.h"
#include "unistd.h"
#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <ncurses.h>
#include <thread>
#include <utility>

Renderer::Renderer() {
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  curs_set(0);
}

Renderer::~Renderer() { endwin(); }

void Renderer::drawShape(const ShapeWithVertices &shape) const {
  auto vertices = shape.getVertices();
  auto edges = shape.getEdges();

  std::for_each(edges.begin(), edges.end(),
                [this, &vertices](const ShapeWithVertices::Edge &edge) {
                  drawEdge(vertices[edge.first], vertices[edge.second]);
                });

  refresh();
}

void Renderer::drawEdge(const Point3_Float &start,
                        const Point3_Float &end) const {
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

  int width = w.ws_row;
  int height = w.ws_col;

  auto adjustedPoints = adjustPoints(start, end, width, height);

  auto start2 = adjustedPoints.first;
  auto end2 = adjustedPoints.second;

  EdgeCalculation calc(start2, end2);

  while (true) {
    mvaddch(start2.x, start2.y, '*');

    if (start2.x == end2.x && start2.y == end2.y)
      break;

    calc.update();
    start2.update(calc);
  }
}

std::pair<Point2_Int, Point2_Int> Renderer::adjustPoints(Point3_Float start,
                                                         Point3_Float end,
                                                         int width,
                                                         int height) const {
  Point2_Int start2Adjusted =
      Point2_Int::newAdjusted(start.x, start.y, width, height);
  Point2_Int end2Adjusted =
      Point2_Int::newAdjusted(end.x, end.y, width, height);

  return std::make_pair(start2Adjusted, end2Adjusted);
}

void Renderer::drawShape(const ShapeWithoutVertices &shape) const {}

void Renderer::clearScreen() const {
  clear();
  refresh();
}

void Renderer::start(ShapeWithVertices shape, float fps) const {
  const int msTime = static_cast<int>(1000.0f / fps);

  constexpr float angle = M_PI / 100.0f;
  const Angles angles(angle, angle, angle);

  RotationQuat rotation(angles);

  while (true) {
    clear();

    drawShape(shape);

    shape.rotate(rotation);

    std::this_thread::sleep_for(std::chrono::milliseconds{msTime});
  }
}
