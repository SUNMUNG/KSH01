#pragma once
#include "Animal.h"
class Eagle : public Animal
{
public:
	void Fly();
public:
	Eagle() = default;
	Eagle(std::string inname)
		:Animal(inname)
	{
	}
};