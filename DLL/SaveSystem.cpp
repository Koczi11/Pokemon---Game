#include "SaveSystem.hpp"
#include <fstream>
#include <iostream>

bool SaveSystem::saveGame(const std::string& playerPokemon, int level, int exp, float playerX, float playerY)
{
	std::ofstream file("C:\\Users\\kacpe\\Desktop\\Projekt_JIPP\\proj\\Projekt_JIPP\\items\\save.dat", std::ios::binary);
	if (!file) return false;

	file << playerPokemon << "\n"
		<< level << "\n"
		<< exp << "\n"
		<< playerX << "\n"
		<< playerY << "\n";

	return file.good();
}

bool SaveSystem::loadGame(std::string& outPokemonName, int& outlevel, int& outexp, float& outplayerX, float& outplayerY)
{
	std::ifstream file("C:\\Users\\kacpe\\Desktop\\Projekt_JIPP\\proj\\Projekt_JIPP\\items\\save.dat", std::ios::binary);
	if (!file) return false;

	file >> outPokemonName
		>> outlevel
		>> outexp
		>> outplayerX
		>> outplayerY;

	return file.good();
}