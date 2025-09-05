#pragma once


//a
int Sum(int, int);


//a
void printHelloworld();


//b
int multiply(int, int);

//c
int division(int, int);

//d
int minus(int, int);

int TestRecurcive(int);

int factorial(int);

template <typename T> 
T Add(T Number, T Number2) {
	T res;
	res = Number + Number2;
	return res;
}
template <typename T>
T Minus(T Number, T Number2) {
	T res;
	res = Number - Number2;
	return res;
}
template <typename T>
T multiply(T Number, T Number2) {
	T res;
	res = Number * Number2;
	return res;
}
template <typename T>
T division(T Number, T Number2) {
	T res;
	res = Number / Number2;
	return res;
}

//날짜별 실습 (오래전)
void oldtales();

//날짜별 실습
void day0905();

