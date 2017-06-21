#include "Actor.h"

Actor::Actor(float x, float y)
{
	Pos->x = x, Pos->y = y;
	CollisionShape = new Collision(x,y,BlockALL);
}
Actor::Actor(float x, float y, CollType Type)
{
	Pos->x = x, Pos->y = y;
	CollisionShape = new Collision(x, y, Type);
}

Coordinate *Actor::GetPos()
{
	return Pos;
}

Actor::~Actor()
{
	delete CollisionShape;
	delete Pos;
}
