#include "PokemonSelector.hpp"

PokemonSelector::PokemonSelector(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Color& color, const sf::Color& color2) : position(position), size(size), textureLoaded(false)
{
	shape.setSize(size);
	shape.setPosition(position);
	shape.setFillColor(color);
	shape.setOutlineColor(color2);
	shape.setOutlineThickness(5.f);
}

PokemonSelector::~PokemonSelector()
{

}

bool PokemonSelector::loadImage(const std::string& filename, const sf::Vector2f& imageposition)
{
	if (!texture.loadFromFile(filename))
	{
		textureLoaded = false;
		return false;
	}

	sprite.setTexture(texture);
	sprite.setPosition(position.x + imageposition.x, position.y + imageposition.y);

	textureLoaded = true;
	return true;
}

void PokemonSelector::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}