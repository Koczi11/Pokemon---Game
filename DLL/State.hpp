#pragma once

#ifndef STATE_H
#define STATE_H

#include "Player.hpp"

class Player;
class State;

class EXPORT_API StateData
{
public:
	StateData() {};

	float gridSize;

	sf::RenderWindow* window;
	std::map<std::string, int>* supportedKeys;
	std::stack<State*>* states;
};

class EXPORT_API State
{
protected:
	StateData* stateData;
	std::stack<State*>* states;
	sf::RenderWindow* window;
	std::map<std::string, int>* supportedKeys;
	std::map<std::string, int> keybinds;
	bool quit;
	bool paused;
	float keyTime;
	float keyTimeMax;
	float gridSize;

	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	sf::Vector2u mousePosGrid;

	std::map<std::string, sf::Texture> textures;

	virtual void initKeybinds() = 0;

public:
	State(StateData* state_data);
	virtual ~State();

	const bool& getQuit() const;
	const bool getKeyTime();
	void endState();
	void pauseState();
	void unpauseState();

	virtual void updateMousePositions(sf::View* view = nullptr);
	virtual void updateKeyTime(const float& deltaTime);
	virtual void updateInput(const float& deltaTime) = 0;
	virtual void update(const float& deltaTime) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;

};

#endif