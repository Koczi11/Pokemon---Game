#pragma once

#ifndef TILEMAP_H
#define TILEMAP_H

#include "Tile.hpp"
#include "Entity.hpp"

class Tile;
class Entity;
class HitboxComponent;

class EXPORT_API TileMap
{
private:
	void clear();

	float gridSizeF;
	unsigned gridSizeU;
	sf::Vector2u maxSize;
	sf::Vector2f maxSizeWorldF;
	unsigned layers;
	std::vector<std::vector<std::vector<Tile*>>> map;
	std::string textureFile;
	sf::Texture tileTextureSheet;
	sf::RectangleShape collisionBox;

	int fromX;
	int toX;
	int fromY;
	int toY;
	int layer;
public:
	TileMap(float gridSize, unsigned width, unsigned height, std::string texture_file);
	virtual ~TileMap();

	const sf::Texture* getTileSheet() const;

	void update();
	void render(sf::RenderTarget& target, Entity* entity = nullptr);

	void updateCollision(Entity* entity, const float& deltaTime);

	void addTile(const unsigned x, const unsigned y, const unsigned z, const sf::IntRect& texture_rect, const bool& collision, const short& type);
	void removeTile(const unsigned x, const unsigned y, const unsigned z);

	void saveToFile(const std::string file_name);
	void loadFromFile(const std::string file_name);
};


#endif