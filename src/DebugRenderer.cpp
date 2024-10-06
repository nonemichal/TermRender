#include "DebugRenderer.h"
#include "Point2_Int.h"
#include "RotationQuat.h"
#include "ShapeWithVertices.h"
#include "sys/ioctl.h"
#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <thread>
#include <unistd.h>

void DebugRenderer::start(ShapeWithVertices shape, float fps) const {
  const int msTime = static_cast<int>(1000.0f / fps);

  constexpr float angle = M_PI / 100.0f;
  const Angles angles(angle, angle, angle);

  RotationQuat rotation(angles);

  while (true) {
    shape.print();
    printAdjusted(shape);

    shape.rotate(rotation);

    std::this_thread::sleep_for(std::chrono::milliseconds{msTime});
  }
}

void DebugRenderer::printAdjusted(const ShapeWithVertices &shape) const {
  auto vertices = shape.getVertices();

  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

  int width = w.ws_row;
  int height = w.ws_col;

  std::for_each(vertices.begin(), vertices.end(), [&](Point3_Float point3) {
    auto adjustedPoint =
        Point2_Int::newAdjusted(point3.x, point3.y, width, height);
    adjustedPoint.print();
  });
  std::cout << std::endl;
}
