#pragma once

#ifndef BUTTON_H
#define BUTTON_H

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

enum button_states { BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE};

class EXPORT_API Button
{
private:
	short unsigned buttonState;

	sf::RectangleShape shape;
	sf::Font* font;

	sf::Color text_idle_color;
	sf::Color text_hover_color;
	sf::Color text_active_color;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;

public:
	Button(float x, float y, float width, float height, sf::Font* font, std::string text, unsigned character_size, sf::Color text_idle_color, sf::Color text_hover_color, sf::Color text_active_color, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
	~Button();

	sf::Text text;

	const bool isPressed() const;

	void update(const sf::Vector2i& mousePosWindow);
	void render(sf::RenderTarget& target);
};


#endif