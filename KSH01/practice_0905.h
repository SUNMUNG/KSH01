#pragma once
//1������
void practice_0905_1();

int Random_int_Return(int, int);


//2������
void practice_0905_2();

int YourAge(int);

//3������
void practice_0905_3();

float CircleResult(float);

//4������
void practice_0905_4();

bool OddEvenResult(int);

//5������
void practice_0905_5();

int RankSelect(int);

//6������
void practice_0905_6();

int ItemInventoryAdd(int,int);

int ItemInventoryDelete(int, int);

int ItemInventoryToggle(int, int);

//7������
void practice_0905_7();

void PyramidMake(int);

//9������
void practice09059();

int Factorial(int);

template <typename T>
T Min(T Number1, T Number2) {
	if (Number1 > Number2) {
		return Number2;
	}
	else {
		return Number1;
	}
}

template <typename T>
T Max(T Number1, T Number2) {
	if (Number1 > Number2) {
		return Number1;
	}
	else {
		return Number2;
	}
}

template <typename T>
T Clamp(T Value, T min ,T max) {
	if (Value < min) {
		return min;
	}
	else if (Value > max) {
		return max;
	}
	else {
		return Value;
	}
}