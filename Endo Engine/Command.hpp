#pragma once

#include <functional>

#include <SFML/Graphics.hpp>

#include "SceneNode.hpp"

class SceneNode;

namespace Category
{
	enum Type
	{
		None	= 0,
		Scene	= 1 << 0,
		Player	= 1 << 1,
		Ally	= 1 << 2,
		Enemy	= 1 << 3,
	};
}

typedef unsigned int CategoryType;

struct Command
{
	std::function<void(SceneNode&, sf::Time)> action;
	CategoryType category;
};