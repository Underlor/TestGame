#include "Collision.h"
Collision::Collision(float x, float y, CollType iType = BlockALL, int s = 32)
{
	CollisionCoord = new Coordinate(x, y);
	Type = iType;
	sizex = sizey = s;
}

Collision::Collision(float x, float y, int s = 32)
{
	sizex = sizey = s;
	CollisionCoord = new Coordinate(x, y);
	Type = BlockALL;
}

Collision::~Collision() 
{
	
}

bool Collision::Collided(Coordinate ObjC)
{
	
	return false;
}

void Collision::SetType(CollType TypeOfCollision)
{
	Type = TypeOfCollision;
}
