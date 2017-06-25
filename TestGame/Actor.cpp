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

void Actor::Spawn()
{

}

void Actor::SetPos(float x, float y)
{
	this->Pos->x = x;
	this->Pos->y = y;
}

Coordinate *Actor::GetPos()
{
	return Pos;
}

void Actor::SetVisible(bool state)
{
	Visible = state;
}

bool Actor::GetVisible()
{
	return Visible;
}

Actor::~Actor()
{
	delete CollisionShape;
	delete Pos;
}
