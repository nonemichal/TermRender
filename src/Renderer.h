#ifndef INCLUDE_SRC_RENDERER_H_
#define INCLUDE_SRC_RENDERER_H_

#include "Axes.h"
#include "Quaternion.h"
#include "ShapeWithVertices.h"
#include "ShapeWithoutVertices.h"

class Renderer {
  void drawEdge(const Point3_Float &start, const Point3_Float &end) const;
  void drawShape(const ShapeWithVertices &shape) const;
  void drawShape(const ShapeWithoutVertices &shape) const;
  void clearScreen() const;

public:
  Renderer();
  ~Renderer();

  void startRendering(ShapeWithVertices &shape, float angleDelta, const Axes &axisXYZ, float fps);
};

#endif // INCLUDE_SRC_RENDERER_H_
