#ifndef INCLUDE_SRC_SHAPEWITHVERTICES_H_
#define INCLUDE_SRC_SHAPEWITHVERTICES_H_

#include "Point3_Float.h"
#include "Shape.h"
#include <utility>
#include <vector>

class ShapeWithVertices : public Shape {
public:
  using Edge = std::pair<double, double>;

private:
  const std::vector<Edge> edges;
  std::vector<Point3_Float> vertices;

public:
  const std::vector<Point3_Float> &getVertices() const;
  const std::vector<Edge> &getEdges() const;
};

#endif // INCLUDE_SRC_SHAPEWITHVERTICES_H_
