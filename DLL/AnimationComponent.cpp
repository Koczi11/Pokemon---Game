#include "AnimationComponent.hpp"

AnimationComponent::AnimationComponent(sf::Sprite& sprite, sf::Texture& textrue_sheet) : sprite(sprite), textureSheet(textrue_sheet)
{
	
}

AnimationComponent::~AnimationComponent()
{
	for (auto& i : this->animations)
	{
		delete i.second;
	}
}

void AnimationComponent::addAnimation(const std::string key, float animation_timer, float start_frame_x, float start_frame_y, float frames_x, float frames_y, float width, float height)
{
	this->animations[key] = new Animation(this->sprite, this->textureSheet, animation_timer, start_frame_x, start_frame_y, frames_x, frames_y, width, height);
}

void AnimationComponent::play(const std::string key, const float& deltaTime)
{
	this->animations[key]->play(deltaTime);
}