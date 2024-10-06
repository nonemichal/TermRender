#ifndef INCLUDE_SRC_AXES_H_
#define INCLUDE_SRC_AXES_H_

struct Axes {
  float axisX;
  float axisY;
  float axisZ;

  Axes(float axisX, float axisY, float axisZ)
      : axisX(axisX), axisY(axisY), axisZ(axisZ) {}

  static const Axes newAxisX() { return Axes(1.0f, 0.0f, 0.0f); }
  static const Axes newAxisY() { return Axes(0.0f, 1.0f, 0.0f); }
  static const Axes newAxisZ() { return Axes(0.0f, 0.0f, 1.0f); }
};

#endif // INCLUDE_SRC_AXES_H_
