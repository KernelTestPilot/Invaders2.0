#include "BulletEntity.h"
BulletEntity::BulletEntity(sf::Texture* Texture, sf::Vector2f pos, std::string direction, std::string faction, std::string entity){
	this->sprite.setPosition(pos);
	this->sprite.setTexture(*Texture);
	this->direction = direction;
	this->FactionType = faction;
	this->EntityType = entity;
}


bool BulletEntity::IsRightBullet() {
	return direction == "Right";
}

bool BulletEntity::IsLeftBullet() {
	return direction == "Left";
}


bool BulletEntity::IsUpBullet() {
	return direction == "Up";
}

void BulletEntity::update(float frametime) {
		if (FactionType =="Friendly") {
			if (IsRightBullet()) {
				sprite.move(10.f, -1000.f * frametime);
			}
			if (IsLeftBullet()) {
				sprite.move(-10.f, -1000.f * frametime);
			}
			if (IsUpBullet()) {
				sprite.move(0.f, -1000.f * frametime);
			}
		}
		else if(FactionType == "Enemy") {
			sprite.move(0.f, 400.f * frametime);
		}
		
	
}