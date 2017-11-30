#include "Aircraft.hpp"


Textures::ID toTextureID(Aircraft::Type type)
{
	switch (type)
	{
	case Aircraft::Player:
		return Textures::Player;
	case Aircraft::Enemy:
		return Textures::Enemy;
	case Aircraft::Ally:
		return Textures::Ally;
	default:
		return Textures::Missing;
	}
}

Aircraft::Aircraft(Type type, const TextureManager& textures)
	: mType(type), mSprite(textures.get(toTextureID(type)))
{
	sf::FloatRect bounds = mSprite.getLocalBounds();
	mSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void Aircraft::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}

Aircraft::~Aircraft()
{
}

CategoryType Aircraft::getCategory() const
{
	switch (mType)
	{
	case Player:
		return Category::Player;
	case Ally:
		return Category::Ally;
	case Enemy:
		return Category::Enemy;
	default: return Category::None;
	}
}
