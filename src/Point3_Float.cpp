#include "Point3_Float.h"
#include "Quaternion.h"
#include <cmath>
#include <iostream>

Point3_Float::Point3_Float(float x, float y, float z) : x(x), y(y), z(z) {}

Point3_Float Point3_Float::operator+(const Point3_Float &point3) const {
  return Point3_Float(x + point3.x, y + point3.y, z + point3.z);
}
Point3_Float Point3_Float::operator-(const Point3_Float &point3) const {
  return Point3_Float(x - point3.x, y - point3.y, z - point3.z);
}
Point3_Float Point3_Float::operator*(float scalar) const {
  return Point3_Float(x * scalar, y * scalar, z * scalar);
}

float Point3_Float::length() const { return std::sqrt(x * x + y * y + z * z); }

Point3_Float Point3_Float::normalized() const {
  float len = length();
  return Point3_Float(x / len, y / len, z / len);
}

Point3_Float Point3_Float::rotate(const Quaternion &quat) const {
  Quaternion quatPoint3_Float(0.0f, x, y, z);

  Quaternion quatConjugate = quat.conjugate();

  Quaternion quatRotated = quat * quatPoint3_Float * quatConjugate;

  return quatRotated.toPoint3_Float();
}

void Point3_Float::print() const {
  std::cout << "Point3_Float: (" << x << ", " << y << ", " << z << ")\n";
}
