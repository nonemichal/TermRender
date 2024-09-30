#ifndef INCLUDE_SRC_SHAPE_H_
#define INCLUDE_SRC_SHAPE_H_

#include "Quaternion.h"

class Shape {
public:
  virtual Shape &rotate(const Quaternion &quat) = 0;
  virtual Shape &zoom(float scalar) = 0;

  virtual void draw() const = 0;

  virtual void print() const = 0;

  virtual ~Shape() = default;
};

#endif // INCLUDE_SRC_SHAPE_H_
