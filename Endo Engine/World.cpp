#include "World.hpp"

#include "SpriteNode.hpp"

World::World(sf::RenderWindow& window)
	: mWindow(window), mWorldView(window.getDefaultView()),
	mWorldBounds(0.f, 0.f, mWorldView.getSize().x, 2000.f),
	mSpawnPosition(mWorldView.getSize().x / 2.f, mWorldBounds.height - mWorldView.getSize().y),
	mPlayerAircraft(nullptr)
{
	loadTextures();
	buildScene();

	mWorldView.setCenter(mSpawnPosition);
}

void World::update(sf::Time dt)
{
	mWorldView.move(0.f, mScrollSpeed * dt.asSeconds());

	sf::Vector2f position = mPlayerAircraft->getPosition();
	sf::Vector2f velocity = mPlayerAircraft->getVelocity();

	if (position.x <= mWorldBounds.left + 150
		|| position.x >= mWorldBounds.left + mWorldBounds.width - 150)
	{
		velocity.x = -velocity.x;
		mPlayerAircraft->setVelocity(velocity);
	}

	mSceneGraph.update(dt);
}

void World::draw()
{
	mWindow.setView(mWorldView);
	mWindow.draw(mSceneGraph);
}

World::~World()
{
}

void World::loadTextures()
{
	printf("World: loading textures\n");
	mTextures.load(Textures::Player, "../resources/Sprites/playerShip1_blue.png");
	mTextures.load(Textures::Ally, "../resources/Sprites/playerShip1_green.png");
	mTextures.load(Textures::Enemy, "../resources/Sprites/enemyBlue1.png");
	mTextures.load(Textures::Landscape, "../resources/textures/blue.png");
}

void World::buildScene()
{
	printf("World: building scene");
	for (std::size_t i = 0; i < LayerCount; ++i)
	{
		SceneNode::Ptr layer(new SceneNode());
		mSceneLayers[i] = layer.get();

		mSceneGraph.attachChild(std::move(layer));
	}

	sf::Texture& texture = mTextures.get(Textures::Landscape);
	sf::IntRect textureRect(mWorldBounds);
	texture.setRepeated(true);
	std::unique_ptr<SpriteNode> backgroundSprite(
		new SpriteNode(texture, textureRect));
	backgroundSprite->setPosition(
		mWorldBounds.left,
		mWorldBounds.top);
	mSceneLayers[Background]->attachChild(std::move(backgroundSprite));

	std::unique_ptr<Aircraft> leader(
		new Aircraft(Aircraft::Player, mTextures));
	mPlayerAircraft = leader.get();
	mPlayerAircraft->setPosition(mSpawnPosition);
	mPlayerAircraft->setVelocity(40.f, mScrollSpeed);
	mSceneLayers[Air]->attachChild(std::move(leader));

	std::unique_ptr<Aircraft> leftEscort(
		new Aircraft(Aircraft::Ally, mTextures));
	leftEscort->setPosition(-80.f, 50.f);
	mPlayerAircraft->attachChild(std::move(leftEscort));

	std::unique_ptr<Aircraft> rightEscort(
		new Aircraft(Aircraft::Ally, mTextures));
	rightEscort->setPosition(80.f, 50.f);
	mPlayerAircraft->attachChild(std::move(rightEscort));
}
