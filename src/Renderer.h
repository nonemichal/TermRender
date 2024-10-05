#ifndef INCLUDE_SRC_RENDERER_H_
#define INCLUDE_SRC_RENDERER_H_

#include "Point2_Int.h"
#include "Quaternion.h"
#include "ShapeWithVertices.h"
#include "ShapeWithoutVertices.h"
#include <utility>

class Renderer {
public:
  Renderer();
  ~Renderer();

  virtual void start(ShapeWithVertices shape, const Quaternion &rotation,
                     float fps) const;

private:
  std::pair<Point2_Int, Point2_Int>
  adjustPoints(Point3_Float start, Point3_Float end, int width, int height) const;

protected:
  void drawEdge(const Point3_Float &start, const Point3_Float &end) const;
  void drawShape(const ShapeWithVertices &shape) const;
  void drawShape(const ShapeWithoutVertices &shape) const;
  void clearScreen() const;
};

#endif // INCLUDE_SRC_RENDERER_H_
