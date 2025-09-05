#include "practice_0905.h"
#include <stdio.h>
#include <cstring>
#include <random>
#include <string>
#include <iostream>

//특정 범위안의 랜덤한 수를 리턴하는 함수
//int 파라메터가 2개
//int 리턴
int Random_int_Return(int minRange, int maxRange)
{
	srand(time(0));
	int Random_Number = rand() % (maxRange - minRange + 1)+minRange;

	return Random_Number;
}
void practice_0905_1()
{
	printf("%d\n",Random_int_Return(1, 10));
}

//“당신의 나이를 입력해 주세요 : “ → “당신은 00살 입니다”
//int 파라메터 1개


void practice_0905_2()
{
	int age;
	printf("당신의 나이를 입력해 주세요 : \n");
	std::cin >> age;

	YourAge(age);

}

int YourAge(int age)
{
	printf("당신은 %d살 입니다.",age);

	return 0;
	
}

//원의 반지름을 입력 받고 넓이 구하기
//float 파라메터 1개
//float 리턴

void practice_0905_3()
{
	int radius;
	printf("반지름을 입력해주세요 : \n");
	std::cin >> radius;

	printf("원의 넓이는 %.2f 입니다\n",CircleResult(radius));
}

float CircleResult(float radius)
{
	float res = 0.0f;

	res = radius * radius * 3.141592f;

	return res;
}



//숫자를 입력받아 홀수인지 짝수인지 판단하는 함수
//int 파라메터 1개
//bool 리턴(true면 홀수, false면 짝수)

void practice_0905_4()
{
	int OddEven_Num;
	printf("수를 입력해주세요 : \n");
	std::cin >> OddEven_Num;

	if (OddEvenResult(OddEven_Num) == true) {
		printf("홀수 입니다.\n");
	}
	else {
		printf("짝수 입니다.\n");
	}
	
}

bool OddEvenResult(int OddEven_Num)
{
	if (OddEven_Num % 2 != 0) {
		return true;
	}

	return false;
}



//성적 분류 함수(A~F)
//int 파라메터 1개
//int 리턴(enum값)

void practice_0905_5()
{
	int Student_Score;
	printf("점수를 입력해주세요 : \n");
	std::cin >> Student_Score;
	switch (RankSelect(Student_Score)) {
		case 0:
			printf("등급은 A입니다.\n");
			break;
		case 1:
			printf("등급은 B입니다.\n");
			break;
		case 2:
			printf("등급은 C입니다.\n");
			break;
		case 3:
			printf("등급은 D입니다.\n");
			break;
		case 4:
			printf("등급은 E입니다.\n");
			break;
		case 5:
			printf("등급은 F입니다.\n");
			break;
		default:
			printf("오류입니다.\n");
	}
	
}

int RankSelect(int score)
{
	enum Rank
	{
		A,
		B,
		C,
		D,
		E,
		F
	};

	if (score >= 90) {
		return A;
	}
	else if (score >= 80) {
		return B;
	}
	else if (score >= 70) {
		return C;
	}
	else if (score >= 60) {
		return D;
	}
	else if (score >= 50) {
		return E;
	}
	else{
		return F;
	}



	return 0;
}

//아이템 설정, 아이템 해제, 아이템 토글용 함수 총 3개
//비트 플래그 인벤토리 코드 수정
//int 파라메터 두개(Inventory, 비트플래그용 enum)



void practice_0905_6()
{
	int PlayerSelectNumber=-1;
	int PlayerItemSelectNumber = -1;
	int PlayerInventory=0;
	enum Item_List
	{
		Axe = 1,
		Evidence =2,
		Flash =3,
		Wirelessset=4
	};

	while (PlayerSelectNumber < 5) {
		printf("메뉴를 보고 숫자를 입력해주세요 .\n");
		printf("[ 1.아이템 설정 2. 아이템 해제 3.아이템 토글 4.인벤토리 확인 5.종료 ] .\n");
		std::cin >> PlayerSelectNumber;

		switch (PlayerSelectNumber) {
			case 1: 
				printf("아이템을 설정합니다\n");
				printf("[ 1.도끼 2.증거 3.플래쉬 4.무전기 ] .\n");
				std::cin >> PlayerItemSelectNumber;
				PlayerInventory = ItemInventoryAdd(PlayerInventory,PlayerItemSelectNumber);
				break;
			case 2:
				printf("아이템을 해제합니다\n");
				printf("[ 1.도끼 2.증거 3.플래쉬 4.무전기 ] .\n");
				std::cin >> PlayerItemSelectNumber;
				PlayerInventory = ItemInventoryDelete(PlayerInventory,PlayerItemSelectNumber);
				break;
			case 3:
				printf("아이템을 토글합니다\n");
				printf("[ 1.도끼 2.증거 3.플래쉬 4.무전기 ] .\n");
				std::cin >> PlayerItemSelectNumber;
				PlayerInventory =ItemInventoryToggle(PlayerInventory,PlayerItemSelectNumber);
				break;
			case 4:printf("현재 인벤토리의 아이템은 .. %d\n",PlayerInventory);
			default:
				break;

		}
	}

}

int ItemInventoryAdd(int PlayerInventory, int ItemNum)
{
	int playerinv = 0;

	switch (ItemNum) {
		case 1:  (playerinv = PlayerInventory |1); //0000 | 0001
			break;
		case 2: (playerinv = PlayerInventory |2); //0000 | 0010
			break;
		case 3:  (playerinv = PlayerInventory |4); //0000 | 0100
			break;
		case 4: (playerinv = PlayerInventory |8); //0000| 1000
			break;
		default: printf("해당하는 번호의 아이템이 없습니다..\n");
			break;
	}
	
	printf("아이템 추가를 완료했습니다.\n");
	return playerinv;
}	

int ItemInventoryDelete(int PlayerInventory, int ItemNum)
{
	int playerinv = 0;

	switch (ItemNum) {
	case 1:  (playerinv = PlayerInventory - 0b0001); 
		break;
	case 2: (playerinv = PlayerInventory - 0b0010); //0110 & 0010 
		break;
	case 3:  (playerinv = PlayerInventory - 0b0100);//0110 & 0100  = 0010
		break;
	case 4: (playerinv = PlayerInventory - 0b1000);
		break;
	default: printf("해당하는 번호의 아이템이 없습니다..\n");
		break;
	}

	printf("아이템 제거를 완료했습니다.\n");
	return playerinv;
}

int ItemInventoryToggle(int PlayerInventory, int ItemNum)
{
	int playerinv = 0;

	switch (ItemNum) {
	case 1:  (playerinv = PlayerInventory ^ 1);
		break;
	case 2: (playerinv = PlayerInventory ^ 2);
		break;
	case 3:  (playerinv = PlayerInventory ^ 4);
		break;
	case 4: (playerinv = PlayerInventory ^ 8);
		break;
	default: printf("해당하는 번호의 아이템이 없습니다..\n");
		break;
	}


	printf("아이템 토글을 완료했습니다.\n");
	return playerinv;
}

//피라미드 출력 함수
//int 파라메터 1개

void practice_0905_7()
{
	int Pyramid_Num;
	printf("층수를 입력해주세요 : \n");
	std::cin >> Pyramid_Num;

	PyramidMake(Pyramid_Num);

}

void PyramidMake(int num)
{
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num-i; j++) {
			printf(" ");
		}
		for (int k = 0; k < 2 * i + 1; k++) {
			printf("*");
		}
		printf("\n");
	}
}

void practice09059()
{	
	int FactorialNumber;
	printf("몇 팩토리얼을 구할까요? : \n");
	std::cin >> FactorialNumber;

	printf("%d", Factorial(FactorialNumber));
}
int res=1;
int Factorial(int num) {
	if (num == 1) return 1;
	else return num * Factorial(num - 1);
}

//재귀함수를 이용해서 팩토리얼 값을 만드는 함수 만들기
//5팩토리얼 = 5 * 4 * 3 * 2 * 1


