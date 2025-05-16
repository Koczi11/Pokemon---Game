#pragma once

#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.hpp"
#include "PauseMenu.hpp"
#include "TileMap.hpp"

class EXPORT_API GameState : public State
{
private:
	sf::Font font;
	PauseMenu* pauseMenu;

	Player* player;
	sf::Texture texture;

	TileMap* tileMap;

	void initKeybinds();
	void initFonts();
	void initTextures();
	void initPauseMenu();
	void initPlayers();
	void initTileMap();

public:
	GameState(StateData* state_data);
	virtual ~GameState();

	
	void updatePausedInput(const float& deltaTime);
	void updateInput(const float& deltaTime);
	void updatePauseMenuButtons();
	void update(const float& deltaTime);
	void render(sf::RenderTarget* target = nullptr);
};

#endif