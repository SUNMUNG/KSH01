#pragma once
#include "Animal.h"
class Tiger : public Animal
{
public:
	void Hunt();
public:
	Tiger() = default;
	Tiger(std::string inname)
		:Animal(inname)
	{
	}
};

