#include "player.h"
#include "master.h"

void UpdatePlayer(player * p, float dt)
{
  p->being.acceleration.x = p->input.x * p->accelerationSpeed;
  p->being.acceleration.y = p->input.y * p->accelerationSpeed;
  UpdateCreature(&p->being, dt);
}
