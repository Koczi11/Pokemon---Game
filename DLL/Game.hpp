#pragma once

#ifndef GAME_H
#define GAME_H

#include "MainMenuState.hpp"

class EXPORT_API Game
{
private:
	StateData stateData;
	sf::RenderWindow* window;
	sf::Event sfEvent;
	std::vector<sf::VideoMode> videoModes;
	sf::ContextSettings windowSettings;
	bool fullscreen;

	sf::Clock deltaClock;
	float deltaTime;
	
	std::stack<State*> states;

	std::map<std::string, int> supportedKeys;

	float gridSize;

	void initVariables();
	void initWindow();
	void initKeys();
	void initStateData();
	void initStates();

public:
		Game();
		virtual ~Game();

		void endApplication();
		void updateDeltaTime();
		void updateEvents();
		void update();
		void render();
		void run();
};

#endif