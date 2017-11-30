#pragma once

#include <array>

#include <SFML/Graphics.hpp>

#include "ResourceManager.hpp"
#include "SceneNode.hpp"
#include "Aircraft.hpp"

class World : private sf::NonCopyable
{
private:
	enum Layer
	{
		Background,
		Air,

		LayerCount,
	};
	sf::RenderWindow& mWindow;
	sf::View mWorldView;
	TextureManager mTextures;
	SceneNode mSceneGraph;
	std::array<SceneNode*, LayerCount> mSceneLayers;

	sf::FloatRect mWorldBounds;
	sf::Vector2f mSpawnPosition;
	float mScrollSpeed;
	Aircraft* mPlayerAircraft;
public:
	explicit World(sf::RenderWindow& window);
	void update(sf::Time dt);
	void draw();
	~World();
private:
	void loadTextures();
	void buildScene();
};

