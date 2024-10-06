#ifndef INCLUDE_SRC_ROTATION_H_
#define INCLUDE_SRC_ROTATION_H_

#include "Angles.h"
#include "Quaternion.h"

class RotationQuat : public Quaternion {
  Angles angles;

public:
  RotationQuat(Angles angles);
};

#endif // INCLUDE_SRC_ROTATION_H_
