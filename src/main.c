#define MATH_PI 3.1415926535897932384626433
#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <math.h>
#include "game/master.h"
#include "ineedit.h"
#include <raylib.h>

int main()
{

  printf("Hello world!\n");
 
  const int screenWidth = 800;
  const int screenHeight = 600;
  InitWindow(screenWidth, screenHeight, "BootZ");
  //SetTargetFPS(144);
  
  player masterson;
  masterson.being.position = (Vector2){screenWidth/2, screenHeight/2};
  masterson.being.acceleration = (Vector2){0, 0};
  masterson.being.velocity = (Vector2){0, 0};
  masterson.being.direction = 0.0;
  masterson.being.health = 25;
  masterson.being.maxhealth = 25;
  masterson.being.maxspeed = 177;
  masterson.being.direction = 0;
  
  masterson.input.x = 0;
  masterson.input.y = 0;
  masterson.input.shoot = 0;
  masterson.input.sprint = 0;
  masterson.input.reload = 0;
  
  masterson.accelerationSpeed = 850;
  masterson.kills = 0;
  masterson.score = 0;
  
  while(!WindowShouldClose())
  {
    float deltaTime = GetFrameTime();
    //update inputs
    if(IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)){printf("Moving down ... "); masterson.input.y = 1;}
    else if(IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)){masterson.input.y = -1;}
    else{masterson.input.y = 0;}
    
    if(IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)){masterson.input.x = -1;}
    else if(IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)){masterson.input.x = 1;}
    else{masterson.input.x = 0;}

    
    UpdatePlayer(&masterson, deltaTime);
    int textSize = (screenWidth * screenHeight)/(10*(screenWidth+screenHeight));
    
    BeginDrawing();
      //background
      ClearBackground(RAYWHITE);
      
      
      DrawText("Welcome to BootZ.", 20, 20, textSize, LIGHTGRAY);
      
      char tempstr[36];
      sprintf(tempstr, "FPS: %d", GetFPS());
      
      
      DrawText(tempstr, 20, 20 + textSize, textSize, LIGHTGRAY);
      
      //masterson
      DrawPlayer(&masterson);
    EndDrawing();
    printf("Player position is %f, %f\n", masterson.being.position.x, masterson.being.position.y);
    printf("Player velocity is %f, %f\n", masterson.being.velocity.x, masterson.being.velocity.y);
    printf("Player acceleration is %f, %f\n", masterson.being.acceleration.x, masterson.being.acceleration.y);
  }
  
  CloseWindow();
  
  return 0;
}
