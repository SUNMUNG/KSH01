#include "Animal.h"
#include <stdio.h>

Animal::Animal(std::string inname)
	:name(inname)
{
	printf("%s : 동물이 생성되었습니다.\n", name.c_str());
}

Animal::Animal(std::string inname, float inEnergy, int inage)
	:name(inname),Energy(inEnergy),age(inage)
{
	printf("%s : 동물이 생성되었습니다.\n",name.c_str());
	printf("에너지 : %.0f\n나이 : %d\n",Energy*100,age);
	printf("----------------------------\n");
}

Animal::~Animal()
{
	printf("%s : 동물이 삭제되었습니다.\n",name.c_str());
	printf("----------------------------\n");
}

//void Animal::Move()
//{
//	if (Energy < 0.1f) {
//		printf("%s : 동물\n", name.c_str());
//		printf("에너지가 부족해 움직일 수 없습니다. : %.0f\n", Energy * 100);
//	}
//	else {
//		printf("%s : 동물이 움직였습니다.\n", name.c_str());
//		SetEnergy(Energy - 0.1f);
//		printf("에너지를 소비했습니다 : %.0f\n", Energy * 100);
//	}
//	
//	printf("----------------------------\n");
//}

void Animal::MakeSound()
{
	printf("%s : 동물이 소리를 질렀습니다.\n",name.c_str());
	printf("----------------------------\n");
}

void Animal::Eat()
{
	
	printf("%s : 동물이 음식을 먹었습니다.\n",name.c_str());
	SetEnergy(Energy + 0.3f);
	printf("에너지가 회복되었습니다 : %.0f\n",Energy * 100);
	printf("----------------------------\n");
}

void Animal::Sleep()
{
	printf("%s : 동물이 잠을 잤습니다.\n",name.c_str());
	SetAge(age + 1);
	SetEnergy(1.0f);
	printf("나이가 증가했습니다. : %d\n", age);
	printf("에너지가 전부 회복되었습니다. : %.0f\n",Energy * 100);
	printf("----------------------------\n");

}

void Animal::ShowInfo()
{
	printf("동물의 정보를 출력합니다.\n");
	printf("----------------------------\n");
	printf("%s : 동물의 이름\n",name.c_str());
	printf("에너지 : %.0f\n나이 : %d\n",Energy * 100,age);
	printf("----------------------------\n");
}
