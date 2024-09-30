#include "Axes.h"
#include "Quaternion.h"
#include "Vector3.h"
#include <cmath>

int main(int argc, char **argv) {
  Vector3 vec3(1.0f, 0.0f, 0.0f);

  float angle = M_PI / 2;
  Axes axisZ = {0.0f, 0.0f, 1.0f};
  Quaternion rotation = Quaternion::fromAngleAxes(angle, axisZ);

  Vector3 rotatedVec3 = vec3.rotate(rotation);

  rotatedVec3.print();
}
