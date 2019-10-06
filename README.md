# BootZ
An open-source, top-down (hopefully multiplayer) 2D zombie shooter programmed in C. Currently in development.

## Conception
I know that the market is saturated chock full of zombie games right now. But, I noticed two things:

1. There's not a lot of open-source or libre-software zombie games out there right now. There's only one I actually know about, two if you count OpenRA with the option to spawn zombies into a map, but that's a stretch since the zombies are more of a novelty feature than a selling point of the game.
2. Most zombie games in general depict a post-apocalypse rather than the scenario I'm trying to paint. It's always depicted as some game where society's fallen and you have to use 15 pounds of ductape combined with sticks and rocks in order to craft an AR-15, and then you have to scavenge abandoned building after abandoned building to find canned beans and ingredients for a potato salad and you have to build a base to hunker down for the night and you have to rebuild humanity or something. Games like this can be fun, but I'm not interested in making a game like this since there's already so many. 

I was watching Shaun Of The Dead the other day when I saw the scene where the military arrives to save Shaun and Liz. They rolled up, hopped out of truck, lined up, and fired, all with the dramatic music playing. I always thought this sequence was awesome, and I realized recently that there's no game that adequately captures this feeling for me, at least as far as zombie games go. The closest would be Killing Floor, but while that game can feel like a badass zombie military operation, that game still errs on the side of survival and holding out in one location. I want to create a game with the feel of entering an area to clear out the zombies, rather than trying to survive. I don't want the zombies spawned in over time, I want all the zombies to already be alive and spawned at the beginning of each mission, with the player's objective to clear out the area and kill all of the zombies with not just a squad, but at least a small army of other soliders, kicking in doors, covering eachother's six, sprinting down hallways, maybe rescuing civillians (with AI soliders doing the boring "escort mission" part of the ordeal for you so that you can focus on more zombie killing, since I know that no one likes escort missions), etc. 

I don't want to portray a world after it all hits the fan. I want to portray a world where it's hitting the fan and you're taking cover and grabbing a mop and bucket before the smell drives everyone out of the room.

## Current features
Nothing. Like, I have a prototype of an orange circle on a white background that you can move with the arrow keys. 

## Planned features
### Alpha 1
- One weapon for the player only, the standard combat rifle.
- A small map, but with a scrolling screen that follows the player
- Basic environmental collision
- 50 zombies, give or take
- A basic vision mechanic that prevents you from seeing around corners.
- Crude graphics
- Punchy feeling gameplay, a focus on player agility and firepower, but not both at the same time (You have to stay still or walk slowly to shoot accurately)
- A basic aiming mechanic; pointing your mouse in the direction of the zombie will connect shots that vary in damage from some to more, but putting your mouse directly on top of the zombie and shooting slowly will guarantee a "precision shot" that deals enough damage for a headshot, which one-hit kills zombies. You will have to fire no more than a burst at a time for this to work, though. You can't just spray down a whole room of zombies in fully-automatic fire and expect every shot to be a precision shot because you put your mouse on top of them.

### Alpha 1.1
- A multiplayer server and client for Alpha 1
- Multiple players can hunt zombies together
- Collision between players
- Those dead will be able to respawn instantly, at least for now

### Alpha 1.2
- A more robust custom map system, made up of two elements: A massive texture representing the map, and a data file with the locations of all the walls
- A working door system. Doors will block vision. Opening a door won't alert zombies in neighboring rooms but will alert zombies in the room, and it takes a second or so after opening the door before you can deliver and accurate shot again. Kicking a door will alert all the zombies in the building, but will allow you to be ready to fire sooner, will look cooler, and, if there's zombies up against the door, can knock them over to make your life easier.

### Future updates
- Multiple weapons: A shotgun that stumbles, stuns, and pushes back entire groups of zombies with one shot, dealing massive damage with each shot but having a clunky reload, and an SMG, which can fire precision bursts as opposed to the rifle that has to tap-fire to get precision shots, and has a faster reload, but does less damage with shots that aren't precise, and may have trouble with stronger zombies or zombies wearing armor. Handles easier in close environments, faster to grab after opening a door. To compensate, the Rifle will be able to shoot through two zombies at a time with a well-aimed shot, will have way more penetration, etc.
- Perhaps the ability to shoot through certain types of walls, and thin walls, and doors (maybe even shoot doors to shreds, or blow them off to pieces with a shotgun)
- Somewhat realistic textures (erring more on the creepy side), perhaps from actual pictures of things, for the environment.
- Basic playergraphics. Animated, but not too well, unless I get help on this project.
- Up to at least 64 players to a single server, and maybe even hundreds of thousands of zombies in a level, tons of doors to kick, rooms to explore, streets, etc. This would be very difficult to network properly, but if I do it right, it would be awesome.
- The client should be able to run on my 2009 Macbook Pro. I'll make a pass for my 2006 black Macbook, since it's in disrepair and may not support Raylib at all depending on what version of OpenGL Raylib has baked in.
- Support for Windows, Mac, and Linux. Linux and Mac support will take priority because these are the platforms I develop on, but I'll compile for Windows when I get the chance and release a Windows build.

## Dependencies
- Raylib
- Enet, in the future
- Standard math and string libraries for C

## "I'm so excited that I want to play this game immediately!"
Come back in maybe a year. It's not done yet. It may not be done in a year, although it'll certainly be playable by then
