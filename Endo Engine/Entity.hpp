#pragma once

#include <SFML/Graphics.hpp>

#include "SceneNode.hpp"

class Entity : public SceneNode
{
private:
	sf::Vector2f mVelocity;
public:
	Entity();
	~Entity();
	void setVelocity(sf::Vector2f velocity);
	void setVelocity(float vx, float vy);
	sf::Vector2f getVelocity() const;
private:
	virtual void updateCurrent(sf::Time dt);
};

