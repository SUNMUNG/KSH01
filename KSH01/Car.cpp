#include "Car.h"
#include <stdio.h>

Car::Car(const char* inname)
	:name(inname)
{
	printf("%s �ڵ��� : ����\n",name.c_str());
	
}

Car::~Car()
{
	printf("%s �ڵ��� : ����\n",name.c_str());
}

void Car::Accel()
{
	printf("�ڵ��� : ����\n");
}

void Car::Brake()
{
	printf("�ڵ��� : ����\n");
}

void Car::HandleTurn()
{
	printf("�ڵ��� : �ڵ�\n");
}
