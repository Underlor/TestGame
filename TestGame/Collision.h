#pragma once
#include "MyTypes.h"
class Collision
{
public:
	Collision(float, float, CollType, int);
	Collision(float, float, int);
	~Collision();
	bool Collided(Coordinate);
	void SetType(CollType);
	int sizex;
	int sizey;
	Coordinate* CollisionCoord;
private:
	CollType Type;
	
	
private:

};
