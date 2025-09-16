#include "Car.h"
#include <stdio.h>

Car::Car(const char* inname)
	:name(inname)
{
	printf("%s 자동차 : 생성\n",name.c_str());
	
}

Car::~Car()
{
	printf("%s 자동차 : 삭제\n",name.c_str());
}

void Car::Accel()
{
	printf("자동차 : 가속\n");
}

void Car::Brake()
{
	printf("자동차 : 감속\n");
}

void Car::HandleTurn()
{
	printf("자동차 : 핸들\n");
}
