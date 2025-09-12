#define _CRTDBG_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#define new new(_NORMAL_BLOCK,__FILE__,__LINE__)
#include <crtdbg.h>
#include <stdio.h>
#include <cstring>
#include <random>
#include <string>
#include <iostream>
#include "weekendpra0912.h"

void weekendpra09121()
{
	Date date;
	int days = 0;

	printf("현재는 %d년 %d월 %d일 %d요일 입니다 .\n",date.year,date.month,date.day,date.weekday);

	printf("몇일 뒤의 날짜를 볼까요? : \n");

	std::cin >> days;


	//윤년고려
	date.year += days / 365; 
	days %= 365;
	

	for (int i = 0; i < date.year; i++) {
		if (i % 400 == 0) {
			days -= 1;
		}
		else if ((i % 4 == 0) && (i % 100 != 0)) {
			days -= 1;
		}
	}
	

	//년수 계산하고 남은 일수중에서 월일
	for (int i = 1; i <= 12; i++) {
		if (i==4||i==6||i==9) {
			if (days<= 30) {
				date.month = i;
				break;
			}
			else {
				days -= 30;
			}
			
		}
		else if (i == 2) {
			if (days <= 28) {
				date.month = i;
				break;
			}
			else {
				days -= 28;
			}
		}
		else {
			if (days <= 31) {
				date.month = i;
				break;
			}
			else {
				days -= 31;
			}
		}

	}

	date.day = days;
	
	printf("입력하신 일수 뒤의 날짜는 \n%d년 %d월 %d일", date.year, date.month, date.day);

	switch (days/7)
	{
		case 0: printf(" 월요일 입니다 .");
			break;
		case 1: printf(" 화요일 입니다 .");
			break;
		case 2: printf(" 수요일 입니다 .");
			break;
		case 3: printf(" 목요일 입니다 .");
			break;
		case 4: printf(" 금요일 입니다 .");
			break;
		case 5: printf(" 토요일 입니다 .");
			break;
		case 6: printf(" 일요일 입니다 .");
			break;
		default:
			break;
	}
	
	 
	
	
	


}
