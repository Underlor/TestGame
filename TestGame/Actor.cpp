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

Actor::Actor(float x, float y, CollType Type, sf::Texture t)
{
	Pos->x = x, Pos->y = y;
	CollisionShape = new Collision(x, y, Type);
	SetTexture(t);
}

void Actor::SetTexture(sf::Texture t)
{
}

void Actor::Spawn()
{

}

bool Actor::Moving(int dx, int dy)
{
	if (true)
	{
		SetPos(GetPos()->x + dx, GetPos()->y + dy);
		return true;
	}
	else
	{
		return false;
	}
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
