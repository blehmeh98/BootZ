#include "player.h"
#include "master.h"
#include "environment.h"

#include <math.h>
#include <raylib.h>

#define MATH_PI 3.1415926535897932384626433 //no joke, I typed this all out from memory


int PlayerCollideWithLines(player * p, wallLine * wl)
{
  lineEq le = WallLineToLineEq(wl);
  return CircleLineIntersectTest(p->being.position, 25, le);
}

void UpdatePlayer(player * p, float dt, wallLine * wl)
{
  p->being.acceleration.x = p->input.x * p->accelerationSpeed;
  p->being.acceleration.y = p->input.y * p->accelerationSpeed;
  p->being.direction = atan((GetMouseX() - p->being.position.x)/(GetMouseY() - p->being.position.y));
  printf("%f\n", p->being.direction);
  if (GetMouseY() < p->being.position.y)
  {
    p->being.direction = p->being.direction + MATH_PI;
  }
  
  player nextFramePlayer = *p;
  UpdateCreature(&nextFramePlayer.being, dt);
  if (PlayerCollideWithLines(&nextFramePlayer, wl) > 0)
  {
    p->being.velocity = (Vector2){0, 0};
    p->being.acceleration = (Vector2){0, 0};
  }
  
  UpdateCreature(&p->being, dt);
}

void DrawPlayer(player * p)
{
  DrawCircle(p->being.position.x, p->being.position.y, 25, ORANGE);
  DrawLineV(p->being.position, (Vector2){p->being.position.x + 50 * sin(p->being.direction), p->being.position.y + 50 * cos(p->being.direction)}, DARKGRAY);
}
