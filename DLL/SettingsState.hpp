#pragma once

#ifndef SETTINGSSTATE_H
#define SETTINGSSTATE_H

#include "State.hpp"
#include "Button.hpp"
#include "EditorState.hpp"

class SettingsState : public State
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
    SettingsState(StateData* state_data);
    virtual ~SettingsState();

	void updateInput(const float& deltaTime);
	void updateButtons();
	void update(const float& deltaTime);
	void renderButtons(sf::RenderTarget* target = nullptr);
	void render(sf::RenderTarget* target = nullptr);
};


#endif
