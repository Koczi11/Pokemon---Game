#pragma once

#ifndef EDITORSTATE_H
#define EDITORSTATE_H

#include "State.hpp"
#include "Button.hpp"
#include "PauseMenu.hpp"
#include "TileMap.hpp"
#include "TextureSelector.hpp"

class State;
class PauseMenu;
class TileMap;
class TextureSelector;


class EXPORT_API EditorState : public State
{
private:
	sf::View view;

	PauseMenu* pauseMenu;

	sf::Font font;
	sf::Text cursorText;
	std::map<std::string, Button*> buttons;

	TileMap* tileMap;

	sf::IntRect textureRect;
	sf::RectangleShape selectorRect;

	TextureSelector* textureSelector;

	bool collision;
	short type;
	
	void initVariables();
	void initView();
	void initBackground();
	void initFonts();
	void initText();
	void initKeybinds();
	void initPauseMenu();
	void initButtons();
	void initTileMap();
	void initGUI();

public:
	EditorState(StateData* state_data);
	virtual ~EditorState();
	
	void updateInput(const float& deltaTime);
	void updatePausedInput(const float& deltaTime);
	void updateEditorInput(const float& deltaTime);
	void updateButtons();
	void updateGUI();
	void updatePauseMenuButtons();
	void update(const float& deltaTime);
	void renderButtons(sf::RenderTarget* target = nullptr);
	void renderGUI(sf::RenderTarget& target);
	void render(sf::RenderTarget* target = nullptr);
};


#endif