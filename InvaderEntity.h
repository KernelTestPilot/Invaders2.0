#pragma once
#include "Entity.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <stdlib.h> 
using namespace std;

class InvaderEntity :
	public Entity
{
public:
	InvaderEntity(sf::Texture* Texture, std::string faction, std::string entity, float Dir);
	virtual void update(float deltaTime) override;
private:
	int HP;
	int HPMax;
	int shootTimer = rand() % 3 + 1;
	float speed = 70.0f;
	int moveSpeedY = -40;
	int left = -4;
	int right = 4;
	int RanDir;

	bool dir = false;

};

