#pragma once
//1번문제
void practice_0905_1();

int Random_int_Return(int, int);


//2번문제
void practice_0905_2();

int YourAge(int);

//3번문제
void practice_0905_3();

float CircleResult(float);

//4번문제
void practice_0905_4();

bool OddEvenResult(int);

//5번문제
void practice_0905_5();

int RankSelect(int);

//6번문제
void practice_0905_6();

int ItemInventoryAdd(int,int);

int ItemInventoryDelete(int, int);

int ItemInventoryToggle(int, int);

//7번문제
void practice_0905_7();

void PyramidMake(int);

//9번문제
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