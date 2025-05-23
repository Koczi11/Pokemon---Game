#pragma once

#ifndef POKEMONSELECTOR_H
#define POKEMONSELECTOR_H

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

class EXPORT_API PokemonSelector
{
private:
	sf::RectangleShape shape;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f position;
	sf::Vector2f size;

	bool textureLoaded;

public:
	PokemonSelector(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Color& color, const sf::Color& color2);
	~PokemonSelector();

	bool loadImage(const std::string& filename, const sf::Vector2f& position);
	void render(sf::RenderTarget& target);
};







#endif