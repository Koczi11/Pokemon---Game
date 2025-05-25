#pragma once

#ifndef POKEMON_H
#define POKEMON_H

#include "Entity.hpp"


class EXPORT_API Pokemon : public Entity
{
private:
	void initVariables();
	void initComponents();

	std::string name;
	int maxHP;
	int currentHP;
	int attack;
	int defense;
	int speed;

	std::vector<std::string> moves;

	int level;
	int exp;
	int expToNextLevel;

public:
	Pokemon(float x, float y, sf::Texture& texture_sheet, const std::string& name, int level, int hp, int attack, int defense, int speed, const std::vector<std::string>& moves);
	virtual ~Pokemon();

	const std::string& getName() const;
	int getCurrentHP() const;
	int getMaxHP() const;
	int getAttack() const;
	int getDefense() const;
	int getSpeed() const;
	const std::vector<std::string>& getMoves() const;

	bool isFainted() const;

	void takeDamage(int damage);
	int calculateDamage(const Pokemon& opponent, const std::string& move) const;
	void heal();

	int getLevel() const;
	int getExp() const;
	int getExpToNextLevel() const;
	void gainExp(int amount);
	void levelUp();

	void update(const float& deltaTime);
	void render(sf::RenderTarget& target);
};


#endif