#pragma once
#include "Entity.h"
class BulletEntity :
	public Entity
{
public:
	BulletEntity(sf::Texture* Texture, sf::Vector2f pos, std::string direction, std::string faction, std::string entity);

	virtual void update(float frametime) override;
	//virtual void shoot() override;
	bool IsRightBullet();
	bool IsLeftBullet();
	bool IsUpBullet();
	std::string direction;
private:

};

