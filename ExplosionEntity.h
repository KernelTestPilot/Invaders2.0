#pragma once
#include "Entity.h"
#include <vector>
 
class ExplosionEntity :
	public Entity
{
public:
	ExplosionEntity(sf::Texture* Texture, sf::Vector2f pos, std::string entity);
	virtual void update(float frametime) override;
	virtual void onEvent(sf::Event* event) override;
	bool collideHandle(Entity* collidedEntity);
private:
	sf::Vector2f myPos;
};

