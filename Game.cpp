#include "Game.h"
Game::Game(){

	running = true;
}

void Game::deleteSprites() {
	for (auto i = 0; i < entityVec.size(); i++)
	{
		//delete om utanför skärm
		if (entityVec[i]->getPosition().y > GAME_HEIGHT + 200 || entityVec[i]->getPosition().y < -200 || entityVec[i]->getPosition().x > GAME_WIDTH + 200 || entityVec[i]->getPosition().x < -200) {
			entityVec.erase(entityVec.begin() + i);
		}
	}
}

void Game::quit()
{
	running = false;
}

void Game::CreateWindow() {
	if (window.isOpen())
	{
		window.close();
	}

	window.create(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT), GAME_TITLE, sf::Style::Titlebar | sf::Style::Close);
	window.setKeyRepeatEnabled(true);
	window.setFramerateLimit(GAME_FPS);

}

void Game::collisionHandler() {
	sf::Texture ExplosionTexture;
	ExplosionTexture.loadFromFile("Explosion.psd");
	for (size_t a = 0; a < entityVec.size(); a++){
		//Entity* Enemies = entityVec[a];
		for (size_t J = 0; J < entityVec.size(); J++) {
		//	Entity* Friendly = entityVec[J];


			if (entityVec[a]->getFaction() == "Friendly" && entityVec[J]->getFaction() == "Enemy") {
			
					if (entityVec[a]->sprite.getGlobalBounds().intersects(entityVec[J]->sprite.getGlobalBounds())) {
						Entity* explosion = new ExplosionEntity(&ExplosionTexture, entityVec[J]->getPosition(), "explosion");
						add(explosion);
						if (entityVec[a]->getEntity() == "Ship")
						{
							quit();
						}
						entityVec.erase(entityVec.begin() + J);
			
					
					}
				

			}

		}
	}
}




void Game::draw(sf::RenderWindow* window) {
	for (auto i = 0; i < entityVec.size(); i++)
	{
		entityVec[i]->draw(window);
	}

}

void Game::add(Entity* entity) {
	entityVec.push_back(entity);
}

void Game::update(float deltaTime) {
	for (auto i = 0; i < entityVec.size(); i++)
	{
		entityVec[i]->update(deltaTime);
	}
}


int Game::run() {

	CreateWindow();
	//Dahlbergs texture manager 3.0

	sf::Texture InvaderTexture;
	InvaderTexture.loadFromFile("Invader.psd");

	sf::Texture ExplosionTexture;
	ExplosionTexture.loadFromFile("Explosion.psd");

	sf::Texture BulletTexture;
	BulletTexture.loadFromFile("Bullet.psd");

	sf::Texture ShipTexture;
	ShipTexture.loadFromFile("Ship.psd");

	//Dahlbergs clock manager
	sf::Clock clock;
	sf::Clock ShootClockPlayer;
	sf::Clock ShootClockInvader;
	sf::Clock spawnClockInvader;
	sf::Time time;
	time = clock.getElapsedTime();

	

	//Here we do classes
	ShipEntity s(&ShipTexture, "Friendly", "Ship");
	Entity* ship = &s;
	add(ship);

	int testlevel = 250;
	while (running) {
		
		Event event;
		while (window.pollEvent(event)) {

			if (event.type == Event::Closed) {
				window.close();
			}
			//EVENTS
			ship->onEvent(&event);
		}
		window.clear();
		//player ship shooting
		timerPlayer += ShootClockPlayer.restart().asSeconds();
		if (ship->fireBullets) {

			if (timerPlayer > shootTimerPlayer) {
				Vector2f playerCenter;
				playerCenter = Vector2f(ship->getPosition().x +30,  ship->getPosition().y);
				Entity* bullet = new BulletEntity(&BulletTexture, playerCenter, "Left", "Friendly","FriendlyBullet");
				add(bullet);
				Entity* bullet2 = new BulletEntity(&BulletTexture, playerCenter, "Right", "Friendly", "FriendlyBullet");
				add(bullet2);
				Entity* bullet3 = new BulletEntity(&BulletTexture, playerCenter, "Up", "Friendly", "FriendlyBullet");
				add(bullet3);
				timerPlayer = 0.0f;
			}
		}
	
	
		//Enemy spawn logicx
		mSpawnTime += spawnClockInvader.restart().asSeconds();
		if (counter > 10)
		{
			invaderSpawnTimer = 1.0f;
		}

		if (counter > 40)
		{
			invaderSpawnTimer = 0.8f;
		}

		if (counter > 60)
		{
			invaderSpawnTimer = 0.5f;
		}

		if (counter > 300)
		{
			invaderSpawnTimer = 0.3f;
		}

		if (counter > 500)
		{
			invaderSpawnTimer = 0.1f;
		}

		if (invaderSpawnTimer < mSpawnTime){
			counter++;
			int dirSpeed = rand() % 2 + 1;
			Entity* invader = new InvaderEntity (&InvaderTexture, "Enemy", "Invader", dirSpeed);
			add(invader);
			mSpawnTime = 0.f;
		}

		// erase explosion entities continuously
		for (auto i = 0; i < entityVec.size(); i++)
		{
			if (entityVec[i]->getEntity() == "explosion")
			{
				entityVec.erase(entityVec.begin() + i);
			}
		}

		//Invader shooting
		timerInvader += ShootClockInvader.restart().asSeconds();
		if (timerInvader > shootTimerInvader)
		{
			for (auto i = 0; i < entityVec.size(); ++i)
			{
				if (entityVec[i]->getEntity() == "Invader")
				{
					if (entityVec[i]->fireBullets)
					{
						Vector2f InvaderCenter;
						InvaderCenter = Vector2f(entityVec[i]->getPosition().x + 30, entityVec[i]->getPosition().y +30);
						Entity* invaderBullet = new BulletEntity(&BulletTexture, InvaderCenter, "null", entityVec[i]->getFaction(), "EnemyBullet");
						add(invaderBullet);
						timerInvader = 0.0f;
					}
				}
			}

			timerInvader = 0.0f;
		}

		//Collide
		collisionHandler();


		//Detele sprites utanför skräm
		deleteSprites();
		window.clear(sf::Color::Black);
		update(clock.restart().asSeconds());
		//Draw here
		draw(&window);
		
		window.display();
	}
	return 0;
}