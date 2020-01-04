#pragma once
#include "Entity.h"
#include <iostream>
using namespace std;

class ShipEntity :
	public Entity
{
	public:
	ShipEntity(sf::Texture* Texture, std::string faction, std::string entity);
	virtual void update(float frametime) override;
	virtual void onEvent(sf::Event* event) override;
private:
	std::string direction;
	float moveSpeedShip = 500.0f;

};

