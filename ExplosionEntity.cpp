#include "ExplosionEntity.h"
ExplosionEntity::ExplosionEntity(sf::Texture* Texture, sf::Vector2f pos, std::string entity) {
	this->sprite.setTexture(*Texture);
	this->EntityType = entity;
	this->myPos = pos;
	sprite.setPosition(myPos.x, myPos.y);
}


bool ExplosionEntity::collideHandle(Entity* collidedEntity){
	return false;
}

void ExplosionEntity::update(float frametime)
{

}


void ExplosionEntity::onEvent(sf::Event* event)
{

}