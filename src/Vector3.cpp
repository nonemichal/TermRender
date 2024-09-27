#include "Vector3.h"
#include "Quaternion.h"
#include <cmath>
#include <iostream>

Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

Vector3 Vector3::operator+(const Vector3 &v) const {
  return Vector3(x + v.x, y + v.y, z + v.z);
}
Vector3 Vector3::operator-(const Vector3 &v) const {
  return Vector3(x - v.x, y - v.y, z - v.z);
}
Vector3 Vector3::operator*(float scalar) const {
  return Vector3(x * scalar, y * scalar, z * scalar);
}

float Vector3::length() const { return std::sqrt(x * x + y * y + z * z); }

Vector3 Vector3::normalized() const {
  float len = length();
  return Vector3(x / len, y / len, z / len);
}

Vector3 Vector3::rotate(const Quaternion &q) const {
  Quaternion vectorQuat(0.0f, x, y, z);
  Quaternion conjugateQuat = q.conjugate();

  Quaternion rotatedQuat = q * vectorQuat * conjugateQuat;

  return rotatedQuat.toVector3();
}

void Vector3::print() const {
  std::cout << "Vector3: (" << x << ", " << y << ", " << z << ")\n";
}
