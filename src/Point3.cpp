#include "Point3.h"
#include "Quaternion.h"
#include <cmath>
#include <iostream>

Point3::Point3(float x, float y, float z) : x(x), y(y), z(z) {}

Point3 Point3::operator+(const Point3 &vec) const {
  return Point3(x + vec.x, y + vec.y, z + vec.z);
}
Point3 Point3::operator-(const Point3 &vec) const {
  return Point3(x - vec.x, y - vec.y, z - vec.z);
}
Point3 Point3::operator*(float scalar) const {
  return Point3(x * scalar, y * scalar, z * scalar);
}

int Point3::getX() const { return x; }
int Point3::getY() const { return y; }
int Point3::getZ() const { return z; }

float Point3::length() const { return std::sqrt(x * x + y * y + z * z); }

Point3 Point3::normalized() const {
  float len = length();
  return Point3(x / len, y / len, z / len);
}

Point3 Point3::rotate(const Quaternion &quat) const {
  Quaternion quatPoint3(0.0f, x, y, z);

  Quaternion quatConjugate = quat.conjugate();

  Quaternion quatRotated = quat * quatPoint3 * quatConjugate;

  return quatRotated.toPoint3();
}

void Point3::print() const {
  std::cout << "Point3: (" << x << ", " << y << ", " << z << ")\n";
}
