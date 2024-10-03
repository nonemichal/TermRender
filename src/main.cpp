#include "Axes.h"
#include "Renderer.h"
#include "ShapeType.h"
#include "ShapeWithVertices.h"
#include <cmath>

int main(int argc, char **argv) {
  Renderer renderer;

  ShapeWithVertices cube(ShapeType::Cube);

  constexpr float fps = 60.0f;

  float angleDelta = M_PI / (2.0f * fps);
  Axes axisXYZ = {1.0f, 1.0f, 1.0f};

  renderer.startRendering(cube, angleDelta, axisXYZ, fps);
}
