#include "Animal.h"
#include <stdio.h>

Animal::Animal(std::string inname)
	:name(inname)
{
	printf("%s : ������ �����Ǿ����ϴ�.\n", name.c_str());
}

Animal::Animal(std::string inname, float inEnergy, int inage)
	:name(inname),Energy(inEnergy),age(inage)
{
	printf("%s : ������ �����Ǿ����ϴ�.\n",name.c_str());
	printf("������ : %.0f\n���� : %d\n",Energy*100,age);
	printf("----------------------------\n");
}

Animal::~Animal()
{
	printf("%s : ������ �����Ǿ����ϴ�.\n",name.c_str());
	printf("----------------------------\n");
}

//void Animal::Move()
//{
//	if (Energy < 0.1f) {
//		printf("%s : ����\n", name.c_str());
//		printf("�������� ������ ������ �� �����ϴ�. : %.0f\n", Energy * 100);
//	}
//	else {
//		printf("%s : ������ ���������ϴ�.\n", name.c_str());
//		SetEnergy(Energy - 0.1f);
//		printf("�������� �Һ��߽��ϴ� : %.0f\n", Energy * 100);
//	}
//	
//	printf("----------------------------\n");
//}

void Animal::MakeSound()
{
	printf("%s : ������ �Ҹ��� �������ϴ�.\n",name.c_str());
	printf("----------------------------\n");
}

void Animal::Eat()
{
	
	printf("%s : ������ ������ �Ծ����ϴ�.\n",name.c_str());
	SetEnergy(Energy + 0.3f);
	printf("�������� ȸ���Ǿ����ϴ� : %.0f\n",Energy * 100);
	printf("----------------------------\n");
}

void Animal::Sleep()
{
	printf("%s : ������ ���� ����ϴ�.\n",name.c_str());
	SetAge(age + 1);
	SetEnergy(1.0f);
	printf("���̰� �����߽��ϴ�. : %d\n", age);
	printf("�������� ���� ȸ���Ǿ����ϴ�. : %.0f\n",Energy * 100);
	printf("----------------------------\n");

}

void Animal::ShowInfo()
{
	printf("������ ������ ����մϴ�.\n");
	printf("----------------------------\n");
	printf("%s : ������ �̸�\n",name.c_str());
	printf("������ : %.0f\n���� : %d\n",Energy * 100,age);
	printf("----------------------------\n");
}
