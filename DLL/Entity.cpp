#include "Entity.hpp"

Entity::Entity()
{
	this->initVariables();
}

Entity::~Entity()
{
	delete this->movement;
	delete this->animationComponent;
}

void Entity::initVariables()
{
	this->movement = nullptr;
	this->animationComponent = nullptr;
}

void Entity::setTexture(sf::Texture& texture)
{
	this->sprite.setTexture(texture);
}

void Entity::createMovement(const float maxVelocity, const float acceleration, const float deceleration)
{
	this->movement = new Movement(this->sprite, maxVelocity, acceleration, deceleration);
}

void Entity::createAnimationComponent(sf::Texture& texture_sheet)
{
	this->animationComponent = new AnimationComponent(this->sprite, texture_sheet);
}

void Entity::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

void Entity::move(const float dir_x, const float dir_y, const float& deltaTime)
{
	if (this->movement)
	{
		this->movement->move(dir_x, dir_y, deltaTime);
	}
}

void Entity::update(const float& deltaTime)
{
	if (this->movement)
	{
		this->movement->update(deltaTime);
	}
}

void Entity::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}