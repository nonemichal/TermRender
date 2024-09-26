#ifndef INCLUDE_SRC_QUATERNION_H_
#define INCLUDE_SRC_QUATERNION_H_

class Quaternion {
  float w, x, y, z;

public:
  Quaternion(float w, float x, float y, float z);

  Quaternion operator*(const Quaternion &q) const;

  Quaternion normalized() const;

  void print() const;
};

#endif // INCLUDE_SRC_QUATERNION_H_
