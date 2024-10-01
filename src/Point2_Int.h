#ifndef INCLUDE_SRC_POINT2_H_
#define INCLUDE_SRC_POINT2_H_

#include "EdgeCalculation.h"

struct Point2_Int {
  int x;
  int y;

  Point2_Int(int x, int y);

  void update(const EdgeCalculation &calc);
};

#endif // INCLUDE_SRC_POINT2_H_
