#include "GameState.hpp"

GameState::GameState(StateData* state_data, const std::string& pokemon_name) : State(state_data), selectedPokemon(pokemon_name)
{
	this->initView();
	this->initKeybinds();
	this->initFonts();
	this->initTextures();
	this->initPauseMenu();
	this->initPlayers();
	this->initTileMap();
	this->initPokemonSelector();
	this->initPokemonSprite();

	std::srand(static_cast<unsigned>(std::time(nullptr)));
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
	this->player = new Player(190, 190, this->textures["PLAYER_SHEET"]);
}

void GameState::initTileMap()
{
	this->tileMap = new TileMap(this->stateData->gridSize, 50, 50, "C:\\Users\\kacpe\\Desktop\\Projekt_JIPP\\proj\\Projekt_JIPP\\items\\kafelki.png");
	this->tileMap->loadFromFile("C:\\Users\\kacpe\\Desktop\\Projekt_JIPP\\proj\\Projekt_JIPP\\items\\Map.txt");
}

void GameState::initPokemonSelector()
{
	this->pokemonSelector = new PokemonSelector(sf::Vector2f(5, 100), sf::Vector2f(96, 576), sf::Color(255, 255, 153, 200), sf::Color(85, 107, 47, 250));
}

void GameState::initPokemonSprite()
{
	this->playerPokemonName = this->selectedPokemon;

	std::string texturePath;

	if (this->selectedPokemon == "bulbasaur")
	{
		texturePath = "C:\\Users\\kacpe\\Desktop\\Projekt_JIPP\\proj\\Projekt_JIPP\\items\\bulbasaur1.png";
	}
	else if (this->selectedPokemon == "charmander")
	{
		texturePath = "C:\\Users\\kacpe\\Desktop\\Projekt_JIPP\\proj\\Projekt_JIPP\\items\\charmander1.png";
	}
	else if (this->selectedPokemon == "squirtle")
	{
		texturePath = "C:\\Users\\kacpe\\Desktop\\Projekt_JIPP\\proj\\Projekt_JIPP\\items\\squirtle1.png";
	}

	if (!this->pokemonTexture.loadFromFile(texturePath))
	{
		std::cerr << "ERROR::GAMESTATE::COULD_NOT_LOAD_POKEMON_TEXTURE" << std::endl;
	}

	this->pokemonSprite.setTexture(this->pokemonTexture);
	this->pokemonSprite.setPosition(5, 0);
	this->pokemonSprite.setScale(1.5f, 1.5f);
}

void GameState::updateFight(const float& deltaTime)
{
	const std::vector<sf::FloatRect> combatAreas =
	{
		sf::FloatRect(1850.f, 300.f, 200.f, 450.f),
		sf::FloatRect(2150.f, 300.f, 250.f, 200.f),
		sf::FloatRect(1850.f, 900.f, 550.f, 300.f),
		sf::FloatRect(100.f, 1900.f, 750.f, 550.f),
		sf::FloatRect(1050.f, 1900.f, 550.f, 550.f)
	};

	bool currentlyInCombatArea = false;

	for (const auto& area : combatAreas)
	{
		if (area.contains(this->player->getPosition()))
		{
			currentlyInCombatArea = true;
			break;
		}
	}

	if (currentlyInCombatArea != isInCombatArea)
	{
		isInCombatArea = currentlyInCombatArea;

		if (isInCombatArea)
		{
			fightCooldown.restart();
		}
	}

	if (isInCombatArea && fightCooldown.getElapsedTime().asSeconds() >= fightCooldownTime)
	{
		if ((std::rand() % 100) < 1)
		{
			this->states->push(new FightState(this->stateData, this->selectedPokemon, this->playerPokemonLevel, this->playerPokemonExp));
			fightCooldown.restart();

			std::cout << "Entering FightState!" << std::endl;
		}
	}
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

		this->updateFight(deltaTime);
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
		this->states->push(new MainMenuState(this->stateData));
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

	this->player->render(*target);

	

	if (this->pokemonSelector)
	{
		target->setView(this->window->getDefaultView());
		this->pokemonSelector->render(*target);
		
		if (this->pokemonSprite.getTexture())
		{
			target->draw(this->pokemonSprite);
		}

		target->setView(this->view);
	}

	if (this->paused)
	{
		target->setView(this->window->getDefaultView());
		this->pauseMenu->render(this->window);
	}

	sf::Text levelText;
	levelText.setString("Lv. " + std::to_string(playerPokemonLevel));
	levelText.setPosition(100, 100);
	window->draw(levelText);
}

GameState::~GameState()
{
	delete this->pauseMenu;
	delete this->player;
	delete this->tileMap;
}
