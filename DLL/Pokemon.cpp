#include "Pokemon.hpp"


Pokemon::Pokemon(float x, float y, sf::Texture& texture_sheet, const std::string& name, int level, int hp, int attack, int defense, int speed, const std::vector<std::string>& moves) : name(name), level(level), maxHP(hp), currentHP(hp), attack(attack), defense(defense), speed(speed), moves(moves), exp(0), expToNextLevel(100 * level)
{
	this->initVariables();
	this->initComponents();
	this->setPosition(x, y);

	this->createMovement(0.f, 0.f, 0.f);
	this->createAnimationComponent(texture_sheet);

	this->animationComponent->addAnimation("IDLE_LEFT", 10.f, 0, 0, 0, 0, 258, 186);
}

Pokemon::~Pokemon()
{

}

void Pokemon::initVariables()
{

}

void Pokemon::initComponents()
{

}

const std::string& Pokemon::getName() const
{
	return name;
}

int Pokemon::getCurrentHP() const
{
	return currentHP;
}

int Pokemon::getMaxHP() const
{
	return maxHP;
}

int Pokemon::getAttack() const
{
	return attack;
}

int Pokemon::getDefense() const
{
	return defense;
}

int Pokemon::getSpeed() const
{
	return speed;
}

const std::vector<std::string>& Pokemon::getMoves() const
{
	return moves;
}

bool Pokemon::isFainted() const
{
	return currentHP <= 0;
}

void Pokemon::takeDamage(int damage)
{
	this->currentHP -= damage;
	if (this->currentHP < 0)
	{
		this->currentHP = 0;
	}
}

int Pokemon::calculateDamage(const Pokemon& opponent, const std::string& move) const
{
	float baseDamage = 15.0f;
	float attackDefenseRatio = static_cast<float>(this->attack) / opponent.getDefense();
	int damage = static_cast<int>(baseDamage * attackDefenseRatio);
	return damage;
}

void Pokemon::heal()
{
	currentHP = maxHP;
}

int Pokemon::getLevel() const
{
	return level;
}

int Pokemon::getExp() const
{
	return exp;
}

int Pokemon::getExpToNextLevel() const
{
	return expToNextLevel;
}

void Pokemon::gainExp(int amount)
{
	exp += amount;
	while (exp >= expToNextLevel)
	{
		exp -= expToNextLevel;
		levelUp();
	}
}

void Pokemon::levelUp()
{
	level++;

	maxHP += 10;
	attack += 3;
	defense += 3;
	speed += 2;

	expToNextLevel = 100 + (level * 50);

	std::cout << name << " awansowal na poziom " << level << "!" << std::endl;
}

void Pokemon::update(const float& deltaTime)
{
	if (this->movement->getState(IDLE))
	{
		this->animationComponent->play("IDLE_LEFT", deltaTime);
	}
}

void Pokemon::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}