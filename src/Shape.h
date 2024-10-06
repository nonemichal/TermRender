#ifndef INCLUDE_SRC_SHAPE_H_
#define INCLUDE_SRC_SHAPE_H_

#include "RotationQuat.h"

class Shape {
public:
  virtual ~Shape() = default;

  virtual void rotate(const RotationQuat &rotation) = 0;
  virtual void scale(float scalar) = 0;
  virtual void print() const = 0;
};

#endif // INCLUDE_SRC_SHAPE_H_
