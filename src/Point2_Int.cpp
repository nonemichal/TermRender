#include "Point2_Int.h"

Point2_Int::Point2_Int(int x, int y) : x(x), y(y) {};

void Point2_Int::update(const EdgeCalculation &calc) {
  int e2 = 2 * calc.err;

  if (e2 > -calc.dy) {
    x += calc.sx;
  }

  if (e2 < calc.dx) {
    y += calc.sy;
  }
}
