#include <stdio.h>
#include <cstring>
#include <string>
#include <iostream>

int main(){

// 원넓이 구하기
/*float radius;
float circle;

std::cin >> radius;
circle = radius * radius * 3.14;
printf("원의 넓이는 : %f\n",circle);*/

/*float a = 10.0f;
float b = 10.0f;

std::cin >> a >> b;
bool res = a == b;

float epsilon = 0.001f;
a < (b + epsilon);
a > (b - epsilon);

return 0;*/




//숫자를 입력받아 양수인지 음수인지 0인지 출력하기
/*int num;
printf("수를 입력하세요. : ");
std::cin >> num;

if (num > 0) {
	printf("양수입니다");
}
else if (num == 0) {
	printf("0입니다");
}
else {
	printf("음수입니다");
}*/
//숫자를 입력받아 홀수인지 짝수인지 출력하기

//int num;
//printf("수를 입력하세요 : ");
//std::cin >> num;
//
//if (num % 2 == 0) {
//	printf("짝수입니다.\n");
//}
//else {
//	printf("홀수입니다.\n");
//}

//두 수를 입력 받아 더 큰 수를 출력하기.같을 경우는 같다고 출력.

//int num1, num2;
//printf("첫번째 수를 입력하세요 : ");
//std::cin >> num1;
//printf("두번째 수를 입력하세요 : ");
//std::cin >> num2;
//
//if (num1 > num2) {
//	printf("%d\n",num1);
//}
//else if (num1 == num2) {
//	printf("같다\n");
//}
//else {
//	printf("%d\n", num2);
//}



//나이와 키를 입력 받아, 6세 이상, 120cm 이상일 때 롤러코스터 탑승 가능, 그 외에는 불가능으로 출력

//int age, h;
//printf("나이와 키를 입력하세요 : ");
//std::cin >> age >> h;
//
//if (age >= 6 && h >= 120) {
//	printf("롤러코스터 탑승가능\n");
//}
//else {
//
//	printf("롤러코스터 탑승 불가능\n");
//}



//점수를 입력 받아 90점 이상은 A, 80점 이상은 B, 70점 이상은 C, 60점 이상은 D, 그 이하는 F라고 출력하기

//int score;
//printf("점수를 입력하세요. :");
//std::cin >> score;
//
//if (score >= 90) {
//	printf("A\n");
//}
//else if (score >= 80) {
//	printf("B\n");
//}
//else if (score >= 70) {
//	printf("C\n");
//}
//else if (score >= 60) {
//	printf("D\n");
//}
//else {
//	printf("F\n");
//}

//세 과목의 점수를 입력받아, 세 과목 모두 60점 이상이면 "합격", 아니면 "불합격"을 출력하는 프로그램을 작성하세요.
//한과목이라도 40점 미만이면 불합격 출력하기

int score_sub_1, score_sub_2, score_sub_3;
int avg;
printf("첫번째 과목의 점수를 입력하세요. : ");
std::cin >> score_sub_1;
printf("두번째 과목의 점수를 입력하세요. : ");
std::cin >> score_sub_2;
printf("세번째 과목의 점수를 입력하세요. : ");
std::cin >> score_sub_3;

avg = (score_sub_1 + score_sub_2 + score_sub_3) / 3;

printf("평균 : %d\n", avg);
if (avg >= 60) {
	if (score_sub_1 < 40 || score_sub_2 < 40 || score_sub_3 < 40) {
		printf("불합격\n");
	}
	else {
		printf("합격\n");
	}
}
else {
	printf("불합격\n");
}




}