#pragma once

#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.hpp"
#include "PauseMenu.hpp"
#include "SettingsState.hpp"
#include "MainMenuState.hpp"
#include "TileMap.hpp"
#include "PokemonSelector.hpp"
#include "Pokemon.hpp"
#include "FightState.hpp"

class PauseMenu;
class Player;
class TileMap;
class sf::View;
class sf::Font;

class EXPORT_API GameState : public State
{
private:
	sf::View view;

	sf::Font font;
	PauseMenu* pauseMenu;

	Player* player;
	sf::Texture texture;

	TileMap* tileMap;
	PokemonSelector* pokemonSelector;

	std::string selectedPokemon;
	sf::Sprite pokemonSprite;
	sf::Texture pokemonTexture;

	sf::Clock fightCooldown;
	const float fightCooldownTime = 10.0f;
	bool isInCombatArea = false;

	const std::vector<sf::FloatRect> combatAreas;

	void initView();
	void initKeybinds();
	void initFonts();
	void initTextures();
	void initPauseMenu();
	void initPlayers();
	void initTileMap();
	void initPokemonSelector();
	void initPokemonSprite();

public:
	GameState(StateData* state_data, const std::string& pokemon_name);
	virtual ~GameState();

	void updateFight(const float& deltaTime);

	void updateView(const float& deltaTime);
	void updatePausedInput(const float& deltaTime);
	void updateInput(const float& deltaTime);
	void updatePauseMenuButtons();
	void updateTileMap(const float& deltaTime);
	void update(const float& deltaTime);
	void render(sf::RenderTarget* target = nullptr);
};

#endif