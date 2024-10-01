#include "Renderer.h"
#include "EdgeCalculation.h"
#include "Point2_Int.h"
#include "ShapeWithVertices.h"
#include "ShapeWithoutVertices.h"
#include "ncurses.h"
#include <algorithm>
#include <cstdlib>

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

void Renderer::drawEdge(const Point3_Float &start, const Point3_Float &end) const {
  Point2_Int start2(start.x, start.y);
  Point2_Int end2(end.x, end.y);

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
