#include "Player.hpp"

void Player::initVariables()
{

}

void Player::initComponents()
{
	
}

Player::Player(float x, float y, sf::Texture& texture_sheet)
{
	this->initVariables();
	this->initComponents();
	this->setPosition(x, y);

	this->createHitboxComponent(this->sprite, 11.f, 3.f, 74.f, 87.f);
	this->createMovement(300.f, 15.f, 10.f);
	this->createAnimationComponent(texture_sheet);

	this->animationComponent->addAnimation("IDLE_LEFT", 10.f, 0, 0, 0, 0, 97, 94);
	this->animationComponent->addAnimation("WALK_LEFT", 10.f, 0, 1, 3, 1, 97, 94);
	this->animationComponent->addAnimation("WALK_RIGHT", 10.f, 0, 2, 3, 2, 97, 94);
	this->animationComponent->addAnimation("WALK_UP", 10.f, 0, 3, 3, 3, 97, 94);
	this->animationComponent->addAnimation("WALK_DOWN", 10.f, 0, 0, 3, 0, 97, 94);
}

void Player::update(const float& deltaTime)
{
	this->movement->update(deltaTime);

	if (this->movement->getState(IDLE))
	{
		this->animationComponent->play("IDLE_LEFT", deltaTime);
	}
	else if (this->movement->getState(MOVING_LEFT))
	{
		this->animationComponent->play("WALK_LEFT", deltaTime);
	}
	else if (this->movement->getState(MOVING_RIGHT))
	{
		this->animationComponent->play("WALK_RIGHT", deltaTime);
	}
	else if (this->movement->getState(MOVING_UP))
	{
		this->animationComponent->play("WALK_UP", deltaTime);
	}
	else if (this->movement->getState(MOVING_DOWN))
	{
		this->animationComponent->play("WALK_DOWN", deltaTime);
	}

	this->hitboxComponent->update();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);

	//this->hitboxComponent->render(target);
}

Player::~Player()
{

}