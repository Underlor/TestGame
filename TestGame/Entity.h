#pragma once
#include "Actor.h"
class Entity : private Actor
{
public:
	Entity(float ix, float iy, CollType CollisionType) :Actor(ix, iy, CollisionType) {}
	Entity(float ix, float iy) :Actor(ix, iy) {}
	~Entity();
private:

};
