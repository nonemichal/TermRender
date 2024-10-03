#include "Renderer.h"
#include "EdgeCalculation.h"
#include "Point2_Int.h"
#include "ShapeWithVertices.h"
#include "ShapeWithoutVertices.h"
#include "unistd.h"
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ncurses.h>

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
  int width = getmaxx(stdscr);
  int height = getmaxy(stdscr);

  Point2_Int start2 = Point2_Int::newAdjusted(start.x, start.y, width, height);
  Point2_Int end2 = Point2_Int::newAdjusted(end.x, end.y, width, height);

  EdgeCalculation calc(start2, end2);

  while (true) {
    mvaddch(start2.x, start2.y, '*');

    if (start2.x == end2.x && start2.y == end2.y)
      break;

    calc.update();
    start2.update(calc);
  }
}

void Renderer::drawShape(const ShapeWithoutVertices &shape) const {}

void Renderer::clearScreen() const {
  clear();
  refresh();
}

void Renderer::startRendering(ShapeWithVertices &shape, float angleDelta,
                              const Axes &axisXYZ, float fps) {
  const int usTime = static_cast<int>(1000000.0f / fps);
  float angle = 0;

  while (true) {
    clear();

    drawShape(shape);

    Quaternion rotation = Quaternion::fromAngleAxes(angle, axisXYZ);

    shape.rotate(rotation);

    angle = fmod(angle, 2 * M_PI) + angleDelta;

    usleep(usTime);
  }
}
