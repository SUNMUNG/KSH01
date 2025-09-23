#pragma once
#include <limits>


class Caculator
{
public:

	template<typename T>
	T Add(const T& a, const T& b)
	{
		return T(a + b);
	}

	template<typename T>
	T Sub(const T& a, const T& b)
	{
		return T(a - b);
	}

	template<typename T>
	T Multiply(const T& a, const T& b)
	{
		return T(a * b);	// * 연산자가 정의되어 있는 타입만 가능하다.
	}
	template<typename T>
	bool Equal(const T& a, const T& b)
	{
		return (a == b);
	}
	template<>
	bool Equal(const float& a, const float& b)
	{
		float abs = (a - b) < 0 ? -(a - b) : (a - b);
		return abs < FLT_EPSILON;
	}

	template<>
	bool Equal(const double& a, const double& b)
	{
		double abs = (a - b) < 0 ? -(a - b) : (a - b);
		return abs < DBL_EPSILON;
	}
	Caculator() {}
	~Caculator(){}
	
	
};





