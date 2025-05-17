#include "Game.hpp"
#include <iostream>

void Game::initVariables()
{
	this->window = nullptr;
	this->fullscreen = false;

	this->deltaTime = 0.f;

	this->gridSize = 50.f;
}

void Game::initWindow()
{
	std::ifstream ifs("C:\\Users\\kacpe\\Desktop\\Projekt_JIPP\\proj\\Projekt_JIPP\\items\\config.ini");
	this->videoModes = sf::VideoMode::getFullscreenModes();

	std::string title = "None";
	sf::VideoMode window_bounds = sf::VideoMode::getDesktopMode();
	bool fullscreen = false;
	unsigned framerate_limit = 120;
	bool vertical_sync_enabled = false;
	unsigned antialiasing_level = 0;

	if (ifs.is_open())
	{
		std::getline(ifs, title);
		ifs >> window_bounds.width >> window_bounds.height;
		ifs >> fullscreen;
		ifs >> framerate_limit;
		ifs >> vertical_sync_enabled;
		ifs >> antialiasing_level;
	}
	
	ifs.close();

	this->fullscreen = fullscreen;
	this->windowSettings.antialiasingLevel = antialiasing_level;
	if(this->fullscreen)
		this->window = new sf::RenderWindow(window_bounds, title, sf::Style::Fullscreen, windowSettings);
	else
		this->window = new sf::RenderWindow(window_bounds, title, sf::Style::Titlebar | sf::Style::Close, windowSettings);

	this->window->setFramerateLimit(120);
	this->window->setVerticalSyncEnabled(false);

}

void Game::initStateData()
{
	this->stateData.window = this->window;
	this->stateData.supportedKeys = &this->supportedKeys;
	this->stateData.states = &this->states;
	this->stateData.gridSize = this->gridSize;
}

void Game::initStates()
{
	this->states.push(new MainMenuState(&this->stateData));
}

void Game::initKeys()
{
	this->supportedKeys["Escape"] = sf::Keyboard::Key::Escape;
	this->supportedKeys["A"] = sf::Keyboard::Key::A;
	this->supportedKeys["D"] = sf::Keyboard::Key::D;
	this->supportedKeys["W"] = sf::Keyboard::Key::W;
	this->supportedKeys["S"] = sf::Keyboard::Key::S;
	this->supportedKeys["C"] = sf::Keyboard::Key::C;
	this->supportedKeys["P"] = sf::Keyboard::Key::P;
	this->supportedKeys["O"] = sf::Keyboard::Key::O;

	for (auto& i : this->supportedKeys)
	{
		std::cout << i.first << " " << i.second << "\n";
	}
}

void Game::updateDeltaTime()
{
	this->deltaTime = this->deltaClock.restart().asSeconds();
}

void Game::endApplication()
{
	std::cout << "Ending Application!" << "\n";
}

Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initKeys();
	this->initStateData();
	this->initStates();
}

void Game::updateEvents()
{
	while (this->window->pollEvent(this->sfEvent))
	{
		if (this->sfEvent.type == sf::Event::Closed)
			this->window->close();
	}
}

void Game::update()
{
	this->updateEvents();

	if (!this->states.empty() && this->window->hasFocus())
	{
		this->states.top()->update(this->deltaTime);

		if (this->states.top()->getQuit())
		{
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}
	}
	else
	{
		this->endApplication();
		this->window->close();
	}
}

void Game::render()
{
	this->window->clear();

	if(!this->states.empty())
		this->states.top()->render();

	this->window->display();
}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->updateDeltaTime();
		this->update();
		this->render();
	}
}

Game::~Game()
{
	delete this->window;

	while (this->states.empty())
	{
		delete this->states.top();
		this->states.pop();
	}
}
