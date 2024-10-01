#ifndef INCLUDE_SRC_EDGECALCULATION_H_
#define INCLUDE_SRC_EDGECALCULATION_H_

struct Point2_Int;

struct EdgeCalculation {
  int dx;
  int dy;
  int sx;
  int sy;
  int err;

  EdgeCalculation(const Point2_Int &start2, const Point2_Int &end2);

  void update();
};

#endif // INCLUDE_SRC_EDGECALCULATION_H_
