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
	printf("����� %d�� %d�� %d�� %d���� �Դϴ� .\n",date.year,date.month,date.day,date.weekday);

	printf("���� ���� ��¥�� �����? : \n");

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

	

	//��� ����ϰ� ���� �ϼ��߿��� ����
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
	
	printf("�Է��Ͻ� �ϼ� ���� ��¥�� \n%d�� %d�� %d��", date.year, date.month, date.day);

	switch (days%7)
	{
		case 0: printf(" ������ �Դϴ� .");
			break;
		case 1: printf(" ȭ���� �Դϴ� .");
			break;
		case 2: printf(" ������ �Դϴ� .");
			break;
		case 3: printf(" ����� �Դϴ� .");
			break;
		case 4: printf(" �ݿ��� �Դϴ� .");
			break;
		case 5: printf(" ����� �Դϴ� .");
			break;
		case 6: printf(" �Ͽ��� �Դϴ� .");
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

//���� ��ǥ
//�� ī���� ���� 21�� ������ �����, 21�� ���� �ʴ� ���� ��ǥ
//21�� �ʰ��ϸ�(����Ʈ, Bust) ��� �й�
//������ ����
//
//ī���� ��
//2~10: ī�� ���� �״�� ����.
//J(��), Q(��), K(ŷ) : ���� 10��.
//A(���̽�) : 1�� �Ǵ� 11��(������ ������ �ڵ� ����).
//
//���� ���� ����
//1) �ʱ� ���
//������ �÷��̾� ��� 2�徿 ī�带 ����.
//�÷��̾��� ī��� �� �� ��� ����.
//������ �� ���� ����(���� ī��), �� ���� �����(Ȧ ī��).
//
//2) �÷��̾� ��
//�÷��̾ ���� �ൿ.
//������:
//Hit(��Ʈ) : ī�带 �� �� �� ����.
//Stand(���ĵ�) : �� �̻� ī�带 ���� �ʰ� ����.
//�÷��̾ 21�� �ʰ��ϸ�(����Ʈ) ��� �й�.
//
//3) ���� ��
//�÷��̾ ���ĵ带 �ϸ� ���� ����.
//������ �ڽ��� ī�� ���� 17 �̻��� �� ������ ��� ��Ʈ(ī�� �ޱ�)�ؾ� ��.
//A�� ���Ե� "����Ʈ 17"(A + 6 = 7 �Ǵ� 17)�� ����.
//17 �̻��̸� ���߰�, 21�� ������ ���� �й�.
//
//4) ���� ����
//����Ʈ�� �ƴ� ���, ���� ��.
//�÷��̾ 21�� �� ������ �¸�.
//�����̸� ���º�(Push).
//������ �� ������ �й�.
//����: ó�� ���� �� ���� A + 10(�Ǵ� J, Q, K)�̸� ����.�Ϲ������� ������ �ܼ� 21������ �켱��.
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
		printf("���º� : ����\n");
		PrintHands(PlayerCard, Playercount, DealerCard, Dealercount, true);
	}
	else if (IsPlayerBlackJack) {
		printf("�÷��̾� : ����\n");
		PrintHands(PlayerCard, Playercount, DealerCard, Dealercount, true);
	}
	else if (IsDealerBlackJack) {
		printf("���� : ����\n");
		PrintHands(PlayerCard, Playercount, DealerCard, Dealercount, true);
	}
	else {
		bool isPlayerStand = false;
		while (!isPlayerStand && !isBurst(PlayerCard, Playercount))
		{
			printf("�÷��̾� ���� : %d\n", GetBestScore(PlayerCard, Playercount));
			printf("Hit(1) / Stand(2)?  : \n");
			int Input = 0;
			std::cin >> Input;
			printf("--------------------------------\n");
			if (Input == 1) {
				AddCardtoHand(PlayerCard, Playercount, DrawCard(card, DeckTop));
				PrintHands(PlayerCard, Playercount, DealerCard, Dealercount, false);
				if (isBurst(PlayerCard, Playercount)) {
					printf("�÷��̾� : ����Ʈ! �й�\n");
					PlayerScore = GetBestScore(PlayerCard, Playercount);
					DealerScore = GetBestScore(DealerCard, Dealercount);
					PrintHands(PlayerCard, Playercount, DealerCard, Dealercount, true);
					printf("�÷��̾� ���� : %d\n", PlayerScore);
					printf("���� ���� : %d\n", DealerScore);
					return;
				}
			}
			else {
				isPlayerStand = true;
			}
			
			printf("���� �� ���� \n");
			printf("--------------------------------\n");
			PrintHands(PlayerCard, Playercount, DealerCard, Dealercount, true);
			while (GetBestScore(DealerCard,Dealercount)<17)
			{
				if (isSoft17(DealerCard, Dealercount)) {
					break;
				}
				AddCardtoHand(DealerCard, Dealercount, DrawCard(card, DeckTop));
				printf("���� ī�� : ");
				PrintDealerHand(DealerCard, Dealercount, true);
				printf("\n");

				if (isBurst(DealerCard, Dealercount)) {
					printf("���� : ����Ʈ\n");
					PlayerScore = GetBestScore(PlayerCard, Playercount);
					DealerScore = GetBestScore(DealerCard, Dealercount);
					PrintHands(PlayerCard, Playercount, DealerCard, Dealercount, true);
					printf("�÷��̾� ���� : %d\n", PlayerScore);
					printf("���� ���� : %d\n", DealerScore);
					return;
				}
			}
			PlayerScore = GetBestScore(PlayerCard, Playercount);
			DealerScore = GetBestScore(DealerCard, Dealercount);
			PrintHands(PlayerCard, Playercount, DealerCard, Dealercount, true);
			printf("�÷��̾� ���� : %d\n", PlayerScore);
			printf("���� ���� : %d\n", DealerScore);
			if (PlayerScore > DealerScore) {
				printf("�÷��̾� : �¸�\n");
			}
			else if(PlayerScore<DealerScore)
			{
				printf("���� : �¸�\n");
			}
			else {
				printf("���º�\n");
				
			}
		}
	}
	


}

void PrintHands(const Card* inplayerhand, int inplayercount, const Card* indealerhand, int indealercount, bool is)
{
	printf("�÷��̾� ī�� : ");
	PrintPlayerHand(inplayerhand, inplayercount);
	printf("\n���� ī�� : ");
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