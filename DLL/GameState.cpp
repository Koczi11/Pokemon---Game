#include "GameState.hpp"

GameState::GameState(StateData* state_data) : State(state_data)
{
	this->initView();
	this->initKeybinds();
	this->initFonts();
	this->initTextures();
	this->initPauseMenu();
	this->initPlayers();
	this->initTileMap();
}

void GameState::initView()
{
	this->view.setSize(sf::Vector2f(
			this->stateData->window->getSize().x,
			this->stateData->window->getSize().y
		)
	);

	this->view.setCenter(sf::Vector2f(
			this->stateData->window->getSize().x,
			this->stateData->window->getSize().y
		)
	);
}

void GameState::initKeybinds()
{
	this->keybinds["CLOSE"] = this->supportedKeys->at("Escape");
	this->keybinds["MOVE_LEFT"] =  this->supportedKeys->at("A");
	this->keybinds["MOVE_RIGHT"] = this->supportedKeys->at("D");
	this->keybinds["MOVE_UP"] = this->supportedKeys->at("W");
	this->keybinds["MOVE_DOWN"] = this->supportedKeys->at("S");
}

void GameState::initFonts()
{
	if (!this->font.loadFromFile("C:\\Users\\kacpe\\Desktop\\Projekt_JIPP\\proj\\Projekt_JIPP\\items\\OpenSans_Condensed-Bold.ttf"))
	{
		throw("ERROR::MAINMENUSTATE::INITFONTS::Could not load font");
	}
}

void GameState::initTextures()
{
	if (!this->textures["PLAYER_SHEET"].loadFromFile("C:\\Users\\kacpe\\Desktop\\Projekt_JIPP\\proj\\Projekt_JIPP\\items\\sCrkzvs.png"))
	{
		std::cout << "ERROR::GAMESTATE::INITTEXTURES::Could not load player texture" << "\n";
	}
}

void GameState::initPauseMenu()
{
	this->pauseMenu = new PauseMenu(*this->window, this->font);

	this->pauseMenu->addButton("QUIT", 700.f, "QUIT");
}

void GameState::initPlayers()
{
	this->player = new Player(100, 100, this->textures["PLAYER_SHEET"]);
}

void GameState::initTileMap()
{
	this->tileMap = new TileMap(this->stateData->gridSize, 100, 100, "C:\\Users\\kacpe\\Desktop\\Projekt_JIPP\\proj\\Projekt_JIPP\\items\\kafelki.png");
	this->tileMap->loadFromFile("C:\\Users\\kacpe\\Desktop\\Projekt_JIPP\\proj\\Projekt_JIPP\\items\\Map.txt");
}

void GameState::updateView(const float& deltaTime)
{
	this->view.setCenter(std::floor(this->player->getPosition().x), std::floor(this->player->getPosition().y));
}

void GameState::update(const float& deltaTime)
{
	this->updateMousePositions();
	this->updateKeyTime(deltaTime);
	this->updatePausedInput(deltaTime);

	if (!this->paused)
	{
		this->updateView(deltaTime);

		this->updateInput(deltaTime);

		this->player->update(deltaTime);

		this->updateTileMap(deltaTime);
	}
	else
	{
		this->pauseMenu->update(this->mousePosWindow);
		this->updatePauseMenuButtons();
	}
}

void GameState::updatePausedInput(const float& deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))) && this->getKeyTime())
	{
		if (!this->paused)
			this->pauseState();
		else
			this->unpauseState();
	}
}

void GameState::updateInput(const float& deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
		this->player->move(-1.f, 0.f, deltaTime);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
		this->player->move( 1.f, 0.f, deltaTime);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))
		this->player->move(0.f, -1.f, deltaTime);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
		this->player->move(0.f, 1.f, deltaTime);
}

void GameState::updateTileMap(const float& deltaTime)
{
	this->tileMap->update();
	this->tileMap->updateCollision(this->player, deltaTime);
}

void GameState::updatePauseMenuButtons()
{
	if (this->pauseMenu->isButtonPressed("QUIT") && this->getKeyTime())
	{
		this->endState();
	}
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target)
	{
		target = this->window;
	}
	
	target->setView(this->view);
	this->tileMap->render(*target);

	this->player->render(target);
	
	if (this->paused)
	{
		target->setView(this->window->getDefaultView());
		this->pauseMenu->render(this->window);
	}
}

GameState::~GameState()
{
	delete this->pauseMenu;
	delete this->player;
	delete this->tileMap;
}
