#pragma once

#ifndef HITBOXCOMPONENT_H
#define HITBOXCOMPONENT_H

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


class EXPORT_API HitboxComponent
{
private:
	sf::Sprite& sprite;
	sf::RectangleShape hitbox;
	sf::FloatRect nextPosition;
	float offsetX;
	float offsetY;

public:
	HitboxComponent(sf::Sprite& sprite, float offset_x, float offset_y, float width, float height);
	virtual ~HitboxComponent();

	const sf::FloatRect& getNextPosition(const sf::Vector2f& velocity);
	const sf::FloatRect getGlobalBounds() const;
	const sf::Vector2f& getPosition() const;
	void setPosition(sf::Vector2f& position);
	void setPosition(const float x, const float y);
	bool Intersects(const sf::FloatRect& frect);

	void update();
	void render(sf::RenderTarget& target);
};






#endif