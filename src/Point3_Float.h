#ifndef INCLUDE_SRC_VECTOR3_H_
#define INCLUDE_SRC_VECTOR3_H_

#include "Quaternion.h"
#include "RotationQuat.h"

struct Point3_Float {
  float x, y, z;

  Point3_Float(float x, float y, float z);

  Point3_Float operator+(const Point3_Float &point3) const;
  Point3_Float operator-(const Point3_Float &point3) const;
  Point3_Float operator*(float scalar) const;

  float length() const;

  Point3_Float normalized() const;

  Point3_Float rotate(const RotationQuat &rotation) const;

  void print() const;
};

#endif // INCLUDE_SRC_VECTOR3_H_
