#pragma once

#ifndef TILE_H
#define TILE_H

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

enum TileTypes {DEFAULT = 0, DAMAGING};

class EXPORT_API Tile
{
private:
	

protected:
	sf::RectangleShape shape;
	bool collision;
	short type;

public:
	Tile();
	Tile(unsigned grid_x, unsigned grid_y, float gridSizeF, const sf::Texture& texture, const sf::IntRect& texture_rect, bool collision = false, short type = TileTypes::DEFAULT);
	virtual ~Tile();

	const std::string getAsString() const;

	void update();
	void render(sf::RenderTarget& target);
};


#endif