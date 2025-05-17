#pragma once

#ifndef ENTITY_H
#define ENTITY_H

#include "Movement.hpp"
#include "AnimationComponent.hpp"

class EXPORT_API Entity
{
private:
	void initVariables();

protected:
	sf::Sprite sprite;

	Movement* movement;
	AnimationComponent* animationComponent;

public:
	Entity();	
	virtual ~Entity();
	
	void setTexture(sf::Texture& texture);
	void createMovement(const float maxVelocity, const float acceleration, const float deceleration);
	void createAnimationComponent(sf::Texture& texture_sheet);

	virtual const sf::Vector2f& getPosition() const;

	virtual void setPosition(const float x, const float y);
	virtual void move(const float x, const float y, const float& deltaTime);

	virtual void update(const float& deltaTime);
	virtual void render(sf::RenderTarget* target);
};

#endif