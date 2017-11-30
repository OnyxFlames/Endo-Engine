#pragma once

#include <map>
#include <memory>
#include <SFML/Graphics.hpp>

namespace Textures
{
	enum ID
	{
		Missing,
		Landscape,
		Player,
		Ally,
		Enemy,
		Missle,
	};
};


template <typename Resource, typename Identifier>
class ResourceManager
{
private:
	std::map<Identifier, std::unique_ptr<Resource>> mResourceMap;
public:
	ResourceManager();
	~ResourceManager();
	
	void load(Identifier id, const std::string& filename);
	template <typename Parameter>
	void load(Identifier id,
		const std::string & filename, const Parameter& param);

	Resource& get(Identifier id);
	const Resource& get(Identifier id) const;
};

typedef ResourceManager<sf::Texture, Textures::ID> TextureManager;

#include "ResourceManager.inl"