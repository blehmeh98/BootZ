#ifndef PLAYER_H
#define PLAYER_H
#include "master.h"

typedef struct pInput
{
  signed char x;
  signed char y; //positive or negative to indicate direction
  char shoot;
  char reload;
  char sprint;
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

void UpdatePlayer(player * p, float dt);

#include "player.c"
#endif