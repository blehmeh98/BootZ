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
    //Resolution method 1: jank as fuck
    //just stop the player when he or she hits something
    //feels shitty to play with in the first place
    
    /*p->being.velocity = (Vector2){0, 0};
    p->being.acceleration = (Vector2){0, 0};*/
    
    //Resolution method 2: a little jank, but way better
    //Test the axises for collision and stop each one individually
    //Mostly works, still jank in some ways and I got the player stuck one time in a wall
    
    /*player nextFramePlayerX = *p;
    nextFramePlayerX.being.velocity.y = 0;
    UpdateCreature(&nextFramePlayerX.being, dt);
    if (PlayerCollideWithLines(&nextFramePlayerX, wl) > 0)
    {
      p->being.velocity.x = 0;
      p->being.acceleration.x = 0;
    }
    
    player nextFramePlayerY = *p;
    nextFramePlayerY.being.velocity.x = 0;
    UpdateCreature(&nextFramePlayerY.being, dt);
    if (PlayerCollideWithLines(&nextFramePlayerY, wl) > 0)
    {
      p->being.velocity.y = 0;
      p->being.acceleration.y = 0;
    }*/
    
    //Resolution method 3: impulse application based on collision angle
    //janky in it's own way, but feels great when it works
    //Making it smoother is mainly about tweaking the values and the formula just a little bit until it feels right
    //The programming itself is good and the theory is reasonably solid for a game of this scope, the math itself and the formula just needs more fine tuning
    //As of this alpha, collision with walls is bumpy, and the bumpiness of running along a wall is unpredictable and sporadic
    //But the player cannot go through walls, and it still feels pretty nice to control, at least for now
    //More fine tuning incoming a while later
    
    Vector2 IntersectPos = GetCircleLineIntPos(nextFramePlayer.being.position, 25, WallLineToLineEq(wl));
    float nfpbx = nextFramePlayer.being.position.x;
    float nfpby = nextFramePlayer.being.position.y;
    float intDist = sqrt((nfpbx - IntersectPos.x)*(nfpbx - IntersectPos.x) + (nfpby - IntersectPos.y)*(nfpby - IntersectPos.y));
    float distRadRatio = 25.00/intDist;
    float distSlope = (nfpby - IntersectPos.y)/(nfpbx - IntersectPos.x);
    
    Vector2 AccAdd = (Vector2){intDist * cos(atan(distSlope)) * 100000 * distRadRatio,intDist * sin(atan(distSlope)) * distRadRatio * 1000000};
    
    if (p->being.position.x > IntersectPos.x){p->being.acceleration.x += AccAdd.x * dt;}
    if (p->being.position.x < IntersectPos.x){p->being.acceleration.x -= AccAdd.x * dt;}
    if (p->being.position.y < IntersectPos.y){p->being.acceleration.y += AccAdd.y * dt;}
    if (p->being.position.y > IntersectPos.y){p->being.acceleration.y -= AccAdd.y * dt;}
  }
  
  UpdateCreature(&p->being, dt);
}

void DrawPlayer(player * p)
{
  DrawCircle(p->being.position.x, p->being.position.y, 25, ORANGE);
  DrawLineV(p->being.position, (Vector2){p->being.position.x + 50 * sin(p->being.direction), p->being.position.y + 50 * cos(p->being.direction)}, DARKGRAY);
}
