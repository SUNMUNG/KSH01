#include "practice0923.h"
#include "Caculator.h"
#include <vector>
#include <algorithm>
#include <limits>


void practice0923::TestTemplate()
{
	Coordinate<int> PositionInt(1, 3);
	Coordinate<float> PositionFloat(0.05f, 5.7f);

	printf("PositionInt : %d, %d\n", PositionInt.x, PositionInt.y);
	printf("PositionFloat : %f, %f\n", PositionFloat.x, PositionFloat.y);
		
	PositionInt.Print();
	PositionFloat.Print();

	Coordinate<std::string> PositionString("A", "B");
	PositionString.Print();
}

void practice0923::TestCaculator()
{
	Caculator Calc;
	int ResultInt = Calc.Add(1, 3);
	float ResultFloat = Calc.Add(2.5f, 7.3f);
	Coordinate<int> ResultCoord = Calc.Add(Coordinate<int>(1, 2), Coordinate<int>(3, 4));

	ResultInt = Calc.Multiply(5, 3);
	ResultFloat = Calc.Multiply(3.5f, 2.0f);
	ResultCoord = Calc.Multiply(Coordinate<int>(1, 2), Coordinate<int>(3, 4));

	int i = 0;
}

void practice0923::TestVector()
{
	std::vector<int> Score;
	Score.reserve(10);
	Score.push_back(10);
	Score.push_back(20);
	Score.push_back(30);
	Score.push_back(40);
	

	for (int i = 0; i < Score.size(); i++) {
		printf("%d ", Score[i]);
	}
}

void practice0923::TestVectorPractice()
{
	/*	1. ���� �Է¹ް� ����ϱ�
		2. �ִ�, �ּ� ���ϱ�
		3. �����ϱ�
		4. Ư�� �� ã��
		5. �ߺ� �����ϱ�
		6. ���� ��ġ��
		7. ���ڿ� ������
		8. ��� ��� ���ϱ�
	*/
	std::vector<int> Numbers;
	std::vector<int> Numbers2 = {1,2,3,4,5};
	int Num =-2;
	while (Num != -1) {
		printf("������ �Է����ּ��� : (-1 �Է½� �Ϸ�)\n");
		std::cin >> Num;
		if (Num != -1){
			Numbers.push_back(Num);
		}
		
	}
	printf("�Էµ� ������ : \n");
	for (int i = 0; i < Numbers.size(); i++) {
		printf("%d ", Numbers[i]);
	}
	printf("\n");
	int SelectNum = -2;
	while (SelectNum != -1) {
		printf("1. �ִ�, �ּ� ���ϱ�\n2. �����ϱ�\n3. Ư�� �� ã��\n4. �ߺ� �����ϱ�\n5. ���� ��ġ��\n6. ���ڿ� ������\n7. ��� ��� ���ϱ�\n8. -1�Է½� ����\n");
		std::cin >> SelectNum;
		switch (SelectNum)
		{
		case 1: MaxMinNumber(Numbers);
			break;
		case 2: SortNumbers(Numbers);
			break;
		case 3: FindNumbers(Numbers, 10);
			break;
		case 4: DistinctNumbers(Numbers);
			break;
		case 5: VectersCat(Numbers, Numbers2);
			break;
		case 6: Reverse(Numbers);
			break;
		case 7: VectorSum(Numbers);
			break;
		default: printf("����\n");
			break;
		}
	}
	
}

void practice0923::MaxMinNumber(std::vector<int> inNumbers)
{
	int MaxNum = INT_MIN;
	int MinNum = INT_MAX;
	for (int i = 0; i < inNumbers.size(); i++) {
		if (MinNum > inNumbers[i]) {
			MinNum = inNumbers[i];
		}
		if (MaxNum < inNumbers[i]) {
			MaxNum = inNumbers[i];
		}
	}
	printf("�ּҰ��� : %d\n�ִ밪�� : %d\n", MinNum, MaxNum);
	printf("\n");
}

void practice0923::SortNumbers(std::vector<int>& inNumbers)
{
	std::sort(inNumbers.begin(), inNumbers.end());

	printf("%���ĵ� ���� : \b");
	for (int i = 0; i < inNumbers.size(); i++) {
		printf("%d ", inNumbers[i]);
	}
	printf("\n");
}

void practice0923::FindNumbers(std::vector<int> inNumbers, int FindNum)
{
	for (int i = 0; i < inNumbers.size(); i++) {
		if (inNumbers[i] == FindNum) {
			printf("%d��° �ε������� ã�ҽ��ϴ�.\n",i);
		}
	}
	printf("\n");
}

void practice0923::DistinctNumbers(std::vector<int>& inNumbers)
{
	for (int i = 0; i < inNumbers.size(); i++) {
		for (int j = i + 1; j < inNumbers.size(); j++) {
			if (inNumbers[i] == inNumbers[j]) {
				SwapAndPop(inNumbers,j);
			}
		}
	}
	printf("�ߺ��� �� ���� : \n");
	for (int i = 0; i < inNumbers.size(); i++) {
		printf("%d ", inNumbers[i]);
	}
	printf("\n");

}

void practice0923::VectersCat(std::vector<int>& inNumbers, std::vector<int> inNumbers2)
{
	for (int i = 0; i < inNumbers2.size(); i++) {
		inNumbers.push_back(inNumbers2[i]);
	}
	printf("�� ���Ͱ� ������ : \n");
	for (int i = 0; i < inNumbers.size(); i++) {
		printf("%d ", inNumbers[i]);
	}
	printf("\n");

}

void practice0923::Reverse(std::vector<int>& inNumbers)
{
	printf("%������ ���� : \b");
	for (int i = inNumbers.size()-1; i >=0 ; i--) {
		printf("%d ", inNumbers[i]);
	}
	printf("\n");

}

void practice0923::VectorSum(std::vector<int> inNumbers)
{
	int sum = 0;
	for (int i = 0; i < inNumbers.size(); i++) {
		sum += inNumbers[i];
	}
	printf("���� : %d\n", sum);
}

void practice0923::SwapAndPop(std::vector<int>& inNumbers,int SwapIndex)
{
	inNumbers[SwapIndex] = inNumbers.back();
	inNumbers.pop_back();
}
