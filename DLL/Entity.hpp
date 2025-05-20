#pragma once

#ifndef ENTITY_H
#define ENTITY_H

#include "Movement.hpp"
#include "AnimationComponent.hpp"
#include "HitboxComponent.hpp"

class EXPORT_API Entity
{
private:
	void initVariables();

protected:
	sf::Sprite sprite;

	Movement* movement;
	HitboxComponent* hitboxComponent;
	AnimationComponent* animationComponent;

public:
	Entity();	
	virtual ~Entity();
	
	void setTexture(sf::Texture& texture);
	void createHitboxComponent(sf::Sprite& sprite, float offset_x, float offset_y, float width, float height);
	void createMovement(const float maxVelocity, const float acceleration, const float deceleration);
	void createAnimationComponent(sf::Texture& texture_sheet);

	virtual const sf::Vector2f& getPosition() const;
	virtual const sf::Vector2u getGridPosition(const unsigned gridSize) const;
	virtual const sf::FloatRect getGlobalBounds() const;
	virtual const sf::FloatRect& getNextPositionBounds(const float& deltaTime) const;

	virtual void setPosition(const float x, const float y);
	
	virtual void move(const float x, const float y, const float& deltaTime);
	virtual void stopVelocity();
	virtual void stopVelocityX();
	virtual void stopVelocityY();

	virtual void update(const float& deltaTime) = 0;
	virtual void render(sf::RenderTarget& target) = 0;
};

#endif