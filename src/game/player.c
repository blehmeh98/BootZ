#include "player.h"
#include "master.h"

#include <math.h>
#include <raylib.h>

#define MATH_PI 3.1415926535897932384626433


void UpdatePlayer(player * p, float dt)
{
  p->being.acceleration.x = p->input.x * p->accelerationSpeed;
  p->being.acceleration.y = p->input.y * p->accelerationSpeed;
  p->being.direction = atan((GetMouseX() - p->being.position.x)/(GetMouseY() - p->being.position.y));
  printf("%f\n", p->being.direction);
  if (GetMouseY() < p->being.position.y)
  {
    p->being.direction = p->being.direction + MATH_PI;
  }
  UpdateCreature(&p->being, dt);
}

void DrawPlayer(player * p)
{
  DrawCircle(p->being.position.x, p->being.position.y, 25, ORANGE);
  DrawLineV(p->being.position, (Vector2){p->being.position.x + 50 * sin(p->being.direction), p->being.position.y + 50 * cos(p->being.direction)}, DARKGRAY);
}
