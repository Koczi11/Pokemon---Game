#pragma once

#ifndef POKEMON_H
#define POKEMON_H

#include "Entity.hpp"


class EXPORT_API Pokemon : public Entity
{
private:
	sf::Sprite m_sprite;

	void initVariables();
	void initComponents();

protected:

public:
	Pokemon(float x, float y, sf::Texture& texture_sheet);
	virtual ~Pokemon();

	void update(const float& deltaTime);

	void render(sf::RenderTarget& target);
};


#endif