#include "State.hpp"

State::State(StateData* state_data)
{
	this->stateData = state_data;
	this->window = state_data->window;
	this->supportedKeys = state_data->supportedKeys;
	this->states = state_data->states;
	this->quit = false;
	this->paused = false;
	this->keyTime = 0.f;
	this->keyTimeMax = 10.f;
	this->gridSize = state_data->gridSize;

}	

State::~State()
{

}

const bool State::getKeyTime()
{
	if (this->keyTime >= this->keyTimeMax)
	{
		this->keyTime = 0.f;
		return true;
	}

	return false;
}

void State::endState()
{
	this->quit = true;
}

const bool& State::getQuit() const
{
	return this->quit;
}

void State::pauseState()
{
	this->paused = true;
}

void State::unpauseState()
{
	this->paused = false;
}

void State::updateMousePositions(sf::View* view)
{
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	
	if(view)
		this->window->setView(*view);

	this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
	this->mousePosGrid = sf::Vector2u(
		static_cast<unsigned>(this->mousePosView.x) / static_cast<unsigned>(this->gridSize),
		static_cast<unsigned>(this->mousePosView.y) / static_cast<unsigned>(this->gridSize)
	);

	this->window->setView(this->window->getDefaultView());
}

void State::updateKeyTime(const float& deltaTime)
{
	if (this->keyTime < this->keyTimeMax)
	{
		this->keyTime += 100.f * deltaTime;
	}
}