#ifndef MASTER_H
#define MASTER_H
#include <raylib.h>

typedef struct creature
{
Vector2 position;
Vector2 velocity;
Vector2 acceleration;
double direction;

float mass;

int health;
int maxhealth;
int maxspeed;
} creature;

void UpdateCreature(creature * c, float dt);
void DamageCreature(creature * c, int d, double dir, float knockback);

#include "player.h"
#include "../ineedit.h"
#include "environment.h"

#include "master.c"
#endif
