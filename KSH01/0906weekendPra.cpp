#include "0906weekendpra.h"
#include <stdio.h>
#include <cstring>
#include <random>
#include <string>
#include <iostream>




//3���� �Ķ���͸� �޾� ��հ��� �����ϴ� �Լ� �����
void weekendPra1()
{
	int num1, num2, num3;
	printf("�� ���� �Է��ϼ��� : \n");
	std::cin >> num1 >> num2 >> num3;

	printf("����� %.2f �Դϴ�.\n",Average(num1,num2,num3));

}

float Average(int num1, int num2, int num3)
{
	float avg = 0.0f;
	avg = (num1 + num2 + num3) / 3.0f;
	return avg;
}


//������ ������ �Է� �޾� ���ΰ� ���ϴ� �Լ� �����
void weekendPra2()
{
	int OriginalPrice;
	float SaleRate;
	printf("���� �� �������� �Է����ּ���. \n");
	std::cin >> OriginalPrice;
	std::cin >> SaleRate;

	printf("���ΰ��� %d �Դϴ�. \n",SalePrice(OriginalPrice, SaleRate));

}

int SalePrice(int OriginalPrice, float SaleRate)
{
	int saleprice = 0;
	saleprice = OriginalPrice * SaleRate;
	return saleprice;
}



//�ֻ����� ���� ����� �����ϴ� �Լ� �����

void weekendPra3()
{
	srand(time(0));
	printf("�ֻ����� �����ϴ�.\n");
	printf("��������� ..  %d",RollDice());

}

int RollDice()
{
	int Dice=-1;
	Dice = rand() % 6 + 1;
	return Dice;
}



//������ �ָ� ����(A~F)�� �ִ� �Լ� �����

void weekendPra4()
{
	int Score;
	printf("������ �Է��ϼ��� \n");
	std::cin >> Score;
	printf("������ %c �Դϴ�\n",RankDecide(Score));
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



//���ø� �Լ��� Clamp �Լ� �����ϱ�

void weekendPra5()
{
}

//�ڸ��� �и��ϱ�(�Է��� �ڸ� �� ���� ����)
//�� �ڸ��� ���� ���ؼ� ����ϱ�
void weekendPra6()
{
	int Number;
	printf("���� �Է��ϼ��� \n");
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



//��� �Լ��� �̿��Ͽ� 10������ �Է¹޾� 2������ ����ϴ� �Լ� �����
void weekendPra7()
{
	int Number;
	printf("���� �Է��ϼ��� \n");
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
	//������ ���	
}

//���� �ӽ� ���� �����
//���� �ݾ� 10000
//���ǿ� ������  �ּ� 100 �����ؾ� ��.���� �����ݾ��� 100 ������ ��� ���� ����.
//���� ���� 3���� ������ 50��� ���� �޴´�.
//���� 777�̸� 10000�� ����

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
		printf("���� �ӽ� ������ �����մϴ�.\n");

		printf("������ �ݾ��� �Է����ּ���.\n100������ ���� �Է½� �ٽ��Է�\n");
		printf("���� �ݾ��� : %d\n", PlayerMoney);
		std::cin >> PlayerBatting;
		

		
		PlayerMoney -= PlayerBatting;
		RandomNumber1 = rand() % 9 + 1;
		RandomNumber2 = rand() % 9 + 1;
		RandomNumber3 = rand() % 9 + 1;

		if ((RandomNumber1 == 7) && (RandomNumber2 == 7) && (RandomNumber3 == 7)) {
			printf("��Ű !! \n");
			printf("���� ���� : %d %d %d\n", RandomNumber1, RandomNumber2, RandomNumber3);
			PlayerMoney += PlayerBatting * 10000;
		}
		else if (RandomNumber1 == RandomNumber2 == RandomNumber3) {
			printf("��÷�Ǿ����ϴ�. \n");
			printf("���� ���� : %d %d %d\n", RandomNumber1, RandomNumber2, RandomNumber3);
			PlayerMoney += PlayerBatting * 50;
		}
		else {
			printf("��÷���� �ʾҽ��ϴ�. \n");
			printf("���� ���� : %d %d %d\n", RandomNumber1, RandomNumber2, RandomNumber3);
		}


	}
		
}


//�÷��̾�� ���� ���� ���� �����
//HP�� 100���� ����
//������ �� �� ���濡�� 5~15�� �������� �ش�.
//10 % �� Ȯ���� ũ��Ƽ���� �߻��� 2���� �������� �ش�.
//������ HP�� 0 ���ϰ� �Ǹ� �¸��Ѵ�.

void TurnBattle()
{
	srand(time(0));
	int PlayerHp = 100;
	int EnemyHp = 100;
	int PlayerDamage;
	int EnemyDamage;
	int PlayercritRate; // 0~9���� ������ 10���� ���� �� 5�� 1/10
	int EnemycritRate; // 0~9���� ������ 10���� ���� �� 5�� 1/10
	printf("���� ���� ������ �����մϴ�.\n");
	printf("���� ���� ü�� : %d\n", PlayerHp);
	printf("���� ���� ü�� : %d\n", EnemyHp);

	printf("������ �����մϴ�. ���͸� ������ ����.\n");
	getchar();

	while (PlayerHp > 0 && EnemyHp > 0) {


		PlayerDamage = rand() % 11 + 5;
		EnemyDamage = rand() % 11 + 5;
		PlayercritRate = rand() % 10;
		EnemycritRate = rand() % 10;



		//�÷��̾� ũ��Ƽ�� �߻� ����
		if (PlayercritRate == 5) {
			PlayerDamage *= 2;
			printf("ũ��Ƽ���� �߻��Ͽ����ϴ� : �÷��̾�\n");
		}


		// ü���� ������ �������°� ����
		EnemyHp -= PlayerDamage;
		if (EnemyHp <= 0) {
			EnemyHp = 0;
		}
		printf("�� ���� %d �� �������� �־����ϴ�.\n", PlayerDamage);
		printf("���� ���� HP : %d\n�÷��̾� ���� HP : %d\n", EnemyHp, PlayerHp);
		printf("����Ϸ��� ����\n");
		getchar();

		if (PlayerHp <= 0) {
			printf("�÷��̾ �й��߽��ϴ�.\n");
			break;
		}
		else if (EnemyHp <= 0) {
			printf("�÷��̾ �¸��߽��ϴ�.\n");
			break;
		}


		//�� ũ��Ƽ�� �߻� ����
		if (EnemycritRate == 5) {
			EnemyDamage *= 2;
			printf("ũ��Ƽ���� �߻��Ͽ����ϴ� : �÷��̾�\n");
		}

		// ü���� ������ �������°� ����
		PlayerHp -= EnemyDamage;
		if (PlayerHp <= 0) {
			PlayerHp = 0;
		}
		printf("�÷��̾ %d �� �������� �޾ҽ��ϴ�.\n", EnemyDamage);
		printf("���� ���� HP : %d\n�÷��̾� ���� HP : %d\n", EnemyHp, PlayerHp);
		printf("����Ϸ��� ����\n");
		getchar();

		if (PlayerHp <= 0) {
			printf("�÷��̾ �й��߽��ϴ�.\n");
			break;
		}
		else if (EnemyHp <= 0) {
			printf("�÷��̾ �¸��߽��ϴ�.\n");
			break;
		}

	}





}

//���� ��� �����
//���� �ݾ� 10000
//���ǿ� ������ �ּ� 100 �����ؾ� ��.���� �����ݾ��� 100 ������ ��� ���� ����.
//������ A~K������ Ʈ���� ī��� ��Ŀ ī�� �� 3���� �������� �̴´�.(�ߺ��� ����� ��)
// A 2 3 4 5 6 7 8 9 10 K Q J ��Ŀ
//�÷��̾�� ������ ī�� �� ������ �����Ѵ�.
//���� �÷��̾ ��Ŀ�� ���ִٸ� �÷��̾��� �¸�.���� �ݾ��� 2�踦 �޴´�.
//�÷��̾ ��Ŀ�� ���� ���ߴٸ� ���� ������ �����ϰų� ���� �ݾ��� 2�踦 �߰��� �����ϰ� �ѹ� �� ������ �� �ִ�.

void weekendPra10()
{
	CardGame();
}

void CardGame()
{
	// A 2 3 4 5 6 7 8 9 10 K Q J ��Ŀ
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

	printf("������� ������ �����մϴ� . \n");

	while (PlayerMoney > 100) {
		printf("������ �ݾ��� �Է����ּ���.\n100������ ���� �Է½� �ٽ��Է�\n");
		printf("���� �ݾ��� : %d\n", PlayerMoney);
		std::cin >> PlayerBatting;

		PlayerMoney -= PlayerBatting;

		Jokerpick = rand() % 3; //0,2�� ��ĿX 1�� ��Ŀ // 1/3Ȯ���� ��Ŀ

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

		printf("������ ���� ī���� �ϳ��� �������ּ���\n");
		printf("[1.ù��° 2.�ι�° 3.����°]\n");
		std::cin >> PlayerSelectCard;

		if (PlayerSelectCard == 1 && DealerCard1 == Joker) {
			PlayerMoney += PlayerBatting * 2;
			printf("�¸�\n");
			printf("��ǻ�Ͱ� ���� ī��: \n");
			CardPrint(DealerCard1);
			CardPrint(DealerCard2);
			CardPrint(DealerCard3);
			printf("��ȣ�� �������ּ��� : \n");
			printf("[1.���� ���� 2.���⼭ ��]\n");
			std::cin >> PlayerSelectNumber;
			Regame(PlayerSelectNumber);
		}
		else if (PlayerSelectCard == 2 && DealerCard2 == Joker) {
			PlayerMoney += PlayerBatting * 2;
			printf("�¸�\n");
			printf("��ǻ�Ͱ� ���� ī��: \n");
			CardPrint(DealerCard1);
			CardPrint(DealerCard2);
			CardPrint(DealerCard3);
			/*printf("��ȣ�� �������ּ��� : \n");
			printf("[1.���� ���� 2.���⼭ ��]\n");
			std::cin >> PlayerSelectNumber;
			Regame(PlayerSelectNumber);*/
		}
		else if (PlayerSelectCard == 3 && DealerCard3 == Joker) {
			PlayerMoney += PlayerBatting * 2;
			printf("�¸�\n");
			printf("��ǻ�Ͱ� ���� ī��: \n");
			CardPrint(DealerCard1);
			CardPrint(DealerCard2);
			CardPrint(DealerCard3);
		/*	printf("��ȣ�� �������ּ��� : \n");
			printf("[1.���� ���� 2.���⼭ ��]\n");
			std::cin >> PlayerSelectNumber;
			Regame(PlayerSelectNumber);*/
		}
		else {
			printf("�й�\n");
			printf("��ǻ�Ͱ� ���� ī��: \n");
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