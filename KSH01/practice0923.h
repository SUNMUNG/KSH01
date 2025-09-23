#pragma once
#include "Coordinate.h"
#include "Caculator.h"
#include <iostream>
#include <cstdio>
#include <vector>

class practice0923
{
public:
    void TestTemplate();
    void TestCaculator();
    void TestVector();
    void TestVectorPractice();

    void MaxMinNumber(std::vector<int> inNumbers);
    void SortNumbers(std::vector<int>& inNumbers);
    void FindNumbers(std::vector<int> inNumbers,int FindNum);
    void DistinctNumbers(std::vector<int>& inNumbers);
    void VectersCat(std::vector<int>& inNumbers, std::vector<int> inNumbers2);
    void Reverse(std::vector<int>& inNumbers);
    void VectorSum(std::vector<int> inNumbers);
    void SwapAndPop(std::vector<int>& inNumbers,int SwapIndex);
};
