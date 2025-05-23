#pragma once

#ifndef POKEMON_H
#define POKEMON_H

#include "Entity.hpp"


class EXPORT_API Pokemon : public Entity
{
private:

public:
	Pokemon(const std::string& name, const std::string& texturePath);
	virtual ~Pokemon();
};


#endif