#pragma once

#ifndef SAVESYSTEM_H
#define SAVESYSTEM_H

#include <string>
#include <unordered_map>
#include "API.h"

class EXPORT_API SaveSystem
{
public:
	static bool saveGame(const std::string& playerPokemon, int level, int exp, float playerX, float playerY);
	static bool loadGame(std::string& outPokemonName, int& outlevel, int& outexp, float& outplayerX, float& outplayerY);
};

#endif