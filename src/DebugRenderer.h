#ifndef INCLUDE_SRC_DEBUGRENDERER_H_
#define INCLUDE_SRC_DEBUGRENDERER_H_

#include "Renderer.h"

class DebugRenderer : public Renderer {
  void printAdjusted(const ShapeWithVertices &shape) const;

public:
  void start(ShapeWithVertices shape,

             float fps) const override;
};

#endif // INCLUDE_SRC_DEBUGRENDERER_H_
