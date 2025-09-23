#pragma once
#include <iostream>
#include <cstdio>
#include <type_traits>
#include <limits>

template<typename T>
struct Coordinate
{
	T x;
	T y;

	// 햇깔릴 수 있는 상황이면 명시적으로 이야기 해주는 것이 좋다.
	Coordinate() : x{}, y{} 
	{};	// 자동으로 생성되는 기본생성자와 같다.	
	Coordinate(T InX, T InY)
		: x(InX), y(InY)
	{
		// 추가 계산이 필요한 경우. 이쪽에 새로 대입하기.
	}

	void Print()const 
	{
		if constexpr (std::is_same_v<T, int>)
		{
			printf("(%d, %d)\n", x, y);
		}
		else if constexpr (std::is_same_v<T, float>)
		{
			printf("(%f, %f)\n", x, y);
		} 
		std::cout << "(" << x << ", " << y << ")" << std::endl;
	}

	Coordinate& operator+=(const Coordinate& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}
	Coordinate& operator-=(const Coordinate& other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}
};

template <typename T>
T Abs(T InValue)
{
	return (InValue < 0) ? -InValue : InValue;
}
// 이항연산자는 구조체 밖에 쓰는 것이 일반적이다.
template <typename T>
Coordinate<T> operator+(const Coordinate<T>& a, const Coordinate<T>& b)
{
	return Coordinate<T>(a.x + b.x, a.y + b.y);
}
template <typename T>
Coordinate<T> operator-(const Coordinate<T>& a, const Coordinate<T>& b) 
{
	return Coordinate<T>(a.x - b.x, a.y - b.y);
}
template <typename T>
Coordinate<T> operator*(const Coordinate<T>& a, const Coordinate<T>& b)
{
	return Coordinate<T>(a.x * b.x, a.y * b.y);
}
template <typename T>
Coordinate<T> operator/(const Coordinate<T>& a, const Coordinate<T>& b)
{
	return Coordinate<T>(a.x / b.x, a.y / b.y);
}
//template <typename T>
//bool operator==(const Coordinate<T>& a, const Coordinate<T>& b)
//{
//	return a.x == b.x && a.y == b.y;
//}
//template <>
//bool operator==(const Coordinate<float>& a, const Coordinate<float>& b)
//{
//	return Abs(a.x - b.x) <= FLT_EPSILON && Abs(a.y - b.y) <= FLT_EPSILON;
//}
//template <typename T>
//bool operator!=(const Coordinate<T>& a, const Coordinate<T>& b)
//{
//	return !(a == b);
//}