#include "Axes.h"
#include "Quaternion.h"
#include "Renderer.h"
#include "ShapeType.h"
#include "ShapeWithVertices.h"
#include <cmath>

int main(int argc, char **argv) {
  Renderer renderer;

  ShapeWithVertices cube(ShapeType::Cube);

  constexpr float fps = 20.0f;

  float angleX = M_PI / 100.0f;
  float angleY = M_PI / 100.0f;
  float angleZ = M_PI / 100.0f;

  Axes axisX = {1.0f, 0.0f, 0.0f};
  Axes axisY = {0.0f, 1.0f, 0.0f};
  Axes axisZ = {0.0f, 0.0f, 1.0f};


  Quaternion rotationX = Quaternion::fromAngleAxes(angleX, axisX);
  Quaternion rotationY = Quaternion::fromAngleAxes(angleY, axisY);
  Quaternion rotationZ = Quaternion::fromAngleAxes(angleZ, axisZ);

  Quaternion combinedRotation = rotationX * rotationY * rotationZ;

  Axes axisXYZ = {1.0f, 1.0f, 1.0f};

  renderer.start(cube, combinedRotation, fps);
}
