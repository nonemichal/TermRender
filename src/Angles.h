#ifndef INCLUDE_SRC_ANGLES_H_
#define INCLUDE_SRC_ANGLES_H_

struct Angles {
  float angleX;
  float angleY;
  float angleZ;

  Angles(float angleX, float angleY, float angleZ)
      : angleX(angleX), angleY(angleY), angleZ(angleZ) {};
};

#endif // INCLUDE_SRC_ANGLES_H_
