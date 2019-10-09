#include "environment.h"
#include <math.h>

#include <raylib.h>

void DebugWallDraw(rectWall * rw)
{
  Vector2 size = {rw->b.x - rw->a.x, rw->b.y - rw->a.y};
  DrawRectangleV(rw->a, size, DARKGRAY);
  printf("Wall drawn\n");
}