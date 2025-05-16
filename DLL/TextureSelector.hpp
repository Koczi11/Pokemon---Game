#pragma once

#ifndef TEXTURESELECTOR_H
#define TEXTURESELECTOR_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <stack>
#include <fstream>
#include <sstream>
#include <map>
#include "Button.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "API.h"

class EXPORT_API TextureSelector
{
private:
	float gridSize;
	bool active;
	bool hidden;
	Button* hide_button;

	sf::RectangleShape bounds;
	sf::Sprite sheet;
	sf::RectangleShape selector;
	sf::Vector2u mousePosGrid;
	sf::IntRect textureRect;

public:
	TextureSelector(float x, float y, float width, float height, float gridSize, const sf::Texture* texture_sheet, sf::Font& font, std::string text);
	~TextureSelector();

	const bool& getActive() const;
	const sf::IntRect& getTextureRect() const;

	void update(const sf::Vector2i& mousePosWindow);
	void render(sf::RenderTarget& target);

};

#endif

