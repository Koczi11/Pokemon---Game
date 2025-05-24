#pragma once

#ifndef FIGHTSTATE_H
#define FIGHTSTATE_H

#include "GameState.hpp"
#include "EditorState.hpp"
#include "SettingsState.hpp"
#include "Button.hpp"

class EXPORT_API FightState : public State
{
private:
	sf::Texture backgroundTexture;
	sf::RectangleShape background;
	sf::Font font;

	std::map<std::string, Button*> buttons;

	Pokemon* playerPokemon;
	Pokemon* enemyPokemon;

	std::string selectedPokemon;

	sf::RectangleShape playerHpBar;
	sf::RectangleShape enemyHpBar;
	sf::Text playerHpText;
	sf::Text enemyHpText;
	sf::Text movesText[4];

	int selectedMove;
	bool playerTurn;

	void initVariables();
	void initBackground();
	void initFonts();
	void initKeybinds();
	void initButtons();
	void initTextures();
	void initPokemons();
	void initGUI();

public:
	FightState(StateData* state_data, const std::string& pokemon_name);
	virtual ~FightState();

	void updateHpBars();
	void playerAttack(int moveIndex);
	void enemyAttack();
	void checkBattleEnd();

	void handleEnemyTurn();

	void updateInput(const float& deltaTime);
	void updateButtons();
	void update(const float& deltaTime);
	void renderButtons(sf::RenderTarget& target);
	void render(sf::RenderTarget* target = nullptr);
};

#endif