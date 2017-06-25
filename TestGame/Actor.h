#pragma once
#include "Collision.h"
#include <SFML/Graphics.hpp>
class Actor
{
public:
	Collision* CollisionShape;
	Actor(float, float);
	Actor(float, float, CollType);
	Actor(float, float, CollType, sf::Texture);
	void SetTexture(sf::Texture);
	void Spawn();
	bool Moving(int, int);
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
	sf::Sprite *sprite;
};
