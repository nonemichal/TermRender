#include "ShapeWithVertices.h"
#include "Point3_Float.h"
#include "ShapeType.h"
#include <algorithm>

ShapeWithVertices::ShapeWithVertices(std::vector<Point3_Float> vertices,
                                     std::vector<Edge> edges)
    : vertices(vertices), edges(edges) {}

ShapeWithVertices::ShapeWithVertices(ShapeType shapeType) {
  switch (shapeType) {
  case ShapeType::Cube: {
    vertices = {
        Point3_Float(-0.5f, 0.5f, 0.5f),  Point3_Float(0.5f, 0.5f, 0.5f),
        Point3_Float(0.5f, -0.5f, 0.5f),  Point3_Float(-0.5f, -0.5f, 0.5f),
        Point3_Float(-0.5f, 0.5f, -0.5f), Point3_Float(0.5f, 0.5f, -0.5f),
        Point3_Float(0.5f, -0.5f, -0.5f), Point3_Float(-0.5f, -0.5f, -0.5f)};
    edges = {{1, 2}, {2, 3}, {3, 4}, {4, 1}, {4, 8}, {8, 7},
             {7, 3}, {8, 5}, {5, 6}, {6, 7}, {1, 5}, {2, 6}};
    break;
  }
  }
}

void ShapeWithVertices::rotate(const Quaternion &quat) {
  std::transform(vertices.begin(), vertices.end(), vertices.begin(),
                 [quat](Point3_Float point) { return point.rotate(quat); });
}

void ShapeWithVertices::scale(float scalar) {}

void ShapeWithVertices::print() const {}

const std::vector<Point3_Float> &ShapeWithVertices::getVertices() const {
  return vertices;
}

const std::vector<std::pair<double, double>> &
ShapeWithVertices::getEdges() const {
  return edges;
}
