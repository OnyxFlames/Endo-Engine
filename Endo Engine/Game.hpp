#pragma once

#include <SFML/Graphics.hpp>

#include "World.hpp"

class Game
{
private:
	sf::RenderWindow mWindow;

	bool mIsMovingUp = false,
		mIsMovingDown = false,
		mIsMovingLeft = false,
		mIsMovingRight = false;

	sf::Texture mTexture;
	sf::Sprite mPlayer;

	World mWorld;
public:
	Game();
	~Game();
private:
	void processEvents();
	void update(sf::Time delta);
	void render();
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
public:
	void run();
};

