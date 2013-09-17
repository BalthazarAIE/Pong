//////////////////////////////////////////////////////////////////////////////
//  Author: Justin Loudermilk
//	
//	Date: 09/17/2013
//
//	Brief: Movable Objects for Example Pong using AIE Static Framework
//
//////////////////////////////////////////////////////////////////////////////
#include "MovableObject.h"
#include "AIE.h"
#include <string>



const int SCREEN_X = 1280;
const int SCREEN_Y = 780;



int list[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
int index = 0;

//initalize objects max of 10
int initObject(MovableObject &obj,const char* path,SColour color)
{
	obj.sprite = CreateSprite(path,obj.width,obj.height,true,color);
	MoveSprite(obj.sprite,obj.position.x,obj.position.y);
	list[index] = obj.sprite;
	index++;
	return 1;
}
int updateObject(MovableObject &obj)
{
	testOnScreen(obj);
	moveObject(obj);
	MoveSprite(obj.sprite,obj.position.x,obj.position.y);
	
	return 1;
};
int drawSprites()
{
	for(int i = 0; i <= index;i++)
	{
		if(list[i] > -1)
			DrawSprite(list[i]);
	
	}
	return 1;
};
bool testOnScreen(MovableObject& obj){
	if(obj.position.x + (obj.width/2) >= SCREEN_X) {
		obj.position.x -= 1;
		obj.velocity.x *= -1;
		return true;
	}
	if(obj.position.x - (obj.width/2)  <= 0) {
		obj.position.x += 1;
		obj.velocity.x *= -1;
		return true;
	}
	if(obj.position.y + (obj.height/2)  >= SCREEN_Y) {
		obj.position.y -= 1;
		obj.velocity.y *= -1;
	}
	if(obj.position.y - (obj.height/2) <=  0) {
		obj.position.y += 1;
		obj.velocity.y *= -1;
	}
	return false;
}

void moveObject(MovableObject &obj)
{
	obj.position.x += obj.velocity.x;
	obj.position.y += obj.velocity.y;

}

bool collisionCheck(MovableObject &objA,MovableObject &objB)
{

	if((objA.position.x + (objA.width/2) <= objB.position.x + (objB.width/2)) && (objA.position.x - (objA.width/2) >= objB.position.x - (objB.width/2) ))
	{
		if((objA.position.y <= objB.position.y + (objB.height /2)) && (objA.position.y >= objB.position.y - (objB.height /2) ))
		{

			objA.velocity.x *= -1;
			return true;
		}
	
	
	}

return false;
}

void playerInput(MovableObject &playerOne,MovableObject &playerTwo)
{
	if(IsKeyDown('W'))
	{	
		playerOne.velocity.y = -1;

	}
	else if(IsKeyDown('S'))
	{
		playerOne.velocity.y = 1;
	}
	else
	{
		playerOne.velocity.y = 0;
	}

	if(IsKeyDown(KEY_UP))
	{
		playerTwo.velocity.y = -1;

	}else if(IsKeyDown(KEY_DOWN))
	{
		playerTwo.velocity.y = 1;
	}
	else
	{
		playerTwo.velocity.y = 0;
	}



}



