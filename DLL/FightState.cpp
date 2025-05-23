#include "FightState.hpp"

FightState::FightState(StateData* state_data) : State(state_data)
{
	this->initVariables();
	this->initBackground();
	this->initFonts();
	this->initKeybinds();
	this->initButtons();
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

void FightState::initKeybinds()
{
	this->keybinds["CLOSE"] = this->supportedKeys->at("Escape");
	this->keybinds["MOVE_LEFT"] = this->supportedKeys->at("A");
	this->keybinds["MOVE_RIGHT"] = this->supportedKeys->at("D");
	this->keybinds["MOVE_UP"] = this->supportedKeys->at("W");
	this->keybinds["MOVE_DOWN"] = this->supportedKeys->at("S");
}

void FightState::initButtons()
{
	this->buttons["BULBASAUR"] = new Button(305, 920, 300, 80,
		&this->font, "Bulbasaur", 60,
		sf::Color(70, 70, 70, 100), sf::Color(70, 70, 70, 250), sf::Color(70, 70, 70, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

	this->buttons["CHARMANDER"] = new Button(850, 920, 300, 80,
		&this->font, "Charmander", 60,
		sf::Color(70, 70, 70, 100), sf::Color(70, 70, 70, 250), sf::Color(70, 70, 70, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

	this->buttons["RUN"] = new Button(1375, 920, 300, 80,
		&this->font, "Run", 60,
		sf::Color(70, 70, 70, 100), sf::Color(70, 70, 70, 250), sf::Color(70, 70, 70, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));
}

void FightState::update(const float& deltaTime)
{
	this->updateMousePositions();
	this->updateInput(deltaTime);

	this->updateButtons();


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

	if (this->buttons["BULBASAUR"]->isPressed())
	{
		this->states->push(new GameState(this->stateData, "bulbasaur"));
	}

	if (this->buttons["CHARMANDER"]->isPressed())
	{
		this->states->push(new GameState(this->stateData, "charmander"));
	}

	if (this->buttons["RUN"]->isPressed())
	{
		this->endState();
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
}