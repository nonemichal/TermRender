#include "ShapeWithVertices.h"
#include "Point3_Float.h"
#include "ShapeType.h"
#include <algorithm>
#include <iostream>

ShapeWithVertices::ShapeWithVertices(std::vector<Point3_Float> vertices,
                                     std::vector<Edge> edges)
    : vertices(vertices), edges(edges) {}

ShapeWithVertices::ShapeWithVertices(ShapeType shapeType) {
  switch (shapeType) {
  case ShapeType::Cube:
    vertices = {
        Point3_Float(-0.5f, 0.5f, 0.5f),  Point3_Float(0.5f, 0.5f, 0.5f),
        Point3_Float(0.5f, -0.5f, 0.5f),  Point3_Float(-0.5f, -0.5f, 0.5f),
        Point3_Float(-0.5f, 0.5f, -0.5f), Point3_Float(0.5f, 0.5f, -0.5f),
        Point3_Float(0.5f, -0.5f, -0.5f), Point3_Float(-0.5f, -0.5f, -0.5f)};
    edges = {{0, 1}, {1, 2}, {2, 3}, {3, 0}, {3, 7}, {7, 6},
             {6, 2}, {7, 4}, {4, 5}, {5, 6}, {0, 4}, {1, 5}};
    break;
  default:
    break;
  }
}

void ShapeWithVertices::rotate(const RotationQuat &rotation) {
  std::transform(
      vertices.begin(), vertices.end(), vertices.begin(),
      [rotation](Point3_Float point) { return point.rotate(rotation); });
}

void ShapeWithVertices::scale(float scalar) {}

void ShapeWithVertices::print() const {
  std::for_each(vertices.begin(), vertices.end(),
                [](Point3_Float point3) { point3.print(); });
  std::cout << "\n";
}

const std::vector<Point3_Float> &ShapeWithVertices::getVertices() const {
  return vertices;
}

const std::vector<std::pair<double, double>> &
ShapeWithVertices::getEdges() const {
  return edges;
}
