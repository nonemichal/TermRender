#ifndef INCLUDE_SRC_SHAPEWITHVERTICES_H_
#define INCLUDE_SRC_SHAPEWITHVERTICES_H_

#include "Point3.h"
#include "Shape.h"
#include <utility>
#include <vector>

using Edge = std::pair<double, double>;

class ShapeWithVertices : public Shape {
  static const std::vector<Edge> edges;
  std::vector<Point3> vertices;

public:
  const std::vector<Point3> &getVertices() const;
  const std::vector<Edge> &getEdges() const;
};

#endif // INCLUDE_SRC_SHAPEWITHVERTICES_H_
