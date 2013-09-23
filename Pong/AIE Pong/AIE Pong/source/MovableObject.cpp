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
const float SPEED = 1000;



int list[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
int index = 0;

float fDeltaTime = 0;



//initalize objects max of 10
int initObject(MovableObject &obj,const char* path,SColour color)
{
	setBoundingBox(obj);
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
	setBoundingBox(obj);


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

	obj.position.x += obj.velocity.x * fDeltaTime * SPEED;
	obj.position.y += obj.velocity.y * fDeltaTime * SPEED;

}

bool collisionCheck(MovableObject &objA,MovableObject &objB)
{
	//old way of doing it

	float xMinA =objA.position.x - (objA.width/2);
	float xMaxA =objA.position.x + (objA.width/2);

	float xMinB =objB.position.x - (objB.width/2);
	float xMaxB =objB.position.x + (objB.width/2);

	float yMinA =objA.position.y - (objA.height/2);
	float yMaxA =objA.position.y + (objA.height/2);

	float yMinB =objB.position.y - (objB.height/2);
	float yMaxB =objB.position.y + (objB.height/2);



	if((xMaxA <= xMaxB && xMinA >= xMinB ))
	{
		if((yMaxA <= yMaxB && yMinA >= yMinB ))
		{

			objA.velocity.x *= -1;
			return true;
		}
	
	
	}

	
	//instead make a bounding box and test 4 points
/*	float xPoint = objA.box.topLeft.x;
	float yPoint = objA.box.topLeft.y;
	
	if(xPoint >= objB.position.x - (objB.width/2) && xPoint <= objB.position.x + (objB.width/2))
	{
		if(yPoint>= objB.position.y - (objB.height/2) && yPoint <= objB.position.y + (objB.height/2))
		{
			objA.velocity.x *= -1;
			return true;
			
		}
	
	
	}	
	
	xPoint = objA.box.topRight.x;
	yPoint = objA.box.topRight.y;
	
	if(xPoint >= objB.position.x - (objB.width/2) && xPoint <= objB.position.x + (objB.width/2))
	{
		if(yPoint>= objB.position.y - (objB.height/2) && yPoint <= objB.position.y + (objB.height/2))
		{
			objA.velocity.x *= -1;
			return true;
		}
	}

	xPoint = objA.box.bottomLeft.x;
	yPoint = objA.box.bottomLeft.y;
	
	if(xPoint >= objB.position.x - (objB.width/2) && xPoint <= objB.position.x + (objB.width/2))
	{
		if(yPoint>= objB.position.y - (objB.height/2) && yPoint <= objB.position.y + (objB.height/2))
		{
			objA.velocity.x *= -1;
			return true;
		}
	}

	xPoint = objA.box.bottomRight.x;
	yPoint = objA.box.bottomRight.y;
	
	if(xPoint >= objB.position.x - (objB.width/2) && xPoint <= objB.position.x + (objB.width/2))
	{
		if(yPoint>= objB.position.y - (objB.height/2) && yPoint <= objB.position.y + (objB.height/2))
		{
			objA.velocity.x *= -1;
			return true;
		}
	}
	*//*
	if(pointInBox(objA.box.topLeft,objB.box)
		||pointInBox(objA.box.topRight,objB.box)
		||pointInBox(objA.box.bottomLeft,objB.box)
		||pointInBox(objA.box.bottomRight,objB.box))
	{
		objA.velocity.x *= -1;
		return true;
		
	}


	*/
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
void deltaTime()
{
	fDeltaTime = GetDeltaTime();

}

void setBoundingBox(MovableObject &obj)
{
	obj.box.topLeft = Vector2D((obj.position.x - obj.width/2) , (obj.position.y - obj.height/2));
	obj.box.topRight = Vector2D((obj.position.x + obj.width/2) , (obj.position.y - obj.height/2));
	obj.box.bottomLeft = Vector2D((obj.position.x - obj.width/2) , (obj.position.y + obj.height/2));
	obj.box.bottomRight = Vector2D((obj.position.x + obj.width/2) , (obj.position.y + obj.height/2));
	

}
bool pointInBox(Vector2D point, BoundingBox box)
{
	
	if(point.x >= box.topLeft.x && point.x <= box.topRight.x)
	{
		if(point.y>= box.topLeft.y && point.y <= box.bottomLeft.y)
		{
			return true;
		}
	}
	return false;
}


