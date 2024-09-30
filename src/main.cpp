#include "Axes.h"
#include "Quaternion.h"
#include "Point3.h"
#include <cmath>

int main(int argc, char **argv) {
  Point3 point3(1.0f, 0.0f, 0.0f);

  float angle = M_PI / 2;
  Axes axisZ = {0.0f, 0.0f, 1.0f};
  Quaternion rotation = Quaternion::fromAngleAxes(angle, axisZ);

  Point3 roatedPoint3 = point3.rotate(rotation);

  roatedPoint3.print();
}
