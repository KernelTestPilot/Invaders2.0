#include "ShipEntity.h"


ShipEntity::ShipEntity(sf::Texture* Texture, std::string faction, std::string entity) {
	this->sprite.setTexture(*Texture);
	this->FactionType = faction;
	this->EntityType = entity;
	sprite.setPosition((GAME_WIDTH / 2), (GAME_HEIGHT / 2));
}
void ShipEntity::update(float deltaTime) {
	if (direction == "Up") {
		if (sprite.getPosition().y < 0)
		{
			//Utanför skärmen do nothing
		}
		else
		{
			sprite.move(0.f, -moveSpeedShip * deltaTime);
		}
	}
	else if (direction == "Down")
	{
		if (sprite.getPosition().y > GAME_HEIGHT - sprite.getGlobalBounds().height)
		{
			//Utanför skärmen do nothing
		}
		else
		{
			sprite.move(0.f, moveSpeedShip * deltaTime);
		}
	}
	else if (direction == "Left")
	{
		if (sprite.getPosition().x < 0)
		{
			//Utanför skärmen do nothing
		}
		else
		{
			sprite.move(-moveSpeedShip * deltaTime, 0.f);

		}
	}
	else if (direction == "Right")
	{
		if (sprite.getPosition().x > GAME_WIDTH - sprite.getGlobalBounds().width)
		{
			//Utanför skärmen do nothing
		}
		else
		{
			sprite.move(moveSpeedShip * deltaTime, 0.f);
		}
	}
}

void ShipEntity::onEvent(sf::Event* event) {

	 direction = "";

	 //For the movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		direction = "Up";
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		direction = "Down";
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		direction = "Right";
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		direction = "Left";
	}

	//for the shooting
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		fireBullets = true;
	}
	else {
		fireBullets = false;

	}

}