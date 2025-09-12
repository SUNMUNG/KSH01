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

	printf("����� %d�� %d�� %d�� %d���� �Դϴ� .\n",date.year,date.month,date.day,date.weekday);

	printf("���� ���� ��¥�� �����? : \n");

	std::cin >> days;


	//������
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
	

	//��� ����ϰ� ���� �ϼ��߿��� ����
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
	
	printf("�Է��Ͻ� �ϼ� ���� ��¥�� \n%d�� %d�� %d��", date.year, date.month, date.day);

	switch (days/7)
	{
		case 0: printf(" ������ �Դϴ� .");
			break;
		case 1: printf(" ȭ���� �Դϴ� .");
			break;
		case 2: printf(" ������ �Դϴ� .");
			break;
		case 3: printf(" ����� �Դϴ� .");
			break;
		case 4: printf(" �ݿ��� �Դϴ� .");
			break;
		case 5: printf(" ����� �Դϴ� .");
			break;
		case 6: printf(" �Ͽ��� �Դϴ� .");
			break;
		default:
			break;
	}
	
	 
	
	
	


}
