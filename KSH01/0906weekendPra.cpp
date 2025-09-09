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
		printf("%d", num % 2);
		num /= 2;
		return ToBinary(num);
	}
	else printf("0");
	//뒤집어 출력	
}

//슬롯 머신 게임 만들기
//시작 금액 10000
//한판에 무조건  최소 100 배팅해야 함.만약 소지금액이 100 이하일 경우 게임 종료.
//같은 숫자 3개가 나오면 50배로 돌려 받는다.
//만약 777이면 10000배 받음

void weekendPra8()
{
	SlotMachine();
}

void SlotMachine()
{
	srand(time(0));
	int PlayerMoney=10000;
	int RandomNumber1, RandomNumber2, RandomNumber3;
	int PlayerBatting=-1;

	

	while (PlayerMoney > 100) {
		printf("슬롯 머신 게임을 시작합니다.\n");

		printf("배팅할 금액을 입력해주세요.\n100이하의 숫자 입력시 다시입력\n");
		printf("현재 금액은 : %d\n", PlayerMoney);
		std::cin >> PlayerBatting;
		

		
		PlayerMoney -= PlayerBatting;
		RandomNumber1 = rand() % 9 + 1;
		RandomNumber2 = rand() % 9 + 1;
		RandomNumber3 = rand() % 9 + 1;

		if ((RandomNumber1 == 7) && (RandomNumber2 == 7) && (RandomNumber3 == 7)) {
			printf("럭키 !! \n");
			printf("나온 숫자 : %d %d %d\n", RandomNumber1, RandomNumber2, RandomNumber3);
			PlayerMoney += PlayerBatting * 10000;
		}
		else if (RandomNumber1 == RandomNumber2 == RandomNumber3) {
			printf("당첨되었습니다. \n");
			printf("나온 숫자 : %d %d %d\n", RandomNumber1, RandomNumber2, RandomNumber3);
			PlayerMoney += PlayerBatting * 50;
		}
		else {
			printf("당첨되지 않았습니다. \n");
			printf("나온 숫자 : %d %d %d\n", RandomNumber1, RandomNumber2, RandomNumber3);
		}


	}
		
}


//플레이어와 적의 턴제 전투 만들기
//HP는 100으로 시작
//공격을 할 때 상대방에게 5~15의 데미지를 준다.
//10 % 의 확률로 크리티컬이 발생해 2배의 데미지를 준다.
//상대방의 HP가 0 이하가 되면 승리한다.

void TurnBattle()
{
	srand(time(0));
	int PlayerHp = 100;
	int EnemyHp = 100;
	int PlayerDamage;
	int EnemyDamage;
	int PlayercritRate; // 0~9까지 굴려서 10개의 숫자 중 5면 1/10
	int EnemycritRate; // 0~9까지 굴려서 10개의 숫자 중 5면 1/10
	printf("턴제 전투 게임을 시작합니다.\n");
	printf("현재 나의 체력 : %d\n", PlayerHp);
	printf("현재 적의 체력 : %d\n", EnemyHp);

	printf("전투를 시작합니다. 엔터를 누르면 시작.\n");
	getchar();

	while (PlayerHp > 0 && EnemyHp > 0) {


		PlayerDamage = rand() % 11 + 5;
		EnemyDamage = rand() % 11 + 5;
		PlayercritRate = rand() % 10;
		EnemycritRate = rand() % 10;



		//플레이어 크리티컬 발생 유무
		if (PlayercritRate == 5) {
			PlayerDamage *= 2;
			printf("크리티컬이 발생하였습니다 : 플레이어\n");
		}


		// 체력이 음수로 떨어지는것 조정
		EnemyHp -= PlayerDamage;
		if (EnemyHp <= 0) {
			EnemyHp = 0;
		}
		printf("적 에게 %d 의 데미지를 주었습니다.\n", PlayerDamage);
		printf("적의 남은 HP : %d\n플레이어 남은 HP : %d\n", EnemyHp, PlayerHp);
		printf("계속하려면 엔터\n");
		getchar();

		if (PlayerHp <= 0) {
			printf("플레이어가 패배했습니다.\n");
			break;
		}
		else if (EnemyHp <= 0) {
			printf("플레이어가 승리했습니다.\n");
			break;
		}


		//적 크리티컬 발생 유무
		if (EnemycritRate == 5) {
			EnemyDamage *= 2;
			printf("크리티컬이 발생하였습니다 : 플레이어\n");
		}

		// 체력이 음수로 떨어지는것 조정
		PlayerHp -= EnemyDamage;
		if (PlayerHp <= 0) {
			PlayerHp = 0;
		}
		printf("플레이어가 %d 의 데미지를 받았습니다.\n", EnemyDamage);
		printf("적의 남은 HP : %d\n플레이어 남은 HP : %d\n", EnemyHp, PlayerHp);
		printf("계속하려면 엔터\n");
		getchar();

		if (PlayerHp <= 0) {
			printf("플레이어가 패배했습니다.\n");
			break;
		}
		else if (EnemyHp <= 0) {
			printf("플레이어가 승리했습니다.\n");
			break;
		}

	}





}

//도둑 잡기 만들기
//시작 금액 10000
//한판에 무조건 최소 100 배팅해야 함.만약 소지금액이 100 이하일 경우 게임 종료.
//딜러는 A~K까지의 트럼프 카드와 조커 카드 중 3장을 랜덤으로 뽑는다.(중복이 없어야 함)
// A 2 3 4 5 6 7 8 9 10 K Q J 조커
//플레이어는 딜러의 카드 중 한장을 선택한다.
//만약 플레이어가 조커를 뽑있다면 플레이어의 승리.배팅 금액의 2배를 받는다.
//플레이어가 조커를 뽑지 못했다면 다음 게임을 시작하거나 배팅 금액의 2배를 추가로 지불하고 한번 더 선택할 수 있다.

void weekendPra10()
{
	CardGame();
}

void CardGame()
{
	// A 2 3 4 5 6 7 8 9 10 K Q J 조커
	enum Card
	{
		A = 1,
		K = 11,
		Q = 12,
		J = 13,
		Joker = 14
	};

	srand(time(0));
	int PlayerMoney = 10000;
	int PlayerBatting = -1;
	int PlayerSelectCard;
	int PlayerSelectNumber;
	int DealerCard1=-1;
	int DealerCard2=-1;
	int DealerCard3=-1;
	int Jokerpick;

	printf("도둑잡기 게임을 시작합니다 . \n");

	while (PlayerMoney > 100) {
		printf("배팅할 금액을 입력해주세요.\n100이하의 숫자 입력시 다시입력\n");
		printf("현재 금액은 : %d\n", PlayerMoney);
		std::cin >> PlayerBatting;

		PlayerMoney -= PlayerBatting;

		Jokerpick = rand() % 3; //0,2이 조커X 1이 조커 // 1/3확률로 조커

		if (Jokerpick == 1) {
			DealerCard1 = Joker;
		}
		else
		{
			DealerCard1 = rand() % 13 + 1;
		}

		Jokerpick = rand() % 2;


		if (Jokerpick == 1 && DealerCard1 != Joker) {
			DealerCard2 = Joker;
		}
		else
		{
			DealerCard2 = rand() % 13 + 1;
		}

		do
		{
			if (DealerCard1 != Joker && DealerCard2 != Joker) {
				DealerCard3 = Joker;
			}
			else {
				DealerCard3 = rand() % 13 + 1;
			}
		} while (!((DealerCard2 != DealerCard3) && (DealerCard1 != DealerCard3)));

		printf("딜러가 뽑은 카드중 하나를 선택해주세요\n");
		printf("[1.첫번째 2.두번째 3.세번째]\n");
		std::cin >> PlayerSelectCard;

		if (PlayerSelectCard == 1 && DealerCard1 == Joker) {
			PlayerMoney += PlayerBatting * 2;
			printf("승리\n");
			printf("컴퓨터가 뽑은 카드: \n");
			CardPrint(DealerCard1);
			CardPrint(DealerCard2);
			CardPrint(DealerCard3);
			printf("번호를 선택해주세요 : \n");
			printf("[1.묻고 더블 2.여기서 끝]\n");
			std::cin >> PlayerSelectNumber;
			Regame(PlayerSelectNumber);
		}
		else if (PlayerSelectCard == 2 && DealerCard2 == Joker) {
			PlayerMoney += PlayerBatting * 2;
			printf("승리\n");
			printf("컴퓨터가 뽑은 카드: \n");
			CardPrint(DealerCard1);
			CardPrint(DealerCard2);
			CardPrint(DealerCard3);
			/*printf("번호를 선택해주세요 : \n");
			printf("[1.묻고 더블 2.여기서 끝]\n");
			std::cin >> PlayerSelectNumber;
			Regame(PlayerSelectNumber);*/
		}
		else if (PlayerSelectCard == 3 && DealerCard3 == Joker) {
			PlayerMoney += PlayerBatting * 2;
			printf("승리\n");
			printf("컴퓨터가 뽑은 카드: \n");
			CardPrint(DealerCard1);
			CardPrint(DealerCard2);
			CardPrint(DealerCard3);
		/*	printf("번호를 선택해주세요 : \n");
			printf("[1.묻고 더블 2.여기서 끝]\n");
			std::cin >> PlayerSelectNumber;
			Regame(PlayerSelectNumber);*/
		}
		else {
			printf("패배\n");
			printf("컴퓨터가 뽑은 카드: \n");
			CardPrint(DealerCard1);
			CardPrint(DealerCard2);
			CardPrint(DealerCard3);
		}

	}

	
}

void CardPrint(int DealerCard)
{

	if (DealerCard == 1) {
		printf("A ,\n");
	}
	else if (DealerCard == 11) {
		printf("K ,\n");
	}
	else if (DealerCard == 12) {
		printf("Q ,\n");
	}
	else if (DealerCard == 13) {
		printf("J ,\n");
	}
	else if (DealerCard == 14) {
		printf("Joker ,\n");
	}
	else {
		printf("%d ,\n", DealerCard);
	}
}

void Regame(int PlayerSelectNumber) {
	if (PlayerSelectNumber == 1) {

	}
	else {

	}
}