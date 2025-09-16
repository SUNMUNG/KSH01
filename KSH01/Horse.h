#pragma once
#include "Animal.h"
class Horse : public Animal
{
public:
	void Ride();
public:
	Horse() = default;
	Horse(std::string inname)
		:Animal(inname)
	{
	}
};