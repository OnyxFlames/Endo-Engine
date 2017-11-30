#pragma once

#include <cassert>
#include <exception>

template <typename Resource, typename Identifier>
ResourceManager<Resource, Identifier>::ResourceManager()
{
}
template <typename Resource, typename Identifier>
ResourceManager<Resource, Identifier>::~ResourceManager()
{
}
template <typename Resource, typename Identifier>
void ResourceManager<Resource, Identifier>::load(Identifier id, const std::string& filename)
{
	std::unique_ptr<Resource> resource = std::make_unique<Resource>();
	if (!resource->loadFromFile(filename))
		throw std::runtime_error("ResourceManager::load - Failed to load " + filename);

	auto inserted = mResourceMap.insert(std::make_pair(id, std::move(resource)));

	assert(inserted.second);
}
template <typename Resource, typename Identifier>
template <typename Parameter>
void ResourceManager<Resource, Identifier>::load(Identifier id,
	const std::string& filename, const Parameter& param)
{
	std::unique_ptr<Resource> resource = std::make_unique<Resource>();
	if (!resource->loadFromFile(filename, param))
		throw std::runtime_error("ResourceManager::load - Failed to load " + filename);

	auto inserted = mResourceMap.insert(std::make_pair(id, std::move(resource)));

	assert(inserted.second);
}
template<typename Resource, typename Identifier>
Resource& ResourceManager<Resource, Identifier>::get(Identifier id)
{
	auto found = mResourceMap.find(id);
	return *found->second;
}
template<typename Resource, typename Identifier>
const Resource& ResourceManager<Resource, Identifier>::get(Identifier id) const
{
	auto found = mResourceMap.find(id);
	return *found->second;
}