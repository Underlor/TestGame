#pragma once
#include "Collision.h"
#include <SFML/Graphics.hpp>
class Actor
{
public:
	Collision* CollisionShape;
	Actor(float, float);
	Actor(float, float, CollType);
	void Spawn();
	void SetPos(float, float);
	Coordinate *GetPos();
	void SetVisible(bool);
	bool GetVisible();
	void Destroy();
	~Actor();
private:
	Coordinate *Pos;
	bool Visible;
	sf::FloatRect *Rect;
};
