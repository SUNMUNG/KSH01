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
			printf("해당하는 문자가 있습니다.\n");
			printf("%d 번째 에 있습니다.\n", number);
		}

		number++;
	}
}

//문자열의 길이를 측정하는 함수 만들기
//int MyStringLength(const char* Target);
void practice09102()
{
	char HelloString[] = "Hello String";
	printf("배열의 길이는 %d 입니다.",MyStringLength(HelloString));
}

int MyStringLength(char* Target)
{
	int length = 0;


	while (Target[length] != '\0') {
		length++;
	}


	return length+1;
}

//문자열을 복사하는 함수 만들기
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
//문자열을 합치는 함수 만들기(Source 뒤에 Destination의 내용을 붙이기)
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
//문자열 두개를 비교하는 함수 만들기
//리턴 값이 두 문자열이 같으면 0, 첫번째가 작으면 음수, 두번째가 작으면 양수
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
//문자열을 입력 받아 정수를 리턴하는 함수 만들기
//int MyAtoI(const char* Source);

void practice09106()
{
	char String[100] = "";

	printf("문자열을 입력해주세요 : \n");

	std::cin >> String;
}
int MyAtoI(const char* Source)
{
	return 0;
}
//문자열을 입력 받아 실수를 리턴하는 함수 만들기
//float MyAtoF(const char* Source);
void practice09107()
{

}

float MyAtoF(const char* Source)
{
	return 0.0f;
}
