#include "practice0910.h"
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <random>
#include <string>
#include <limits.h>

void practice09101()
{
	char HelloString[]="Hello String";
	char c;
	std::cin >> c;
	isFindChar(HelloString, c);
	
}

void isFindChar(char* HelloStr, int c)
{
	int number = 0;

	while (HelloStr[number] != '\0') {
		if (HelloStr[number] == c) {
			printf("�ش��ϴ� ���ڰ� �ֽ��ϴ�.\n");
			printf("%d ��° �� �ֽ��ϴ�.\n", number);
		}

		number++;
	}
}

//���ڿ��� ���̸� �����ϴ� �Լ� �����
//int MyStringLength(const char* Target);
void practice09102()
{
	char HelloString[] = "Hello String";
	printf("�迭�� ���̴� %d �Դϴ�.",MyStringLength(HelloString));
}

int MyStringLength(char* Target)
{
	int length = 0;


	while (Target[length] != '\0') {
		length++;
	}


	return length+1;
}

//���ڿ��� �����ϴ� �Լ� �����
//void MyStringCopy(const char* Source, char* Destination);

void practice09103()
{
	int count = 0;
	char Source[] = "Hello String";
	char Destination[] = "";

	MyStringCopy(Source, Destination);

	
	for (int i = 0; i < 13; i++) {
		if (Destination[i] != '\0') {
			printf("%c", Destination[i]);
		}
	}
	
}

void MyStringCopy(char* Source, char* Destination)
{
	int length = 0;
	while (Source[length] != '\0') {
		Destination[length] = Source[length];
		length++;
	}
	Destination[length] = '\0';

}
//���ڿ��� ��ġ�� �Լ� �����(Source �ڿ� Destination�� ������ ���̱�)
//void MyStringCat(char* Source, const char* Destination);

void practice09104()
{
	char Source[] = "Hello";
	char Destination[] = " String";

	MyStringCat(Source, Destination);

}

void MyStringCat(char* Source, char* Destination)
{
	int Slength = 0;
	int Dlength = 0;
	int TotalLen = 0;
	int count=0;

	while (Source[Slength] != '\0') {
		Slength++;
	}
	while (Destination[Dlength] != '\0') {
		Dlength++;
	}
	TotalLen = Slength + Dlength;

	for (int i = Slength; i < TotalLen; i++) {
		Source[i] = Destination[count];
		count++;
	}
	Source[TotalLen] = '\0';


	for (int i = 0; i < TotalLen; i++) {
		if (Source[i] != '\0') {
			printf("%c", Source[i]);
		}
	}



}
//���ڿ� �ΰ��� ���ϴ� �Լ� �����
//���� ���� �� ���ڿ��� ������ 0, ù��°�� ������ ����, �ι�°�� ������ ���
//int MyStringCompare(const char* String1, const char* string2);

void practice09105()
{
	char String1[] = "Hello";
	char String2[] = "Hello";
	char String3[] = "Hea";
	char String4[] = "Hez";

	printf("%d", MyStringCompare(String1, String2)); //0
	printf("%d", MyStringCompare(String1, String3)); //1  65+@ >65
	printf("%d", MyStringCompare(String1, String4)); //-1 65+@ < z

}
int MyStringCompare(const char* String1, const char* String2)
{
	int length = 0;

	while (String1[length] != '\0') {
		if (String1[length] != String2[length]) {
			if (String1[length] > String2[length]) {
				return 1;
			}
			else {
				return -1;
			}
		}
		length++;
	}

	return 0;
}
//���ڿ��� �Է� �޾� ������ �����ϴ� �Լ� �����
//int MyAtoI(const char* Source);

void practice09106()
{
	char String[100] = "";

	printf("���ڿ��� �Է����ּ��� : \n");

	std::cin >> String;
}
int MyAtoI(const char* Source)
{
	return 0;
}
//���ڿ��� �Է� �޾� �Ǽ��� �����ϴ� �Լ� �����
//float MyAtoF(const char* Source);
void practice09107()
{

}

float MyAtoF(const char* Source)
{
	return 0.0f;
}
