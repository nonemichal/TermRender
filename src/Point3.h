#ifndef INCLUDE_SRC_VECTOR3_H_
#define INCLUDE_SRC_VECTOR3_H_

#include "Quaternion.h"

class Point3 {
  float x, y, z;

public:
  Point3(float x, float y, float z);

  Point3 operator+(const Point3 &vec) const;
  Point3 operator-(const Point3 &vec) const;
  Point3 operator*(float scalar) const;

  int getX() const;
  int getY() const;
  int getZ() const;

  float length() const;

  Point3 normalized() const;

  Point3 rotate(const Quaternion &quat) const;

  void print() const;
};

#endif // INCLUDE_SRC_VECTOR3_H_
