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
	Goblin.Name = "���1ȣ";
	/*Goblin.Helath = 100.0f;
	Goblin.Attakpower = 10.0f;
	Goblin.DropGold = 100;*/
	printf("�̸� :%s\n", Goblin.Name.c_str());
	printf("HP : %.1f\n", Goblin.Health);
	printf("���ݷ� : %.1f\n", Goblin.Attackpower);
	printf("������ : %d\n", Goblin.DropGold);

	printf("\n");

	Enemy* enemy = new Enemy();
	enemy->Name = "��1ȣ";
	enemy->Health = 200.0f;
	enemy->Attackpower = 20.0f;
	enemy->DropGold = 200;

	printf("�̸� :%s\n", enemy->Name.c_str());
	printf("HP : %.1f\n", enemy->Health);
	printf("���ݷ� : %.1f\n", enemy->Attackpower);
	printf("������ : %d\n", enemy->DropGold);

	printf("\n");
	Boss* boss = new Boss();

	boss->Name = "����1ȣ";

	printf("�̸� :%s\n", boss->Name.c_str());
	printf("HP : %.1f\n", boss->Helath);
	printf("���ݷ� : %.1f\n", boss->Attakpower);
	printf("������ : %d\n", boss->DropGold);
	printf("\n");

	Item* item = new Item();

	printf("�̸� :%s\n", item->Name.c_str());
	printf("HP�߰� : %1f\n", item->HPAdd);
	printf("������ : %d\n", item->BuyGold);
	printf("������ : %d\n", item->SellGold);
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
		Goblins[i].Name = "���"+std::to_string(i+1)+"ȣ";
		printf("�̸� : %s\n", Goblins[i].Name.c_str());
	}

	delete[] Goblins;
	Goblins = nullptr;
	printf("\n");

	Enemy* enemy1 = new Enemy(10.0f);

	printf("�̸� :%s\n", enemy1->Name.c_str());
	printf("HP : %.1f\n", enemy1->Health);
	printf("���ݷ� : %.1f\n", enemy1->Attackpower);
	printf("������ : %d\n", enemy1->DropGold);

	delete enemy1;
	enemy1 = nullptr;
	
}

void practice09122()
{
	Enemy Goblin1("���1ȣ");
	Enemy Goblin2("���2ȣ");

	Enemy Fusion(Goblin1 + Goblin2);

	printf("�̸� :%s\n", Fusion.Name.c_str());
	printf("HP : %.1f\n", Fusion.Health);
	printf("���ݷ� : %.1f\n", Fusion.Attackpower);
	printf("������ : %d\n", Fusion.DropGold);

}

void practice09123()
{
	Enemy Goblin1("���1ȣ");
	Enemy Goblin2("���2ȣ");

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
	printf("�̸� :%s\n", enemy.Name.c_str());
	printf("HP : %.1f\n", enemy.Health);
	printf("���ݷ� : %.1f\n", enemy.Attackpower);
	printf("������ : %d\n", enemy.DropGold);
}

//��ġ ǥ���� ����ü Position �����
//## �䱸����
//����ü �̸��� Position���� �Ѵ�.
//��� ������ int x, int y�� ������.
//�� ��� ������ �⺻���� 0�̾�� �Ѵ�.
//�� ���� ���� ���� �޾Ƽ� ��� ������ �Ҵ��ϴ� �����ڸ� �����.
//+ �����ڸ� �����ε��Ͽ� �� Position ��ü�� ������ ��, ������ ������� ���� ����� ���� ���ο� Position ��ü�� �����ǵ��� �Ѵ�.
//�����ڵ� �����ε��Ͽ� �� Position ��ü�� ���� ��, ������ ������� �� ����� ���� ���ο� Position ��ü�� �����ǵ��� �Ѵ�.

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


