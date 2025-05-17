#include "Entity.hpp"

Entity::Entity()
{
	this->initVariables();
}

Entity::~Entity()
{
	delete this->hitboxComponent;
	delete this->movement;
	delete this->animationComponent;
}

void Entity::initVariables()
{
	this->hitboxComponent = nullptr;
	this->movement = nullptr;
	this->animationComponent = nullptr;
}

void Entity::setTexture(sf::Texture& texture)
{
	this->sprite.setTexture(texture);
}

void Entity::createHitboxComponent(sf::Sprite& sprite, float offset_x, float offset_y, float width, float height)
{
	this->hitboxComponent = new HitboxComponent(sprite, offset_x, offset_y, width, height);
}

void Entity::createMovement(const float maxVelocity, const float acceleration, const float deceleration)
{
	this->movement = new Movement(this->sprite, maxVelocity, acceleration, deceleration);
}

void Entity::createAnimationComponent(sf::Texture& texture_sheet)
{
	this->animationComponent = new AnimationComponent(this->sprite, texture_sheet);
}

const sf::Vector2f& Entity::getPosition() const
{
	if (this->hitboxComponent)
		return this->hitboxComponent->getPosition();

	return this->sprite.getPosition();
}

const sf::Vector2u Entity::getGridPosition(const unsigned gridSizeU) const
{
	return sf::Vector2u(
		static_cast<unsigned>(this->sprite.getPosition().x) / gridSizeU,
		static_cast<unsigned>(this->sprite.getPosition().y) / gridSizeU
	);
}

const sf::FloatRect Entity::getGlobalBounds() const
{
	return this->sprite.getGlobalBounds();
}

const sf::FloatRect& Entity::getNextPositionBounds(const float& deltaTime) const
{
	if (this->movement && this->hitboxComponent)
	{
		return this->hitboxComponent->getNextPosition(this->movement->getVelocity());
	}
}

void Entity::setPosition(const float x, const float y)
{
	if (this->hitboxComponent)
		this->hitboxComponent->setPosition(x, y);
	else
		this->sprite.setPosition(x, y);
}

void Entity::move(const float dir_x, const float dir_y, const float& deltaTime)
{
	if (this->movement)
	{
		this->movement->move(dir_x, dir_y, deltaTime);
	}
}

void Entity::stopVelocity()
{
	if (this->movement)
	{
		this->movement->stopVelocity();
	}
}

void Entity::stopVelocityX()
{
	if (this->movement)
	{
		this->movement->stopVelocityX();
	}
}

void Entity::stopVelocityY()
{
	if (this->movement)
	{
		this->movement->stopVelocityY();
	}
}


void Entity::update(const float& deltaTime)
{
	if (this->movement)
	{
		this->movement->update(deltaTime);
	}
}

void Entity::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);

	if (this->hitboxComponent)
		this->hitboxComponent->render(target);
}