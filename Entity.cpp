#include "Entity.h"

Entity::Entity() {

}

std::string Entity::getEntity() {
	return EntityType;
}

std::string Entity::getFaction() {
	return FactionType;
}

sf::Vector2f Entity::getPosition() {
	return sprite.getPosition();
}



void Entity::draw(sf::RenderWindow* window) {
	// takes a memory adress and then dereferences it
	// window->draw(sprite); 
	(*window).draw(sprite);

}

void Entity::update(float frametime)
{
	// default behaviour 
	// do nothing
}

void Entity::onEvent(sf::Event* event) {
	// do nothing
 }