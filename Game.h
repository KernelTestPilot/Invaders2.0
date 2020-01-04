#pragma once

#include "SFML/Graphics.hpp"
#include "Entity.h"
#include "ShipEntity.h"
#include "InvaderEntity.h"
#include "BulletEntity.h"
#include "ExplosionEntity.h"
#include "ExplosionEntity.h"
#include "GameSettings.h"
#include <vector>

using namespace sf;
using namespace std;

class Game
{	public:
	//General game functions
	Game();
	void add(Entity* entity);
	int run();
	void CreateWindow();
	void draw(sf::RenderWindow* window);
	void update(float deltaTime);

	void deleteSprites();

	void collisionHandler();
	void quit();

	int counter = 0;


private:
	sf::RenderWindow window;
	std::vector<Entity*> entityVec;

	//Game settings
	float invaderSpawnTimer = 2.0f;
	float mSpawnTime = 0.0f;

	float timerPlayer = 0.0f;
	float shootTimerPlayer = 0.3f;

	float timerInvader = 0.0f;
	float shootTimerInvader = 0.6f;

	bool running;

};

