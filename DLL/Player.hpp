#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.hpp"

class EXPORT_API Player : public Entity
{
private:
    sf::Sprite m_sprite;

	void initVariables();
	void initComponents();

protected:

public:
	Player(float x, float y, sf::Texture& texture_sheet);
	virtual ~Player();

	void update(const float& deltaTime);
};


#endif