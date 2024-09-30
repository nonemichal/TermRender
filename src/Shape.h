#ifndef INCLUDE_SRC_SHAPE_H_
#define INCLUDE_SRC_SHAPE_H_

#include "Quaternion.h"

class Shape {
public:
  virtual Shape &rotate(const Quaternion &quat) = 0;
  virtual Shape &scale(float scalar) = 0;

  virtual void print() const = 0;

  virtual ~Shape() = default;
};

#endif // INCLUDE_SRC_SHAPE_H_
