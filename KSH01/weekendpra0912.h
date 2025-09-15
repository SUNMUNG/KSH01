#pragma once

void weekendpra09121();

struct Date
{
	int year = 1;
	int day = 1;
	int month = 1;
	int weekday = 0;
};



struct Card
{
	int Value=0;
	char Shape=0;

	bool isAce() { return Value == 1; }
	int GetCardValue() { return Value > 10 ? 10 : Value; };
};

void weekendpra09122();

void CardList(Card* List);

void shuffle(Card* List);

const Card& DrawCard(Card* List, int& intop);

void AddCardtoHand(Card* inhand,int& count,const Card& card);

void PlayGame();

void PrintHands(const Card* inplayerhand,int inplayercount, const Card* indealerhand, int indealercount,bool is);

void PrintCard(const Card& incard);

void PrintPlayerHand(const Card* inhand,  int count);

void PrintDealerHand(const Card* inhand,  int count, bool InRevealHole);

bool isBlackJack(const Card* inhand, int count);

int GetCardValue(const Card& incard);

bool isBurst(Card* inhand, int incount);

int GetBestScore(Card* inhand, int incount);

bool isSoft17(Card* InHand, int InCount);

