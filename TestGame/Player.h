#pragma once
#include "Entity.h"
class Player : private Entity
{
public:
	Player(float ix, float iy, CollType CollisionType) :Entity(ix, iy, CollisionType) {}
	Player(float ix, float iy) :Entity(ix, iy) {}
	~Player();
private:

};