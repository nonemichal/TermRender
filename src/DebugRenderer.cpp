#include "DebugRenderer.h"
#include "Point2_Int.h"
#include "ShapeWithVertices.h"
#include "sys/ioctl.h"
#include <algorithm>
#include <iostream>
#include <unistd.h>

void DebugRenderer::start(ShapeWithVertices shape, const Quaternion &rotation,
                          float fps) const {
  const int usTime = static_cast<int>(1000000.0f / fps);

  while (true) {
    shape.print();
    printAdjusted(shape);

    shape.rotate(rotation);

    usleep(usTime);
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
