#ifndef INCLUDE_SRC_VECTOR3_H_
#define INCLUDE_SRC_VECTOR3_H_

#include "Quaternion.h"

class Vector3 {
  float x, y, z;

public:
  Vector3(float x, float y, float z);

  Vector3 operator+(const Vector3 &vec) const;
  Vector3 operator-(const Vector3 &vec) const;
  Vector3 operator*(float scalar) const;

  float length() const;

  Vector3 normalized() const;

  Vector3 rotate(const Quaternion &quat) const;

  void print() const;
};

#endif // INCLUDE_SRC_VECTOR3_H_
