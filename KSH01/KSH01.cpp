#include <stdio.h>
#include <cstring>
#include <string>
#include <iostream>

int main(){
	
	/*int num;
	printf("양수를 입력하세요 : ");
	std::cin >> num;

	if ((num & 1) == 1) {
		printf("홀수입니다.\n");
	}
	else {
		printf("짝수입니다.\n");
	}*/

	//for (int i = 0; i < 10; i++) {
	//	printf("(for)Hello world : %d\n", i);
	//}
	//int count=1;

	//do
	//{
	//	printf("(while)Hello world : %d\n", count);
	//	count++;
	//} while ((count % 3) != 0);
	
	int num=1;
	int sum=0;
	//1.
	/*while (num != 0) {
		printf("수를 계속해서 입력하세요 0을 입력하면 종료후 합을 출력: ");
		std::cin >> num;
		sum += num;
	}
	printf("합은 : %d\n", sum);*/

	//1-2.
	/*do
	{
		printf("수를 계속해서 입력하세요 0을 입력하면 종료후 합을 출력: ");
		std::cin >> num;
		sum += num;

	} while (num != 0);
	printf("합은 : %d\n", sum);*/

	//2.
	/*printf("수를 입력하세요 : ");
	std::cin >> num;

	for (int i = 1; i < 10; i++) {
		printf("%d * %d = %d\n", num, i, num * i);
	}*/

	//3.
	/*printf("수를 입력하세요 : ");
	std::cin >> num;

	for (int i = 0; i < num; i++) {
		if (i % 2 != 0) {
			printf("%d ", i);
		}
		else continue;
	}*/


	//4.
	/*for (int i = 0; i <= 100; i++) {
		if (i % 7 == 0) {
			printf("%d ", i);
		}
		else continue;
	}*/

	printf("수를 입력하세요 : ");
	std::cin >> num;

	for (int i = 0; i < num; i++) {
		for (int j = 0; j <num-i ; j++) {
			printf(" ");
		}

		for (int k = 0; k < i+1; k++) {
			printf("*");
		}

		for (int l = 0; l < i; l++) {
			printf("*");
		}
		printf("\n");
	}
	
}

