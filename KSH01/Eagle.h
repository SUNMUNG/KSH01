#pragma once
#include "Animal.h"
#include "IFlyable.h"
class Eagle : public Animal,public IFlyable
{
public:
	virtual void Move() override;
	virtual void MakeSound() override;
	virtual void Fly() override;

public:
	Eagle() = default;
	Eagle(std::string inname)
		:Animal(inname)
	{
	}
	virtual ~Eagle(){}
};