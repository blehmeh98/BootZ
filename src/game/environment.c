#include "environment.h"
#include <math.h>

#include <raylib.h>


void DebugWallDraw(rectWall * rw)
{
  Vector2 size = {rw->b.x - rw->a.x, rw->b.y - rw->a.y};
  DrawRectangleV(rw->a, size, DARKGRAY);
  //printf("Wall drawn\n");
}

void DebugWallLineDraw(wallLine * wl)
{
  DrawLineV(wl->a, wl->b, DARKGRAY);
  //printf("Wall drawn\n");
}

lineEq WallLineToLineEq(wallLine * lw)
{
  lineEq le;
  le.m = (float)(lw->b.y - lw->a.y)/(lw->b.x - lw->a.x); //simple rise over run
  le.b = lw->a.y - le.m * lw->a.x; //(b = y - mx);
  le.x1 = lw->a.x;
  le.x2 = lw->b.x;
  //printf("New line equation determined.\n");
  //printf("m = %f, b = %f, x1 = %f, x2 = %f\n", le.m, le.b, le.x1, le.x2);
  return le;
}

int CircleLineIntersectTest(Vector2 cpos, float crad, lineEq le)
{
  Vector2 lineStartPos = (Vector2){le.x1, le.m * le.x1 + le.b};
  Vector2 lineEndPos = (Vector2){le.x2, le.m * le.x2 + le.b};

  if (CheckCollisionPointCircle(lineStartPos, cpos, crad) || CheckCollisionPointCircle(lineEndPos, cpos, crad))
  {
    printf("Line endpoint inside circle, collision detected\n");
    return 1;
  }
  
  float xMinDist = (cpos.x + le.m * cpos.y - le.m * le.b)/(le.m * le.m + 1);
  
  if (xMinDist < le.x1 || xMinDist > le.x2)
  {
    printf("Circle too far horizontally from line to collide, collision denied\n");
    return 0;
  }
  
  Vector2 closestLinePoint = (Vector2){xMinDist, le.m * xMinDist + le.b};
  if (CheckCollisionPointCircle(closestLinePoint, cpos, crad))
  {
    printf("The closest point on the line is inside of the circle, collision detected\n");
    return 1;
  }
  return 0;
}

Vector2 GetCircleLineIntPos(Vector2 cpos, float crad, lineEq le)
{
  Vector2 lineStartPos = (Vector2){le.x1, le.m * le.x1 + le.b};
  Vector2 lineEndPos = (Vector2){le.x2, le.m * le.x2 + le.b};
  
  float xMinDist = (cpos.x + le.m * cpos.y - le.m * le.b)/(le.m * le.m + 1);
  
  Vector2 closestLinePoint = (Vector2){xMinDist, le.m * xMinDist + le.b};

  return closestLinePoint;

}