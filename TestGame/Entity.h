#pragma once
#include "Actor.h"
#include "../../AString.h"
class Entity : public Actor
{
public:
	Entity(float ix, float iy) :Actor(ix, iy) {}
	Entity(float ix, float iy, CollType CollisionType) :Actor(ix, iy, CollisionType) {}
	Entity(float ix, float iy, CollType CollisionType, sf::Texture t) :Actor(ix, iy, CollisionType, t) {}
	void Damage(int);
	void Die(AStr::Str);
	void SetOnGround(bool);
	int GetHealth();
	void SetHealth(int);
	void SetIsDead(bool);
	bool IsDead();
	~Entity();
private:
	int Health;
	bool OnGround;
	bool isDead;
};
