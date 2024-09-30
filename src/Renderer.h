#ifndef INCLUDE_SRC_RENDERER_H_
#define INCLUDE_SRC_RENDERER_H_

#include "ShapeWithVertices.h"
#include "ShapeWithoutVertices.h"

class Renderer {
  void drawEdge(const Point3 &vec1, const Point3 &vec2) const;

public:
  Renderer();
  ~Renderer();

  void drawShape(const ShapeWithVertices &shape) const;
  void drawShape(const ShapeWithoutVertices &shape) const;
  void clearScreen() const;
};

#endif // INCLUDE_SRC_RENDERER_H_
