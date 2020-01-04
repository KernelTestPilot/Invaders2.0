#include "InvaderEntity.h"
InvaderEntity::InvaderEntity(sf::Texture* Texture, std::string faction, std::string entity,float Dir) {
	this->sprite.setTexture(*Texture);
	this->HPMax = rand() % 3 + 1;
	this->HP = this->HPMax;
	this->sprite.setPosition((rand() % int (GAME_WIDTH)), 0.f);
	this->moveSpeedY = rand() % 3 + 1;
	this->FactionType = faction;
	this->EntityType = entity;
	this->fireBullets = true;
	
this->	RanDir = Dir;

	if (RanDir == 1)
	{
		dir = true;
	}

	else
	{
		dir = false;
	}
}

void InvaderEntity::update(float deltaTime) {
	
	if (!dir)
	{
		if (sprite.getPosition().x < GAME_WIDTH - sprite.getGlobalBounds().width)
		{
			sprite.move(5.f, speed * deltaTime);
		}

		else
		{
			dir = true;

		}

	}

	if (dir)
	{
		if (sprite.getPosition().x > 0)
		{
			sprite.move(-5.f, speed * deltaTime);
		}

		else
		{
			dir = false;
		}
	}
}


