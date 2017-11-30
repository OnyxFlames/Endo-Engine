#pragma once

#include <SFML/Graphics.hpp>

#include "Entity.hpp"
#include "ResourceManager.hpp"

class Aircraft : public Entity
{
public:
	enum Type
	{
		Player,
		Ally,
		Enemy,
	};
	explicit Aircraft(Type type, const TextureManager& textures);

	virtual void drawCurrent(sf::RenderTarget& target,
		sf::RenderStates states) const;
	~Aircraft();
	virtual CategoryType getCategory() const;
private:
	Type mType;
	sf::Sprite mSprite;
};

