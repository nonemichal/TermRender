#include "Renderer.h"
#include "ShapeType.h"
#include "ShapeWithVertices.h"
#include <chrono>
#include <cmath>

int main(int argc, char **argv) {
  Renderer renderer;

  ShapeWithVertices cube(ShapeType::Cube);

  constexpr float fps = 20.0f;

  renderer.setLogger("../logs/render_logs.txt", std::chrono::milliseconds(1000));
  renderer.start(cube, fps);
}
