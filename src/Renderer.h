#ifndef INCLUDE_SRC_RENDERER_H_
#define INCLUDE_SRC_RENDERER_H_

#include "Logger.h"
#include "Point2_Int.h"
#include "Quaternion.h"
#include "ShapeWithVertices.h"
#include "ShapeWithoutVertices.h"
#include <chrono>
#include <memory>
#include <utility>

class Renderer {
public:
  Renderer();
  ~Renderer();

  void setLogger(const std::string &fileName,
                 std::chrono::milliseconds flushInterval);
  virtual void start(ShapeWithVertices shape, float fps) const;

private:
  std::pair<Point2_Int, Point2_Int> adjustPoints(Point3_Float start,
                                                 Point3_Float end, int width,
                                                 int height) const;

  bool loggerEnabled;
  std::unique_ptr<Logger> logger;

protected:
  void drawEdge(const Point3_Float &start, const Point3_Float &end) const;
  void drawShape(const ShapeWithVertices &shape) const;
  void drawShape(const ShapeWithoutVertices &shape) const;
  void clearScreen() const;
};

#endif // INCLUDE_SRC_RENDERER_H_
