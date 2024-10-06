#include "Renderer.h"
#include "ShapeType.h"
#include "ShapeWithVertices.h"
#include <cmath>

int main(int argc, char **argv) {
  Renderer renderer;

  ShapeWithVertices cube(ShapeType::Cube);

  constexpr float fps = 20.0f;

  renderer.start(cube, fps);
}
