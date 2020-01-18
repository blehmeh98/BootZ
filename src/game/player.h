#ifndef PLAYER_H
#define PLAYER_H
#include "master.h"
#include "environment.h"

typedef struct pInput
{
  signed char x;
  signed char y; //positive or negative to indicate direction
  signed char shoot; //signed for altfire capabilities? feeling creative, might remove later
  //like, lets say I have an M16 with an underbarrel grenade launcher
  //I could set it to 0 for not shoot, 1 for semi auto shot, 2 for burst shot, 3 for full auto
  //or -1 to load and launch a frag grenade, -2 for a smoke grenade, -3 for an incendiary, etc.
  char reload;
  char sprint;
  char weapon_switch; //0 for all weapons holstered, 1 for knife, 2 for standard sidearm
  //most of these are set to either one or zero, since they're either on or off
} pInput;


typedef struct player
{
creature being;
pInput input;
float accelerationSpeed;
int score;
int kills;
} player;

void UpdatePlayer(player * p, float dt, wallLine * wl);
void DrawPlayer(player * p);
int PlayerCollideWithLines(player * p, wallLine * wl);
#include "player.c"
#endif
