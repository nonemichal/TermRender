#include "Quaternion.h"
#include "Axes.h"
#include "Point3_Float.h"
#include <cmath>
#include <iostream>

Quaternion::Quaternion(float w, float x, float y, float z)
    : w(w), x(x), y(y), z(z) {}

Quaternion Quaternion::operator*(const Quaternion &quat) const {
  return Quaternion(w * quat.w - x * quat.x - y * quat.y - z * quat.z,
                    w * quat.x + x * quat.w + y * quat.z - z * quat.y,
                    w * quat.y - x * quat.z + y * quat.w + z * quat.x,
                    w * quat.z + x * quat.y - y * quat.x + z * quat.w);
}

Quaternion &Quaternion::copyFrom(const Quaternion &quat) {
  w = quat.w;
  x = quat.x;
  y = quat.y;
  z = quat.z;

  return *this;
}

float Quaternion::length() const {
  return std::sqrt(w * w + x * x + y * y + z * z);
}

Quaternion Quaternion::normalized() const {
  float len = length();
  return Quaternion(w / len, x / len, y / len, z / len);
}

Quaternion Quaternion::conjugate() const { return Quaternion(w, -x, -y, -z); }

Quaternion Quaternion::fromAngleAxes(float angle, Axes axes) {
  float halfAngle = angle / 2.0f;
  float sin = std::sin(halfAngle);
  float cos = std::cos(halfAngle);
  float ax = axes.axisX;
  float ay = axes.axisY;
  float az = axes.axisZ;

  return Quaternion(cos, ax * sin, ay * sin, az * sin);
}

Point3_Float Quaternion::toPoint3() const { return Point3_Float(x, y, z); }

void Quaternion::print() const {
  std::cout << "Quaternion: (" << w << ", " << x << ", " << y << ", " << z
            << ")" << std::endl;
}
