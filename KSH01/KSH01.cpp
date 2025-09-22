#define _CRTDBG_MAP_ALLOC
#define new new(_NORMAL_BLOCK,__FILE__,__LINE__)
#include <crtdbg.h>
#include <stdio.h>
#include <cstring>
#include <random>
#include <string>
#include <iostream>
#include "test.h"
#include "practice_0905.h"
#include "0906weekendPra.h"
#include "practice_0908.h"
#include "practice0909.h"
#include "practice0911.h"
#include "practice0910.h"
#include "practice0912.h"
#include "weekendpra0912.h"
#include "weekend0920.h"
#include "practice0916.h"
#include "practice0917.h"
#include "practice0918.h"
#include "practice0919.h"
#include "GameManager.h"


int main() {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	srand(time(0));
	//practice_0905_1();
	//practice_0905_2();
	//practice_0905_3();
	//practice_0905_4();
	//practice_0905_5();
	//practice_0905_6();
	//practice_0905_7();
	//practice09059();

	//weekendPra1();
	//weekendPra2();
	//weekendPra3();
	//weekendPra4();
	//weekendPra6();
	//weekendPra7();
	//weekendPra8();
	//weekendPra9();
	//weekendPra10();

	//practice09081();
	//practice09082();
	//practice09083();
	//practice09084();
	//practice09085();
	//practice09086();
	//practice09087();
	//practice0908();
	//practice09089();

	//practice09091();
	//practice09092();
	//practice09093();
	//practice09094();
	//practice09095();
	//practice09096();
	//practice09097();

	//practice09101();
	//
	//practice09102();
	//
	//practice09103();
	//
	//practice09104();
	//
	//practice09105();
	//
	//practice09106();
	//
	//practice09107();

	//practice09108();

	//practice09109();

	//practice091010();

	//practice091011();
	// 
	//practice09111();



	//practice09121();
	//practice09122();
	//practice09123();
	//practice09124();


	//weekendpra09121();
	//weekendpra09122();

	/*Practice0916 pra0916;
	pra0916.ClassInstance();*/

	//practice0917 pra0917;
	/*pra0917.TestPolymorphism();*/
	//pra0917.TestPractice1();

	/*GameManager gameManager;
	gameManager.InitializeMaze();
	gameManager.MazeEscape();
	gameManager.ClearMaze();*/
	//practice0918 pra0918;
	//pra0918.TestSingleLinkedList();
	//pra0918.TestDoubleLinkedList();

	//practice0919 pra0919;

	//pra0919.TestFixedStack();
	//pra0919.TestCircularQueue();
	//pra0919.TestCircularQueue2();

	Weekend0920 weekend0920;
	Battleship cruiser(3, 1002);
	Battleship destroyer(2, 1001);
	Battleship aircraftCarrier(4, 1003);
	Battleship battleship(5, 1004);
	weekend0920.InitializeMap(destroyer, cruiser, aircraftCarrier, battleship);
	//weekend0920.PrintAllMap();
	weekend0920.BattlePhase(destroyer, cruiser, aircraftCarrier, battleship);


}



//적을 클래스화하기(Monster로 대체)
//플레이어 클래스 만들고 적용하기
//적과 플레이어의 부모인 Actor 클래스 만들기

//9 / 16 심화문제
//전투 이벤트 시 적이 랜덤한 몬스터 중 하나가 등장한다.
//GameManager 클래스 만들기
//미로 관련 데이터 생성 / 관리
//게임 진행 함수 만들기