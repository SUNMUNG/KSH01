#pragma once
#include <string>
class Car
{
public:
	std::string name = "";
	float speed = 0.0f;
	float fuel = 1.0f;

	Car(const char* inname);
	~Car();


	void Accel();
	void Brake();
	void HandleTurn();
};

