#pragma once
#include <string>
class Animal
{
public:

	std::string name = "";
	float Energy=1.0f;
	int age = 1;

	Animal(const char* inname,float inEnergy,int inage);
	~Animal();
	void Move();
	void MakeSound();
	void Eat();
	void Sleep();
	void ShowInfo();
private:

};



