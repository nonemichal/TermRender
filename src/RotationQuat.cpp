#include "RotationQuat.h"
#include "Angles.h"
#include "Axes.h"
#include "Quaternion.h"

RotationQuat::RotationQuat(Angles angles)
    : angles(angles), Quaternion(0, 0, 0, 0) {
  Axes axisX = Axes::newAxisX();
  Axes axisY = Axes::newAxisY();
  Axes axisZ = Axes::newAxisZ();

  Quaternion rotationX = Quaternion::fromAngleAxes(angles.angleX, axisX);
  Quaternion rotationY = Quaternion::fromAngleAxes(angles.angleY, axisY);
  Quaternion rotationZ = Quaternion::fromAngleAxes(angles.angleZ, axisZ);

  Quaternion combinedRotation = rotationX * rotationY * rotationZ;

  this->copyFrom(combinedRotation);
}
