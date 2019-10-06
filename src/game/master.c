#include "master.h"
#include <math.h>

void UpdateCreature(creature * c, float dt)
{
  if (abs(c->velocity.x) < 1){c->velocity.x = 0;}
  if (abs(c->velocity.y) < 1){c->velocity.y = 0;} //basic velocity dampening
  //if velocity is too small to be noticeable, set it to 0 to make further calculations easier and faster
  //without this, objects may twitch as they get so small that friction forces them to switch between positive and negative
  
  if (c->acceleration.x == 0){c->acceleration.x = -300 * mathSignF(c->velocity.x);}
  if (c->acceleration.y == 0){c->acceleration.y = -300 * mathSignF(c->velocity.y);} //basic friction, for if there's no acceleration but there is velocity

  c->velocity.x += c->acceleration.x * dt;
  c->velocity.y += c->acceleration.y * dt; //modify velocity by acceleration

  if (abs(c->velocity.x) > c->maxspeed)
  {
    c->velocity.x = c->maxspeed * mathSignF(c->velocity.x);
  }
  if (abs(c->velocity.y) > c->maxspeed)
  {
    c->velocity.y = c->maxspeed * mathSignF(c->velocity.y);

  }
  c->position.x += c->velocity.x * dt;
  c->position.y += c->velocity.y * dt;  
}

