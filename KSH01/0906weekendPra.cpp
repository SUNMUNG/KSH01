#include "0906weekendpra.h"
#include <stdio.h>
#include <cstring>
#include <random>
#include <string>
#include <iostream>




//3개의 파라메터를 받아 평균값을 리턴하는 함수 만들기
void weekendPra1()
{
	int num1, num2, num3;
	printf("세 수를 입력하세요 : \n");
	std::cin >> num1 >> num2 >> num3;

	printf("평균은 %.2f 입니다.\n",Average(num1,num2,num3));

}

float Average(int num1, int num2, int num3)
{
	float avg = 0.0f;
	avg = (num1 + num2 + num3) / 3.0f;
	return avg;
}


//정가와 할인율 입력 받아 할인가 구하는 함수 만들기
void weekendPra2()
{
	int OriginalPrice;
	float SaleRate;
	printf("정가 와 할인율을 입력해주세요. \n");
	std::cin >> OriginalPrice;
	std::cin >> SaleRate;

	printf("할인가는 %d 입니다. \n",SalePrice(OriginalPrice, SaleRate));

}

int SalePrice(int OriginalPrice, float SaleRate)
{
	int saleprice = 0;
	saleprice = OriginalPrice * SaleRate;
	return saleprice;
}



//주사위를 굴린 결과를 리턴하는 함수 만들기

void weekendPra3()
{
	srand(time(0));
	printf("주사위를 굴립니다.\n");
	printf("굴린결과는 ..  %d",RollDice());

}

int RollDice()
{
	int Dice=-1;
	Dice = rand() % 6 + 1;
	return Dice;
}



//점수를 주면 성적(A~F)를 주는 함수 만들기

void weekendPra4()
{
	int Score;
	printf("점수를 입력하세요 \n");
	std::cin >> Score;
	printf("성적은 %c 입니다\n",RankDecide(Score));
}

char RankDecide(int score)
{
	if (score >= 90) {
		return 'A';
	}
	else if (score >= 80) {
		return 'B';
	}
	else if (score >= 70) {
		return 'C';
	}
	else if (score >= 60) {
		return 'D';
	}
	else if (score >= 60) {
		return 'E';
	}
	else {
		return 'F';
	}
}



//템플릿 함수로 Clamp 함수 구현하기

void weekendPra5()
{
}

//자리수 분리하기(입력은 자리 수 제한 없음)
//각 자리의 수를 합해서 출력하기
void weekendPra6()
{
	int Number;
	printf("수를 입력하세요 \n");
	std::cin >> Number;
	printf("%d", DivideSum(Number));

}

int DivideSum(int Number)
{
	int sum = 0;
	int divideNumber = 1;
	while (Number > divideNumber) {
		sum += Number % divideNumber;
		divideNumber *= 10;
	}

	return sum;
}



//재귀 함수를 이용하여 10진수를 입력받아 2진수로 출력하는 함수 만들기
void weekendPra7()
{
	int Number;
	printf("수를 입력하세요 \n");
	std::cin >> Number;

	ToBinary(Number);
}

int ToBinary(int num)
{
	if (num >= 1) {
		printf("%d", num%2);
		num /= 2;
		return ToBinary(num);
	}
	else printf("0");
    //뒤집어 출력	
}

void weekendPra8()
{
	SlotMachine();
}

void SlotMachine()
{
	srand(time(0));
	int PlayerMoney=10000;
	int RandomNumber1, RandomNumber2, RandomNumber3;
	int PlayerBatting;

	RandomNumber1 = rand() % 9 + 1;
	RandomNumber2 = rand() % 9 + 1;
	RandomNumber3 = rand() % 9 + 1;

		printf("슬롯 머신 게임을 시작합니다.\n");
		printf("배팅할 금액을 입력해주세요.\n");
		std::cin >> PlayerBatting;
		PlayerMoney-= PlayerBatting;

		if ((RandomNumber1 == 7) && (RandomNumber2 == 7) && (RandomNumber3 == 7)) {
			PlayerMoney += PlayerBatting * 50;
		}


}


//슬롯 머신 게임 만들기
//시작 금액 10000
//한판에 무조건  최소 100 배팅해야 함.만약 소지금액이 100 이하일 경우 게임 종료.
//같은 숫자 3개가 나오면 50배로 돌려 받는다.
//만약 777이면 10000배 받음

//플레이어와 적의 턴제 전투 만들기
//HP는 100으로 시작
//공격을 할 때 상대방에게 5~15의 데미지를 준다.
//10 % 의 확률로 크리티컬이 발생해 2배의 데미지를 준다.
//상대방의 HP가 0 이하가 되면 승리한다.

//도둑 잡기 만들기
//시작 금액 10000
//한판에 무조건 최소 100 배팅해야 함.만약 소지금액이 100 이하일 경우 게임 종료.
//딜러는 A~K까지의 트럼프 카드와 조커 카드 중 3장을 랜덤으로 뽑는다.(중복이 없어야 함)
// A 1 2 3 4 5 6 7 8 9 K Q J 조커
//플레이어는 딜러의 카드 중 한장을 선택한다.
//만약 플레이어가 조커를 뽑있다면 플레이어의 승리.배팅 금액의 2배를 받는다.
//플레이어가 조커를 뽑지 못했다면 다음 게임을 시작하거나 배팅 금액의 2배를 추가로 지불하고 한번 더 선택할 수 있다.


