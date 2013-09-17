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

struct Vector2D
{
	float x;
	float y;
};

struct MovableObject
{
	Vector2D position;
	Vector2D velocity;
	int width;
	int height;
	int sprite;
};

int initObject(MovableObject &obj,const char* path,SColour color);
int updateObject(MovableObject& obj);
int drawSprites();
bool testOnScreen(MovableObject& obj);
void moveObject(MovableObject &obj);
bool collisionCheck(MovableObject &objA,MovableObject &objB);
void playerInput(MovableObject &playerOne,MovableObject &playerTwo);

#endif