#ifndef INCLUDE_SRC_POINT2_H_
#define INCLUDE_SRC_POINT2_H_

#include "EdgeCalculation.h"

struct Point2_Int {
  int x;
  int y;

  Point2_Int(int x, int y);

  static Point2_Int newAdjusted(float x, float y, int width, int height);

  void update(const EdgeCalculation &calc);
};

#endif // INCLUDE_SRC_POINT2_H_
