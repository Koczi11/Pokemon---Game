#pragma once

#ifndef STARTSTATE_H
#define STARTSTATE_H

#include "GameState.hpp"
#include "EditorState.hpp"
#include "SettingsState.hpp"
#include "Button.hpp"

class EXPORT_API StartState : public State
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
	StartState(StateData* state_data);
	virtual ~StartState();

	void updateInput(const float& deltaTime);
	void updateButtons();
	void update(const float& deltaTime);
	void renderButtons(sf::RenderTarget& target);
	void render(sf::RenderTarget* target = nullptr);
};

#endif