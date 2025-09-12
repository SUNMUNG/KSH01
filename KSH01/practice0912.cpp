#include <cstring>
#include <random>
#include <string>
#include <limits.h>
#include <direct.h>
#include <fstream>
#include "practice0911.h"
#include "practice0910.h"
#include "practice0912.h"

void practice09121()
{
	Enemy Goblin;
	Goblin.Name = "고블린1호";
	/*Goblin.Helath = 100.0f;
	Goblin.Attakpower = 10.0f;
	Goblin.DropGold = 100;*/
	printf("이름 :%s\n", Goblin.Name.c_str());
	printf("HP : %.1f\n", Goblin.Health);
	printf("공격력 : %.1f\n", Goblin.Attackpower);
	printf("드랍골드 : %d\n", Goblin.DropGold);

	printf("\n");

	Enemy* enemy = new Enemy();
	enemy->Name = "적1호";
	enemy->Health = 200.0f;
	enemy->Attackpower = 20.0f;
	enemy->DropGold = 200;

	printf("이름 :%s\n", enemy->Name.c_str());
	printf("HP : %.1f\n", enemy->Health);
	printf("공격력 : %.1f\n", enemy->Attackpower);
	printf("드랍골드 : %d\n", enemy->DropGold);

	printf("\n");
	Boss* boss = new Boss();

	boss->Name = "보스1호";

	printf("이름 :%s\n", boss->Name.c_str());
	printf("HP : %.1f\n", boss->Helath);
	printf("공격력 : %.1f\n", boss->Attakpower);
	printf("드랍골드 : %d\n", boss->DropGold);
	printf("\n");

	Item* item = new Item();

	printf("이름 :%s\n", item->Name.c_str());
	printf("HP추가 : %1f\n", item->HPAdd);
	printf("드랍골드 : %d\n", item->BuyGold);
	printf("드랍골드 : %d\n", item->SellGold);
	printf("\n");

	delete item;
	delete enemy;
	delete boss;
	item = nullptr;
	enemy = nullptr;
	boss = nullptr;


	Enemy* Goblins = nullptr;
	Goblins = new Enemy[3]();

	for (int i = 0; i < 3; i++) {
		Goblins[i].Name = "고블린"+std::to_string(i+1)+"호";
		printf("이름 : %s\n", Goblins[i].Name.c_str());
	}

	delete[] Goblins;
	Goblins = nullptr;
	printf("\n");

	Enemy* enemy1 = new Enemy(10.0f);

	printf("이름 :%s\n", enemy1->Name.c_str());
	printf("HP : %.1f\n", enemy1->Health);
	printf("공격력 : %.1f\n", enemy1->Attackpower);
	printf("드랍골드 : %d\n", enemy1->DropGold);

	delete enemy1;
	enemy1 = nullptr;
	
}

void practice09122()
{
	Enemy Goblin1("고블린1호");
	Enemy Goblin2("고블린2호");

	Enemy Fusion(Goblin1 + Goblin2);

	printf("이름 :%s\n", Fusion.Name.c_str());
	printf("HP : %.1f\n", Fusion.Health);
	printf("공격력 : %.1f\n", Fusion.Attackpower);
	printf("드랍골드 : %d\n", Fusion.DropGold);

}

void practice09123()
{
	Enemy Goblin1("고블린1호");
	Enemy Goblin2("고블린2호");

	Enemy Fusion1(Goblin1 + Goblin2);
	Enemy Fusion2(Goblin1 - Goblin2);
	Enemy Fusion3(Goblin1 * 5.0f);
	Enemy Fusion3_2 = Goblin1 * 5.0f;
	Enemy Fusion4(Goblin1 *= 5.0f);

	printEnemy(Fusion1);
	printEnemy(Fusion2);
	printEnemy(Fusion3);
	printEnemy(Fusion3_2);
	printEnemy(Fusion4);
}

void printEnemy(Enemy enemy)
{
	printf("이름 :%s\n", enemy.Name.c_str());
	printf("HP : %.1f\n", enemy.Health);
	printf("공격력 : %.1f\n", enemy.Attackpower);
	printf("드랍골드 : %d\n", enemy.DropGold);
}

//위치 표현용 구조체 Position 만들기
//## 요구사항
//구조체 이름은 Position으로 한다.
//멤버 변수로 int x, int y를 가진다.
//두 멤버 변수는 기본값이 0이어야 한다.
//두 개의 정수 값을 받아서 멤버 변수에 할당하는 생성자를 만든다.
//+ 연산자를 오버로딩하여 두 Position 객체를 더했을 때, 각각의 멤버끼리 더한 결과를 갖는 새로운 Position 객체가 생성되도록 한다.
//연산자도 오버로딩하여 두 Position 객체를 뺐을 때, 각각의 멤버끼리 뺀 결과를 갖는 새로운 Position 객체가 생성되도록 한다.

void practice09124()
{
	Position p1(2, 3);
	Position p2(5, 1);

	Position Sum = p1 + p2;
	Position diff = p1 - p2;


	SprintXY(Sum);
	SprintXY(diff);
		
}

void SprintXY(Position pos)
{
	printf("X : %d ", pos.x);
	printf("Y : %d\n", pos.y);
	
}


