#pragma once

#include "SceneNode.hpp"

class SpriteNode : public SceneNode
{
private:
	sf::Sprite mSprite;
public:
	explicit SpriteNode(const sf::Texture& texture);
	SpriteNode(const sf::Texture& texture,
		const sf::IntRect& rect);
	~SpriteNode();
private:
	virtual void drawCurrent(sf::RenderTarget& target,
		sf::RenderStates states) const;
};

