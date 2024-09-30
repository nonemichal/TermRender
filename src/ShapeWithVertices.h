#ifndef INCLUDE_SRC_SHAPEWITHVERTICES_H_
#define INCLUDE_SRC_SHAPEWITHVERTICES_H_

#include "Shape.h"
#include "Vector3.h"
#include <utility>
#include <vector>

class ShapeWithVertices : public Shape {
  static const std::vector<std::pair<double, double>> edges;
  std::vector<Vector3> vertices;
};

#endif // INCLUDE_SRC_SHAPEWITHVERTICES_H_
