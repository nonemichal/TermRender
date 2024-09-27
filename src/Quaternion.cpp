#include "Quaternion.h"
#include "Axes.h"
#include "Vector3.h"
#include <cmath>
#include <iostream>

Quaternion::Quaternion(float w, float x, float y, float z)
    : w(w), x(x), y(y), z(z) {}

Quaternion Quaternion::operator*(const Quaternion &q) const {
  return Quaternion(w * q.w - x * q.x - y * q.y - z * q.z,
                    w * q.x + x * q.w + y * q.z - z * q.y,
                    w * q.y - x * q.z + y * q.w + z * q.x,
                    w * q.z + x * q.y - y * q.x + z * q.w);
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
  float ax = axes.ax;
  float ay = axes.ay;
  float az = axes.az;

  return Quaternion(cos, ax * sin, ay * sin, az * sin);
}

Vector3 Quaternion::toVector3() const { return Vector3(x, y, z); }

void Quaternion::print() const {
  std::cout << "Quaternion: (" << w << ", " << x << ", " << y << ", " << z
            << ")\n";
}
