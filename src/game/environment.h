#ifndef ENV_H
#define ENV_H

typedef struct rectWall //rectangular wall
{
Vector2 a;
Vector2 b; //coordinates of the corners of the wall
} rectWall; 

void DebugWallDraw(rectWall * rw); //walls themselves are meant to be invisible
//instead, the massive map texture should provide insight to the environment, such as where the walls are.


#include "environment.c"
#endif