#include "Renderer.h"
#include "ShapeWithVertices.h"
#include "ShapeWithoutVertices.h"
#include "ncurses.h"
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

  for (const auto edge : edges) {
    drawEdge(vertices[edge.first], vertices[edge.second]);
  }

  refresh();
}

void Renderer::drawEdge(const Point3 &vec1, const Point3 &vec2) const {
  int x1 = vec1.getX();
  int y1 = vec1.getY();
  int x2 = vec2.getX();
  int y2 = vec2.getY();

  int dx = std::abs(x2 - x1);
  int dy = std::abs(y2 - y1);
  int sx = (x1 < x2) ? 1 : -1;
  int sy = (y1 < y2) ? 1 : -1;
  int err = dx - dy;

  while (true) {
    mvaddch(x1, y1, '*');

    if (x1 == x2 && y1 == y2)
      break;

    int e2 = 2 * err;
    if (e2 > -dy) {
      err -= dy;
      x1 += sx;
    }
    if (e2 < dx) {
      err += dx;
      y1 += sy;
    }
  }
}

void Renderer::drawShape(const ShapeWithoutVertices &shape) const {}

void Renderer::clearScreen() const {
  clear();
  refresh();
}
