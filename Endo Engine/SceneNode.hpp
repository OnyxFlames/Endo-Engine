#pragma once

#include <vector>
#include <memory>

#include <SFML/Graphics.hpp>

#include "Command.hpp"

struct Command;

typedef unsigned int CategoryType;


class SceneNode : public sf::Transformable, public sf::Drawable,
	private sf::NonCopyable
{
public:
	typedef std::unique_ptr<SceneNode> Ptr;
public:
	SceneNode();
	~SceneNode();

	void attachChild(Ptr child);
	Ptr detachChild(const SceneNode& node);
	void update(sf::Time dt);
	virtual CategoryType getCategory() const;
	void onCommand(const Command& command, sf::Time dt);
private:
	std::vector<Ptr> mChildren;
	SceneNode* mParent;
private:
	virtual void draw(sf::RenderTarget& target,
		sf::RenderStates states) const;
	virtual void drawCurrent(sf::RenderTarget& target,
		sf::RenderStates states) const;
	virtual void updateCurrent(sf::Time dt);
	void updateChildren(sf::Time dt);
	sf::Transform getWorldTransform() const;
	sf::Vector2f getWorldPosition() const;
};

