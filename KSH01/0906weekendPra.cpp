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
		printf("%d", num%2);
		num /= 2;
		return ToBinary(num);
	}
	else printf("0");
    //������ ���	
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

		printf("���� �ӽ� ������ �����մϴ�.\n");
		printf("������ �ݾ��� �Է����ּ���.\n");
		std::cin >> PlayerBatting;
		PlayerMoney-= PlayerBatting;

		if ((RandomNumber1 == 7) && (RandomNumber2 == 7) && (RandomNumber3 == 7)) {
			PlayerMoney += PlayerBatting * 50;
		}


}


//���� �ӽ� ���� �����
//���� �ݾ� 10000
//���ǿ� ������  �ּ� 100 �����ؾ� ��.���� �����ݾ��� 100 ������ ��� ���� ����.
//���� ���� 3���� ������ 50��� ���� �޴´�.
//���� 777�̸� 10000�� ����

//�÷��̾�� ���� ���� ���� �����
//HP�� 100���� ����
//������ �� �� ���濡�� 5~15�� �������� �ش�.
//10 % �� Ȯ���� ũ��Ƽ���� �߻��� 2���� �������� �ش�.
//������ HP�� 0 ���ϰ� �Ǹ� �¸��Ѵ�.

//���� ��� �����
//���� �ݾ� 10000
//���ǿ� ������ �ּ� 100 �����ؾ� ��.���� �����ݾ��� 100 ������ ��� ���� ����.
//������ A~K������ Ʈ���� ī��� ��Ŀ ī�� �� 3���� �������� �̴´�.(�ߺ��� ����� ��)
// A 1 2 3 4 5 6 7 8 9 K Q J ��Ŀ
//�÷��̾�� ������ ī�� �� ������ �����Ѵ�.
//���� �÷��̾ ��Ŀ�� ���ִٸ� �÷��̾��� �¸�.���� �ݾ��� 2�踦 �޴´�.
//�÷��̾ ��Ŀ�� ���� ���ߴٸ� ���� ������ �����ϰų� ���� �ݾ��� 2�踦 �߰��� �����ϰ� �ѹ� �� ������ �� �ִ�.


