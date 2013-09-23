//////////////////////////////////////////////////////////////////////////
#include "AIE.h"
#include <string>
#include <cmath>
#include <time.h>
#include <assert.h>
#include <crtdbg.h>
#include <iostream>
#include "MovableObject.h"

const int SCREEN_X = 1280;
const int SCREEN_Y = 780;


const int BALL_W = 20;
const int BALL_H = 20;
const int PADDLE_W = 10;
const int PADDLE_H = 100;



int main( int argc, char* argv[] )
{	
	Initialise(SCREEN_X,SCREEN_Y,false);
	MovableObject Ball = {Vector2D(SCREEN_X/2,SCREEN_Y/2),Vector2D(1,0),BALL_W,BALL_H,-1};

	MovableObject PlayerOne = {Vector2D(100,SCREEN_Y/2),Vector2D(0,0),PADDLE_W,PADDLE_H,-1};
	MovableObject PlayerTwo = {Vector2D(SCREEN_X-100,SCREEN_Y/2),Vector2D(0,0),PADDLE_W,PADDLE_H,-1};
	

	initObject(PlayerTwo,"./images/paddle.png",SColour(255,0,0,255));
	initObject(PlayerOne,"./images/paddle.png",SColour(0,255,0,255));
	initObject(Ball,"./images/ball.png",SColour(255,255,255,255));

	

	
	do 
	{
		ClearScreen();
		deltaTime();
		playerInput(PlayerOne,PlayerTwo);
		
		updateObject(Ball);
		collisionCheck(Ball,PlayerOne);
		collisionCheck(Ball,PlayerTwo);
		updateObject(PlayerOne);
		updateObject(PlayerTwo);

		drawSprites();
	


	} while ( FrameworkUpdate() == false );
	
	Shutdown();

	return 0;
}

