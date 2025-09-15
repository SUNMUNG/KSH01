#define _CRTDBG_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#define new new(_NORMAL_BLOCK,__FILE__,__LINE__)
#include <crtdbg.h>
#include <stdio.h>
#include <cstring>
#include <random>
#include <string>
#include <iostream>
#include "weekendpra0912.h"

const int MaxHand = 12;

void weekendpra09121()
{
	Date date;
	int days = 0;
	int YearDays = 0;
	printf("현재는 %d년 %d월 %d일 %d요일 입니다 .\n",date.year,date.month,date.day,date.weekday);

	printf("몇일 뒤의 날짜를 볼까요? : \n");

	std::cin >> days;
					
	while (1)
	{
		date.year++;
		if (date.year % 400 == 0) {
			if (YearDays+366 > days)break;
			YearDays += 366;
		}
		else if ((date.year % 4 == 0) && (date.year % 100 != 0)) {
			if (YearDays+366 > days)break;
			YearDays += 366;
		}
		else {
			if (YearDays+365 > days)break;
			YearDays += 365;
		}

		
	}
	date.year-=1;
	days = days - YearDays;

	

	//년수 계산하고 남은 일수중에서 월일
	for (int i = 1; i <= 12; i++) {
		if (i==4||i==6||i==9) {
			if (days<= 30) {
				date.month = i;
				break;
			}
			else {
				days -= 30;
			}
			
		}
		else if (i == 2) {
			if (days <= 28) {
				date.month = i;
				break;
			}
			else {
				days -= 28;
			}
		}
		else {
			if (days <= 31) {
				date.month = i;
				break;
			}
			else {
				days -= 31;
			}
		}

	}

	date.day = days;
	
	printf("입력하신 일수 뒤의 날짜는 \n%d년 %d월 %d일", date.year, date.month, date.day);

	switch (days%7)
	{
		case 0: printf(" 월요일 입니다 .");
			break;
		case 1: printf(" 화요일 입니다 .");
			break;
		case 2: printf(" 수요일 입니다 .");
			break;
		case 3: printf(" 목요일 입니다 .");
			break;
		case 4: printf(" 금요일 입니다 .");
			break;
		case 5: printf(" 토요일 입니다 .");
			break;
		case 6: printf(" 일요일 입니다 .");
			break;
		default:
			break;
	}
	
	 
	
	
	


}

void weekendpra09122()
{
	
	PlayGame();
	
}

void CardList(Card* List)
{
	const char Shape[4] = { 'S','H','D','C' };
	int Index = 0;
	for (int value = 0; value < 13; value++) {
		for (int shape = 0; shape < 4; shape++) {
			List[Index].Value = value + 1;
			List[Index].Shape= Shape[shape];
			Index++;
		}
	}

}

void shuffle(Card* List)
{
	for (int i = 51; i > 0; i--) {
		int j = rand() % (i + 1);
		Card Temp = List[i];
		List[i] = List[j];
		List[j] = Temp;
	}
}

const Card& DrawCard(Card* List, int& intop)
{
	if (intop >= 52) {
		shuffle(List);
		intop = 0;
	}
	return List[intop++];
}

void AddCardtoHand(Card* inhand, int& count, const Card& card)
{
	if (count < MaxHand)
	{
		inhand[count] = card;
		count++;
	}
}

//게임 목표
//두 카드의 합이 21에 가깝게 만들되, 21을 넘지 않는 것이 목표
//21을 초과하면(버스트, Bust) 즉시 패배
//배팅은 없음
//
//카드의 값
//2~10: 카드 숫자 그대로 점수.
//J(잭), Q(퀸), K(킹) : 각각 10점.
//A(에이스) : 1점 또는 11점(유리한 쪽으로 자동 선택).
//
//게임 진행 절차
//1) 초기 배분
//딜러와 플레이어 모두 2장씩 카드를 받음.
//플레이어의 카드는 두 장 모두 공개.
//딜러는 한 장은 공개(오픈 카드), 한 장은 비공개(홀 카드).
//
//2) 플레이어 턴
//플레이어가 먼저 행동.
//선택지:
//Hit(히트) : 카드를 한 장 더 받음.
//Stand(스탠드) : 더 이상 카드를 받지 않고 멈춤.
//플레이어가 21을 초과하면(버스트) 즉시 패배.
//
//3) 딜러 턴
//플레이어가 스탠드를 하면 딜러 차례.
//딜러는 자신의 카드 합이 17 이상이 될 때까지 계속 히트(카드 받기)해야 함.
//A가 포함된 "소프트 17"(A + 6 = 7 또는 17)도 멈춤.
//17 이상이면 멈추고, 21을 넘으면 딜러 패배.
//
//4) 승패 판정
//버스트가 아닌 경우, 점수 비교.
//플레이어가 21에 더 가까우면 승리.
//동점이면 무승부(Push).
//딜러가 더 가까우면 패배.
//블랙잭: 처음 받은 두 장이 A + 10(또는 J, Q, K)이면 블랙잭.일반적으로 블랙잭이 단순 21점보다 우선함.
void PlayGame()
{
	Card card[52];
	int DeckTop = 0;
	CardList(card);

	shuffle(card);
	int PlayerScore = 0;
	int DealerScore = 0;
	Card DealerCard[MaxHand];
	int Dealercount=0;
	Card PlayerCard[MaxHand];
	int Playercount=0;
	AddCardtoHand(PlayerCard, Playercount, DrawCard(card, DeckTop));
	AddCardtoHand(PlayerCard, Playercount, DrawCard(card, DeckTop));
	AddCardtoHand(DealerCard, Dealercount, DrawCard(card, DeckTop));
	AddCardtoHand(DealerCard, Dealercount, DrawCard(card, DeckTop));

	PrintHands(PlayerCard, Playercount, DealerCard, Dealercount, false);
	printf("--------------------------------\n");

	bool IsPlayerBlackJack = isBlackJack(PlayerCard, Playercount);
	bool IsDealerBlackJack = isBlackJack(DealerCard, Dealercount);

	if (IsPlayerBlackJack && IsDealerBlackJack) {
		printf("무승부 : 블랙잭\n");
		PrintHands(PlayerCard, Playercount, DealerCard, Dealercount, true);
	}
	else if (IsPlayerBlackJack) {
		printf("플레이어 : 블랙잭\n");
		PrintHands(PlayerCard, Playercount, DealerCard, Dealercount, true);
	}
	else if (IsDealerBlackJack) {
		printf("딜러 : 블랙잭\n");
		PrintHands(PlayerCard, Playercount, DealerCard, Dealercount, true);
	}
	else {
		bool isPlayerStand = false;
		while (!isPlayerStand && !isBurst(PlayerCard, Playercount))
		{
			printf("플레이어 점수 : %d\n", GetBestScore(PlayerCard, Playercount));
			printf("Hit(1) / Stand(2)?  : \n");
			int Input = 0;
			std::cin >> Input;
			printf("--------------------------------\n");
			if (Input == 1) {
				AddCardtoHand(PlayerCard, Playercount, DrawCard(card, DeckTop));
				PrintHands(PlayerCard, Playercount, DealerCard, Dealercount, false);
				if (isBurst(PlayerCard, Playercount)) {
					printf("플레이어 : 버스트! 패배\n");
					PlayerScore = GetBestScore(PlayerCard, Playercount);
					DealerScore = GetBestScore(DealerCard, Dealercount);
					PrintHands(PlayerCard, Playercount, DealerCard, Dealercount, true);
					printf("플레이어 점수 : %d\n", PlayerScore);
					printf("딜러 점수 : %d\n", DealerScore);
					return;
				}
			}
			else {
				isPlayerStand = true;
			}
			
			printf("딜러 턴 시작 \n");
			printf("--------------------------------\n");
			PrintHands(PlayerCard, Playercount, DealerCard, Dealercount, true);
			while (GetBestScore(DealerCard,Dealercount)<17)
			{
				if (isSoft17(DealerCard, Dealercount)) {
					break;
				}
				AddCardtoHand(DealerCard, Dealercount, DrawCard(card, DeckTop));
				printf("딜러 카드 : ");
				PrintDealerHand(DealerCard, Dealercount, true);
				printf("\n");

				if (isBurst(DealerCard, Dealercount)) {
					printf("딜러 : 버스트\n");
					PlayerScore = GetBestScore(PlayerCard, Playercount);
					DealerScore = GetBestScore(DealerCard, Dealercount);
					PrintHands(PlayerCard, Playercount, DealerCard, Dealercount, true);
					printf("플레이어 점수 : %d\n", PlayerScore);
					printf("딜러 점수 : %d\n", DealerScore);
					return;
				}
			}
			PlayerScore = GetBestScore(PlayerCard, Playercount);
			DealerScore = GetBestScore(DealerCard, Dealercount);
			PrintHands(PlayerCard, Playercount, DealerCard, Dealercount, true);
			printf("플레이어 점수 : %d\n", PlayerScore);
			printf("딜러 점수 : %d\n", DealerScore);
			if (PlayerScore > DealerScore) {
				printf("플레이어 : 승리\n");
			}
			else if(PlayerScore<DealerScore)
			{
				printf("딜러 : 승리\n");
			}
			else {
				printf("무승부\n");
				
			}
		}
	}
	


}

void PrintHands(const Card* inplayerhand, int inplayercount, const Card* indealerhand, int indealercount, bool is)
{
	printf("플레이어 카드 : ");
	PrintPlayerHand(inplayerhand, inplayercount);
	printf("\n딜러 카드 : ");
	PrintDealerHand(indealerhand, indealercount, is);
	printf("\n");
}

void PrintCard(const Card& incard)
{
	const char* Valuestrs[13] = { "A","2","3","4","5","6","7","8","9","10","K","Q","J"};
	printf("%c%s", incard.Shape, Valuestrs[incard.Value-1]);
}

void PrintPlayerHand(const Card* inhand, int count)
{
	for (int i = 0; i < count; i++) {
		PrintCard(inhand[i]);
		printf(" ");
	}
}

void PrintDealerHand(const Card* inhand, int count, bool InRevealHole)
{
	for (int i = 0; i < count; i++) {
		if (i == 1 && InRevealHole==false)
		{
			printf("??");
		}
		else {
			PrintCard(inhand[i]);
		}
		
		printf(" ");
	}
}

bool isBlackJack(const Card* inhand, int count)
{
	bool Result = false;

	if (count == 2) {
		if ((inhand[0].Value == 1 && GetCardValue(inhand[1]) == 10)||
			(inhand[1].Value == 1 && GetCardValue(inhand[0]) == 10)) {
			Result = true;
		}
	}

	return Result;
}

int GetCardValue(const Card& incard)
{
	int value = incard.Value;
	if (value>10) {
		value = 10;
	}
	return value;
}

bool isBurst(Card* inhand, int incount)
{
	return GetBestScore(inhand,incount)>21;
}

int GetBestScore(Card* inhand, int incount)
{
	int Sum = 0;
	int Acecount = 0;
	for (int i = 0; i < incount; i++) {
		Sum += GetCardValue(inhand[i]);
		if (inhand[i].isAce() == 1) {
			Acecount++;
		}
	}
	while ((Acecount > 0) && (Sum + 10) <= 21)
	{
		Sum += 10;
		Acecount--;
	}
	return Sum;
}
bool isSoft17(Card* InHand, int InCount)
{
	int Sum = 0;
	for (int i = 0; i < InCount; i++)
	{
		Sum += GetCardValue(InHand[i]);
		if (InHand[i].isAce())
		{
			Sum += 10;
		}
	}
	return Sum >= 17;
}