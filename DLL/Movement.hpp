#pragma once

#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <stack>
#include <fstream>
#include <sstream>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "API.h"

enum movement_states { IDLE = 0, MOVING, MOVING_LEFT, MOVING_RIGHT, MOVING_UP, MOVING_DOWN };

class EXPORT_API Movement
{
private:
	sf::Sprite& sprite;

	float maxVelocity;
	float acceleration;
	float deceleration;

	sf::Vector2f velocity;

public:
	Movement(sf::Sprite& sprite, float maxVelocity, float acceleration, float deceleration);
	virtual ~Movement();

	const sf::Vector2f& getVelocity() const;	

	const bool getState(const short unsigned state) const;

	void move(const float x, const float y, const float& deltaTime);
	void update(const float& deltaTime);

};






#endif