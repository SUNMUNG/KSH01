#pragma once
#include <string>
class Animal
{
public:
	inline const float GetEnergy()const { return Energy; }
	inline const int GetAge()const { return age; }
	inline const std::string& GetName()const { return name; }

	Animal(std::string inname,float inEnergy,int inage);
	Animal(std::string inname);
	~Animal();
	void Move();
	void MakeSound();
	void Eat();
	void Sleep();
	void ShowInfo();
protected:
	inline void SetEnergy(float inEnergy)
	{
		if (inEnergy < 0) {
			Energy = 0.0f;
		}
		else if (inEnergy > 1.0f) {
			Energy = 1.0f;
		}
		else {
			Energy = inEnergy;
		}
		
	}
	inline void SetAge(int inAge)
	{
		age = inAge;
	}
	inline void SetAge(std::string& Name)
	{
		name = Name;
	}
	float Energy = 1.0f;
	std::string name = "";
	int age = 1;
};



