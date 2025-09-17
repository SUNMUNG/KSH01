#pragma once
#include "Animal.h"
class Horse : public Animal
{
public:
	void Ride();
	virtual void MakeSound() override;
	virtual void Move() override;
public:
	Horse() = default;
	Horse(std::string inname)
		:Animal(inname)
	{
	}
};