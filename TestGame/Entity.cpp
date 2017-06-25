#include "Entity.h"

void Entity::Damage(int count)
{
	if (Health - count <= 0)
	{
		Die("Кончились жизни");
	}
	else
	{
		Health -= count;
	}
}

void Entity::Die(AStr::Str)
{
	
}

void Entity::SetOnGround(bool state)
{
	OnGround = state;
}


int Entity::GetHealth()
{
	return Health;
}

void Entity::SetHealth(int count)
{
	Health = count;
}

void Entity::SetIsDead(bool state)
{
	isDead = state;
}

bool Entity::IsDead()
{
	return isDead;
}

Entity::~Entity()
{

}
