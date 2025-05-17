#include"PauseMenu.hpp"

PauseMenu::PauseMenu(sf::RenderWindow& window, sf::Font& font) : font(font)
{
	this->background.setSize(
		sf::Vector2f(
			static_cast<float>(window.getSize().x), 
			static_cast<float>(window.getSize().y)
		)
	);

	this->background.setFillColor(sf::Color(20, 20, 20, 100));

	this->container.setSize(
		sf::Vector2f(
			static_cast<float>(window.getSize().x) / 3.f, 
			static_cast<float>(window.getSize().y) / 1.2f
		)
	);

	this->container.setFillColor(sf::Color(20, 20, 20, 200));

	this->container.setPosition(
		static_cast<float>(window.getSize().x) / 2.f - this->container.getSize().x / 2.f,
		static_cast<float>(window.getSize().y) / 2.f - this->container.getSize().y / 2.f
	);

	this->menuText.setFont(font);
	this->menuText.setFillColor(sf::Color(255, 255, 255, 200));
	this->menuText.setCharacterSize(60);
	this->menuText.setString("PAUSED");
	this->menuText.setPosition(
		this->container.getPosition().x + this->container.getSize().x / 2.f - this->menuText.getGlobalBounds().width / 2.f,
		this->container.getPosition().y + 20
	);
}

PauseMenu::~PauseMenu()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}

std::map<std::string, Button*>& PauseMenu::getButtons()
{
	return this->buttons;
}

const bool PauseMenu::isButtonPressed(const std::string key)
{
	return this->buttons[key]->isPressed();
}

void PauseMenu::addButton(const std::string key, float y, const std::string text)
{
	float x = this->container.getPosition().x + this->container.getSize().x / 2.f - 150;
	//y = this->container.getPosition().y + this->container.getSize().y - 300.f + y;
	this->buttons[key] = new Button(x, y, 300, 80,
		&this->font, text, 40,
		sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));
}

void PauseMenu::update(const sf::Vector2i& mousePos)
{
	for (auto& i : this->buttons)
	{
		i.second->update(mousePos);
	}
}

void PauseMenu::render(sf::RenderTarget* target)
{
	target->draw(background);
	target->draw(container);

	for (auto &i : this->buttons)
	{
		i.second->render(*target);
	}

	target->draw(menuText);
}