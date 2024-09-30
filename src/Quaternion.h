#ifndef INCLUDE_SRC_QUATERNION_H_
#define INCLUDE_SRC_QUATERNION_H_

#include "Axes.h"

class Vector3;

class Quaternion {
  float w, x, y, z;

public:
  Quaternion(float w, float x, float y, float z);

  Quaternion operator*(const Quaternion &quat) const;

  float length() const;

  Quaternion normalized() const;
  Quaternion conjugate() const;

  static Quaternion fromAngleAxes(float angle, Axes axes);

  Vector3 toVector3() const;

  void print() const;
};

#endif // INCLUDE_SRC_QUATERNION_H_
