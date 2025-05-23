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

	void initVariables();
	void initBackground();
	void initFonts();
	void initKeybinds();
	void initButtons();

public:
	FightState(StateData* state_data);
	virtual ~FightState();

	void updateInput(const float& deltaTime);
	void updateButtons();
	void update(const float& deltaTime);
	void renderButtons(sf::RenderTarget& target);
	void render(sf::RenderTarget* target = nullptr);
};

#endif