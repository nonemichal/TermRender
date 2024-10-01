#include "EdgeCalculation.h"
#include "Point2_Int.h"
#include <cstdlib>

EdgeCalculation::EdgeCalculation(const Point2_Int &start2,
                                 const Point2_Int &end2) {
  dx = std::abs(end2.x - start2.x);
  dy = std::abs(end2.y - start2.y);
  sx = (start2.x < end2.x) ? 1 : -1;
  sy = (start2.y < end2.y) ? 1 : -1;
  err = dx - dy;
}

void EdgeCalculation::update() {
  int e2 = 2 * err;

  if (e2 > -dy) {
    err -= dy;
  }

  if (e2 < dx) {
    err += dx;
  }
}
