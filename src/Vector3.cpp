#include "Vector3.h"
#include "Quaternion.h"
#include <cmath>
#include <iostream>

Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

Vector3 Vector3::operator+(const Vector3 &vec) const {
  return Vector3(x + vec.x, y + vec.y, z + vec.z);
}
Vector3 Vector3::operator-(const Vector3 &vec) const {
  return Vector3(x - vec.x, y - vec.y, z - vec.z);
}
Vector3 Vector3::operator*(float scalar) const {
  return Vector3(x * scalar, y * scalar, z * scalar);
}

float Vector3::length() const { return std::sqrt(x * x + y * y + z * z); }

Vector3 Vector3::normalized() const {
  float len = length();
  return Vector3(x / len, y / len, z / len);
}

Vector3 Vector3::rotate(const Quaternion &quat) const {
  Quaternion qVector(0.0f, x, y, z);

  Quaternion qConjugate = quat.conjugate();

  Quaternion qRotated = quat * qVector * qConjugate;

  return qRotated.toVector3();
}

void Vector3::print() const {
  std::cout << "Vector3: (" << x << ", " << y << ", " << z << ")\n";
}
