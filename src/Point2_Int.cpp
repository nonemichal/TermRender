#include "Point2_Int.h"
#include <cmath>
#include <iostream>

Point2_Int::Point2_Int(int x, int y) : x(x), y(y) {};

Point2_Int Point2_Int::newAdjusted(float x, float y, int width, int height) {
  float halfWidth = static_cast<float>(width) / 2.0f;
  float halfHeight = static_cast<float>(height) / 2.0f;

  float roundedX = std::round((x + 1.0f) * halfWidth);
  float roundedY = std::round((y + 1.0f) * halfHeight);

  int newX = static_cast<int>(roundedX);
  int newY = static_cast<int>(roundedY);

  return Point2_Int(newX, newY);
}

void Point2_Int::update(const EdgeCalculation &calc) {
  int e2 = 2 * calc.err;

  if (e2 > -calc.dy) {
    x += calc.sx;
  }

  if (e2 < calc.dx) {
    y += calc.sy;
  }
}

void Point2_Int::print() const {
  std::cout << "Point2_Int: (" << x << ", " << y << ")\n"; 
}
