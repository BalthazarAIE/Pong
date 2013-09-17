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
const int PADDLE_W = 20;
const int PADDLE_H = 100;



int main( int argc, char* argv[] )
{	
	Initialise(1280,780,false);
	MovableObject Ball = {150,100,1,1,BALL_W,BALL_H,-1};
	MovableObject PlayerOne ={100,100,0,0,PADDLE_W,PADDLE_H,-1};
	MovableObject PlayerTwo ={1100,100,0,0,PADDLE_W,PADDLE_H,-1};
	

	initObject(PlayerTwo,"./images/paddle.png",SColour(255,0,0,255));
	initObject(PlayerOne,"./images/paddle.png",SColour(0,255,0,255));
	initObject(Ball,"./images/ball.png",SColour(255,255,255,255));

	
	do 
	{
		ClearScreen();

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

