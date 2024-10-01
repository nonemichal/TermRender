#include "ShapeWithVertices.h"

const std::vector<Point3_Float> &ShapeWithVertices::getVertices() const {
  return vertices;
}

const std::vector<std::pair<double, double>> &
ShapeWithVertices::getEdges() const {
  return edges;
}
