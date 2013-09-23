//////////////////////////////////////////////////////////////////////////////
//  Author: Justin Loudermilk
//	
//	Date: 09/17/2013
//
//	Brief: Movable Objects for Example Pong using AIE Static Framework
//
//////////////////////////////////////////////////////////////////////////////
#ifndef _MOVABLEOBJECT_H_
#define _MOVABLEOBJECT_H_
#include "AIE.h"
#include <time.h>

struct Vector2D
{

	float x;
	float y;

	Vector2D()
	{
		x = 0;
		y = 0;
	}
	Vector2D(float a,float b)
	{
		x = a;
		y = b;
	}
};

struct BoundingBox
{

	Vector2D topLeft;
	Vector2D topRight;
	Vector2D bottomRight;
	Vector2D bottomLeft;

	BoundingBox()
	{
	topLeft = Vector2D(0,0);
	topRight  = Vector2D(0,0);
	bottomRight   = Vector2D(0,0);
	bottomLeft  = Vector2D(0,0);
	}
};

struct MovableObject
{
	Vector2D position;
	Vector2D velocity;
	int width;
	int height;
	int sprite;
	BoundingBox box;


};

int initObject(MovableObject &obj,const char* path,SColour color);
int updateObject(MovableObject& obj);
int drawSprites();
bool testOnScreen(MovableObject& obj);
void moveObject(MovableObject &obj);
bool collisionCheck(MovableObject &objA,MovableObject &objB);
void playerInput(MovableObject &playerOne,MovableObject &playerTwo);
void deltaTime();
void setBoundingBox(MovableObject &obj);

bool pointInBox(Vector2D point, BoundingBox box);

#endif