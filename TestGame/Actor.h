#pragma once
#include "Collision.h"
#include <SFML/Graphics.hpp>
class Actor
{
public:
	Collision* CollisionShape;
	Actor(float, float);
	Actor(float, float, CollType);
	Coordinate *GetPos();
	~Actor();
private:
	Coordinate *Pos;
	sf::FloatRect *Rect;
};
