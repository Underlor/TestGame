#pragma once
#include "Entity.h"
class Enemy : public Entity
{
public:
	Enemy(float ix, float iy) :Entity(ix, iy) {}
	Enemy(float ix, float iy, CollType CollisionType) :Entity(ix, iy, CollisionType) {}
	Enemy(float ix, float iy, CollType CollisionType, sf::Texture t) :Entity(ix, iy, CollisionType, t) {}

private:

};