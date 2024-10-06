#ifndef INCLUDE_SRC_SHAPEWITHVERTICES_H_
#define INCLUDE_SRC_SHAPEWITHVERTICES_H_

#include "Point3_Float.h"
#include "RotationQuat.h"
#include "Shape.h"
#include "ShapeType.h"
#include <utility>
#include <vector>

class ShapeWithVertices : public Shape {
public:
  using Edge = std::pair<double, double>;

private:
  std::vector<Point3_Float> vertices;
  std::vector<Edge> edges;

public:
  ShapeWithVertices(std::vector<Point3_Float> vertices,
                    std::vector<Edge> edges);
  ShapeWithVertices(ShapeType shapeType);
  virtual ~ShapeWithVertices() = default;

  void rotate(const RotationQuat &rotation) override;
  void scale(float scalar) override;
  void print() const override;

  const std::vector<Point3_Float> &getVertices() const;
  const std::vector<Edge> &getEdges() const;
};

#endif // INCLUDE_SRC_SHAPEWITHVERTICES_H_
