#include "Game.hpp"

#include  <iostream>

Game::Game()
	:mWindow(sf::VideoMode(640, 480), "Endo Engine"),
	mTexture(),
	mPlayer(),
	mWorld(mWindow)
{
	if (!mTexture.loadFromFile("../resources/sprites/playerShip1_blue.png"))
	{

	}
	//mPlayer.setTexture(mTexture);
	//mPlayer.setPosition(100.f, 100.f);
}

void Game::run()
{
	const sf::Time TimePerFrame = sf::seconds(1.0f / 60.f);

	sf::Clock clock;
	sf::Time lastUpdate = sf::Time::Zero;
	while (mWindow.isOpen())
	{
		lastUpdate += clock.restart();
		while (lastUpdate > TimePerFrame)
		{
			lastUpdate -= TimePerFrame;
			processEvents();
			update(TimePerFrame);
		}
		render();
	}
}

Game::~Game()
{
}

void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
				mWindow.close();
			else
				handlePlayerInput(event.key.code, true);
			break;
		case sf::Event::KeyReleased:
			handlePlayerInput(event.key.code, false);
			break;
		case sf::Event::Closed:
			mWindow.close();
			break;
		}
	}
}

void Game::update(sf::Time delta)
{
	mWorld.update(delta);
}

void Game::render()
{
	mWindow.clear();
	mWorld.draw();
	
	mWindow.setView(mWindow.getDefaultView());
	mWindow.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::W)
		mIsMovingUp = isPressed;
	else if (key == sf::Keyboard::S)
		mIsMovingDown = isPressed;
	else if (key == sf::Keyboard::A)
		mIsMovingLeft = isPressed;
	else if (key == sf::Keyboard::D)
		mIsMovingRight = isPressed;
}


