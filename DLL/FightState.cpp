#include "FightState.hpp"

FightState::FightState(StateData* state_data, const std::string& pokemon_name) : State(state_data), selectedPokemon(pokemon_name), selectedMove(0), playerTurn(true)
{
	this->initVariables();
	this->initBackground();
	this->initFonts();
	this->initKeybinds();
	this->initButtons();
	this->initPokemons();
	this->initTextures();
	this->initGUI();
}

void FightState::initVariables()
{

}

void FightState::initBackground()
{
	this->background.setSize(sf::Vector2f(static_cast<float>(this->window->getSize().x), static_cast<float>(this->window->getSize().y)));

	if (!this->backgroundTexture.loadFromFile("C:\\Users\\kacpe\\Desktop\\Projekt_JIPP\\proj\\Projekt_JIPP\\items\\fight.png"))
	{
		throw"ERROR::MAINMENUSTATE::INITBACKGROUND::Could not load background texture";
	}

	this->background.setTexture(&this->backgroundTexture);
}

void FightState::initFonts()
{
	if (!this->font.loadFromFile("C:\\Users\\kacpe\\Desktop\\Projekt_JIPP\\proj\\Projekt_JIPP\\items\\OpenSans_Condensed-Bold.ttf"))
	{
		throw("ERROR::MAINMENUSTATE::INITFONTS::Could not load font");
	}
}

void FightState::initTextures()
{
	if (!this->textures["BULBASAUR_FIGHT"].loadFromFile("C:\\Users\\kacpe\\Desktop\\Projekt_JIPP\\proj\\Projekt_JIPP\\items\\bulbasaur_fight.png"))
	{
		std::cout << "ERROR::GAMESTATE::INITTEXTURES::Could not load player texture" << "\n";
	}

	if (!this->textures["CHARMANDER_FIGHT"].loadFromFile("C:\\Users\\kacpe\\Desktop\\Projekt_JIPP\\proj\\Projekt_JIPP\\items\\charmander_fight.png"))
	{
		std::cout << "ERROR::GAMESTATE::INITTEXTURES::Could not load player texture" << "\n";
	}

	if (!this->textures["SQUIRTLE_FIGHT"].loadFromFile("C:\\Users\\kacpe\\Desktop\\Projekt_JIPP\\proj\\Projekt_JIPP\\items\\squirtle_fight.png"))
	{
		std::cout << "ERROR::GAMESTATE::INITTEXTURES::Could not load player texture" << "\n";
	}

	if (!this->textures["RATATA_FIGHT"].loadFromFile("C:\\Users\\kacpe\\Desktop\\Projekt_JIPP\\proj\\Projekt_JIPP\\items\\rattata.png"))
	{
		std::cout << "ERROR::GAMESTATE::INITTEXTURES::Could not load player texture" << "\n";
	}
}

void FightState::initPokemons()
{
	if (this->selectedPokemon == "bulbasaur")
	{
		this->playerPokemon = new Pokemon(300, 570, this->textures["BULBASAUR_FIGHT"], "Bulbasaur", 120, 49, 49, 45, { "Vine Whip", "Tackle", "Growl", "Leech Seed" });
		dynamic_cast<Button*>(this->buttons["MOVE_1"])->text.setString("Vine Whip");
		dynamic_cast<Button*>(this->buttons["MOVE_2"])->text.setString("Tackle");
		dynamic_cast<Button*>(this->buttons["MOVE_3"])->text.setString("Growl");
		dynamic_cast<Button*>(this->buttons["MOVE_4"])->text.setString("Leech Seed");
	}
	else if (this->selectedPokemon == "charmander")
	{
		this->playerPokemon = new Pokemon(300, 570, this->textures["CHARMANDER_FIGHT"], "Charmander", 100, 52, 43, 65, {"Ember", "Scratch", "Growl", "Smokescreen"});
		dynamic_cast<Button*>(this->buttons["MOVE_1"])->text.setString("Ember");
		dynamic_cast<Button*>(this->buttons["MOVE_2"])->text.setString("Scratch");
		dynamic_cast<Button*>(this->buttons["MOVE_3"])->text.setString("Growl");
		dynamic_cast<Button*>(this->buttons["MOVE_4"])->text.setString("Smokescreen");
	}
	else if (this->selectedPokemon == "squirtle")
	{
		this->playerPokemon = new Pokemon(300, 570, this->textures["SQUIRTLE_FIGHT"], "Squirtle", 110, 48, 65, 43, {"Bubble", "Tackle", "Tail Whip", "Withdraw"});
		dynamic_cast<Button*>(this->buttons["MOVE_1"])->text.setString("Bubble");
		dynamic_cast<Button*>(this->buttons["MOVE_2"])->text.setString("Tackle");
		dynamic_cast<Button*>(this->buttons["MOVE_3"])->text.setString("Tail Whip");
		dynamic_cast<Button*>(this->buttons["MOVE_4"])->text.setString("Withdraw");
	}



	this->enemyPokemon = new Pokemon(1250, 280, this->textures["RATATA_FIGHT"], "Rattata", 80, 56, 35, 72, {"Tackle", "Quick Attack", "Tail Whip", "Bite"});
}

void FightState::initKeybinds()
{
	
}

void FightState::initButtons()
{
	this->buttons["RUN"] = new Button(1375, 920, 300, 80,
		&this->font, "Run", 60,
		sf::Color(70, 70, 70, 100), sf::Color(70, 70, 70, 250), sf::Color(70, 70, 70, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

	this->buttons["MOVE_1"] = new Button(100, 200, 300, 80,
		&this->font, "Tackle", 60,
		sf::Color(70, 70, 70, 100), sf::Color(70, 70, 70, 250), sf::Color(70, 70, 70, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

	this->buttons["MOVE_2"] = new Button(300, 300, 300, 80,
		&this->font, "Quick Attack", 60,
		sf::Color(70, 70, 70, 100), sf::Color(70, 70, 70, 250), sf::Color(70, 70, 70, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

	this->buttons["MOVE_3"] = new Button(500, 400, 300, 80,
		&this->font, "Growl", 60,
		sf::Color(70, 70, 70, 100), sf::Color(70, 70, 70, 250), sf::Color(70, 70, 70, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

	this->buttons["MOVE_4"] = new Button(700, 500, 300, 80,
		&this->font, "Tail Whip", 60,
		sf::Color(70, 70, 70, 100), sf::Color(70, 70, 70, 250), sf::Color(70, 70, 70, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

}

void FightState::initGUI()
{
	this->playerHpBar.setSize(sf::Vector2f(200, 20));
	this->playerHpBar.setFillColor(sf::Color::Green);
	this->playerHpBar.setPosition(300, 500);

	this->enemyHpBar.setSize(sf::Vector2f(200, 20));
	this->enemyHpBar.setFillColor(sf::Color::Green);
	this->enemyHpBar.setPosition(1300, 700);

	this->playerHpText.setFont(this->font);
	this->playerHpText.setCharacterSize(20);
	this->playerHpText.setPosition(300, 470);

	this->playerHpText.setFont(this->font);
	this->playerHpText.setCharacterSize(20);
	this->playerHpText.setPosition(1250, 170);

	this->enemyHpText.setFont(this->font);
	this->enemyHpText.setCharacterSize(20);
	this->enemyHpText.setPosition(1250, 170);

	for (int i = 0; i < 4; ++i)
	{
		this->movesText[i].setFont(this->font);
		this->movesText[i].setCharacterSize(24);
		this->movesText[i].setPosition(50, 700 + i * 40);

		if (i < this->playerPokemon->getMoves().size())
			this->movesText[i].setString(this->playerPokemon->getMoves()[i]);
	}

	this->updateHpBars();
}

void FightState::updateHpBars()
{
	float playerHpPercent = static_cast<float>(this->playerPokemon->getCurrentHP()) / this->playerPokemon->getMaxHP();
	this->playerHpBar.setSize(sf::Vector2f(200 * playerHpPercent, 20));

	std::stringstream playerSs;
	playerSs << this->playerPokemon->getName() << ": " << this->playerPokemon->getCurrentHP() << "/" << this->playerPokemon->getMaxHP();
	this->playerHpText.setString(playerSs.str());

	float enemyHpPercent = static_cast<float>(this->enemyPokemon->getCurrentHP()) / this->enemyPokemon->getMaxHP();
	this->enemyHpBar.setSize(sf::Vector2f(200 * enemyHpPercent, 20));

	std::stringstream enemySs;
	enemySs << this->enemyPokemon->getName() << ": " << this->enemyPokemon->getCurrentHP() << "/" << this->enemyPokemon->getMaxHP();
	this->enemyHpText.setString(enemySs.str());
}

void FightState::playerAttack(int moveIndex)
{
	if (moveIndex >= this->playerPokemon->getMoves().size()) return;

	std::string move = this->playerPokemon->getMoves()[moveIndex];
	int damage = this->playerPokemon->calculateDamage(*this->enemyPokemon, move);
	this->enemyPokemon->takeDamage(damage);

	this->updateHpBars();
}

void FightState::enemyAttack()
{
	if (this->enemyPokemon->getMoves().empty()) return;

	int randomMove = rand() % this->enemyPokemon->getMoves().size();
	std::string move = this->enemyPokemon->getMoves()[randomMove];
	int damage = this->enemyPokemon->calculateDamage(*this->playerPokemon, move);
	this->playerPokemon->takeDamage(damage);

	this->updateHpBars();
}

void FightState::checkBattleEnd()
{
	if (this->playerPokemon->isFainted())
	{
		this->endState();
	}
	else if (this->enemyPokemon->isFainted())
	{
		this->endState();
	}
}

void FightState::update(const float& deltaTime)
{
	this->updateMousePositions();
	this->updateInput(deltaTime);

	this->updateButtons();

	this->playerPokemon->update(deltaTime);
	this->enemyPokemon->update(deltaTime);
}

void FightState::updateInput(const float& deltaTime)
{

}

void FightState::updateButtons()
{
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosWindow);
	}

	if (this->buttons["RUN"]->isPressed())
	{
		this->endState();
	}

	if (this->playerTurn)
	{
		if (this->buttons["MOVE_1"]->isPressed())
		{
			this->playerAttack(0);
			this->handleEnemyTurn();
		}
		else if (this->buttons["MOVE_2"]->isPressed())
		{
			this->playerAttack(1);
			this->handleEnemyTurn();
		}
		else if (this->buttons["MOVE_3"]->isPressed())
		{
			this->playerAttack(2);
			this->handleEnemyTurn();
		}
		else if (this->buttons["MOVE_4"]->isPressed())
		{
			this->playerAttack(3);
			this->handleEnemyTurn();
		}
	}
}

void FightState::handleEnemyTurn()
{
	if (!this->enemyPokemon->isFainted())
	{
		sf::sleep(sf::seconds(1.0f));
		this->enemyAttack();
		this->checkBattleEnd();
	}
	else
	{
		this->checkBattleEnd();
	}
}

void FightState::renderButtons(sf::RenderTarget& target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void FightState::render(sf::RenderTarget* target)
{
	if (!target)
	{
		target = this->window;
	}

	target->draw(this->background);

	this->renderButtons(*target);

	this->playerPokemon->render(*target);
	this->enemyPokemon->render(*target);

	target->draw(this->playerHpBar);
	target->draw(this->enemyHpBar);
	target->draw(this->playerHpText);
	target->draw(this->enemyHpText);

	/*sf::Text mouseText;
	mouseText.setPosition(this->mousePosView.x, this->mousePosView.y - 50);
	mouseText.setFont(this->font);
	mouseText.setCharacterSize(12);
	std::stringstream ss;
	ss << this->mousePosView.x << " " << this->mousePosView.y;
	mouseText.setString(ss.str());

	target->draw(mouseText);*/
}

FightState::~FightState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}

	delete this->playerPokemon;
	delete this->enemyPokemon;
}