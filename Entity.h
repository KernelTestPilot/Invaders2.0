#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#include <vector>
#include "GameSettings.h"

class Entity
{
public:
	Entity();
	//return 
	std::string getEntity();
	std::string getFaction();
	sf::Vector2f getPosition();

	//poly 
	virtual void update(float deltaTime);
	virtual void onEvent(sf::Event* event);
	
	void draw(sf::RenderWindow* window);

	//Declarations of stuff
	sf::Sprite sprite;
	bool fireBullets = false;
private:
	
protected:
	std::string EntityType;
	std::string FactionType;
};

