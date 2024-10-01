#include "Axes.h"
#include "Quaternion.h"
#include "Point3_Float.h"
#include <cmath>

int main(int argc, char **argv) {
  Point3_Float point3(1.0f, 0.0f, 0.0f);

  float angle = M_PI / 2;
  Axes axisZ = {0.0f, 0.0f, 1.0f};
  Quaternion rotation = Quaternion::fromAngleAxes(angle, axisZ);

  Point3_Float roatedPoint3_Float = point3.rotate(rotation);

  roatedPoint3_Float.print();
}
