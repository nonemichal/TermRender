#include "Quaternion.h"
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

Quaternion Quaternion::normalized() const {
  float length = std::sqrt(w * w + x * x + y * y + z * z);
  return Quaternion(w / length, x / length, y / length, z / length);
}

void Quaternion::print() const {
  std::cout << "Quaternion: (" << w << ", " << x << ", " << y << ", " << z
            << ")\n";
}
