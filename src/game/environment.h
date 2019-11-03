#ifndef ENV_H
#define ENV_H

typedef struct rectWall //rectangular wall
{
Vector2 a;
Vector2 b; //coordinates of the corners of the wall
} rectWall; 

typedef struct wallLine
{
Vector2 a;
Vector2 b; //coordinates of the endpoint of the line
} wallLine;

typedef struct lineEq //values for the equation of a line, taking the form y = mx + b
{
float m;
float b;
float x1;
float x2; //domain for the line equation
} lineEq;

void DebugWallDraw(rectWall * rw); //walls themselves are meant to be invisible

void DebugWallLineDraw(wallLine * rw); //wall lines themselves are meant to be invisible
//instead, the massive map texture should provide insight to the environment, such as where the walls are.

lineEq WallLineToLineEq(wallLine * lw);

int CircleLineIntersectTest(Vector2 cpos, float crad, lineEq le);


#include "environment.c"
#endif