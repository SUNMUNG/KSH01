#pragma once
#include "Animal.h"
class Tiger : public Animal
{
public:
	void Hunt();
	virtual void Move() override;
	virtual void MakeSound() override;
public:
	Tiger() = default;
	Tiger(std::string inname)
		:Animal(inname)
	{
	}
	virtual ~Tiger() {}
};

