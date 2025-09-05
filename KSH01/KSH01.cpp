#include <stdio.h>
#include <cstring>
#include <random>
#include <string>
#include <iostream>

int main() {

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

	int num = 1;
	int sum = 0;
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

	/*printf("수를 입력하세요 : ");
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
	}*/
	/*std::random_device random;
	std::mt19937 Generate(random());

	printf("균등분포 : \n");
	std::uniform_int_distribution<> uniformDis(1, 100);

	for (int i = 0; i < 10; i++) {
		int number = uniformDis(Generate);
		printf("%d", number);
		if (i < 9) {
			printf(",");
		}
		printf("\n");
	}

	printf("정규분포 : \n");
	std::normal_distribution<> normalDis(80, 10);

	for (int i = 0; i < 10; i++) {
		float number2 = normalDis(Generate);
		printf("%.2f", number2);
		if (i < 9) {
			printf(",");
		}
		printf("\n");
	}*/

	//1번

	//std::random_device random;
	//std::mt19937 Generate(random());
	//std::uniform_int_distribution<> uniformDis(1, 6);
	//int  count = 0;
	//for (int i = 0; i < 1000000; i++) {
	//	int number = uniformDis(Generate);
	//	//printf("%d ", number);
	//	if (number == 6) {
	//		count++;
	//	}
	//	else continue;
	//}
	//printf("주사위 눈 6이 나왔던 횟수 : %d\n",count);

	//2번



	/*enum RSP
	{
		Scissor,
		Rock,
		Paper
	};
	int InputNumber;
	std::random_device random;
	std::mt19937 Generate(random());
	std::uniform_int_distribution<> uniformDis(Scissor, Paper);

	
	for (int i = 0; i < 3; i++) {
		printf("가위바위보 게임\n");
		printf("무엇을 내시겠습니까?\n");
		printf("1.가위 2.바위 3.보\n");
		int number = uniformDis(Generate);
		std::cin >> InputNumber;
		InputNumber--;
		if (InputNumber == Scissor) {
			printf("내가 낸 것 : 가위\n");
		}
		else if (InputNumber == Rock) {
			printf("내가 낸 것 : 바위\n");
		}
		else if (InputNumber == Paper) {
			printf("내가 낸 것 : 보자기\n");
		}
		else printf("해당하는 숫자가 없습니다. \n");

		if (number == Scissor) {
			printf("상대가 낸 것 : 가위\n");
		}
		else if (number == Rock) {
			printf("상대가 낸 것 : 바위\n");
		}
		else if (number == Paper) {
			printf("상대가 낸 것 : 보자기\n");
		}

		
		if (number == InputNumber) {	
			printf("1");
			printf("비겼습니다.\n");
		}
		else if (((number == 3 && InputNumber == 1))) {	
			printf("2");
			printf("이겼습니다\n");
		}
		else if ((number == 1 && InputNumber == 3))  {
			printf("3");
			printf("졌습니다\n");
		}
		else if (number < InputNumber) {
			printf("4");
			printf("이겼습니다\n");
		}
		else if (number > InputNumber)
		{
			printf("5");
			printf("졌습니다\n");
		}*/



	//3번

	/*srand(time(0));
    int player_num=-1;
	int com_num = rand() % 100 + 1;
	int count = 5;

	while (count > 0) {
		printf("생각하는 숫자를 입력하세요 : ");
		std::cin >> player_num;

		if (player_num == com_num) {
			printf("정답입니다");
			break;
		}
		else if (player_num > com_num) {
			printf("더 낮게\n");
			count--;
			printf("기회가 %d번 남았습니다.\n",count);
		}
		else if (player_num < com_num) {
			printf("더 높게\n");
			count--;
			printf("기회가 %d번 남았습니다.\n",count);
		}
		else {
			printf("오류입니다.\n");
		}
	}
	printf("기회가 소진되었습니다.\n");
	printf("맞춰야하는 수는 : %d 였습니다.\n",com_num);*/


	//4번

	/*enum Item
	{
		Potion = 1,
		Evidence = 2 ,
		Flash = 4,
		Axe = 8
	};

	int Item_Inventory = 0;
	int player_select_number;
	int exit = -1;

	
	while (exit!=0) {

		printf("추가 할 아이템의 번호를 선택하세요\n");
		printf("1.포션 2.증거 3.플래쉬 4.도끼 5.삭제 6.현재 인벤토리 확인 7.종료\n");
		std::cin >> player_select_number;

		switch (player_select_number) {
		case 1: printf("인벤토리에 포션을 추가했습니다\n");
			Item_Inventory = Item_Inventory | Potion;
			printf("%d\n", Item_Inventory);
			break;
		case 2: printf("인벤토리에 증거를 추가했습니다\n");
			Item_Inventory = Item_Inventory | Evidence;
			printf("%d\n", Item_Inventory);
			break;
		case 3: printf("인벤토리에 플래쉬를 추가했습니다\n");
			Item_Inventory = Item_Inventory | Flash;
			printf("%d\n", Item_Inventory);
			break;
		case 4: printf("인벤토리에 도끼를 추가했습니다\n");
			Item_Inventory = Item_Inventory | Axe;
			printf("%d\n", Item_Inventory);
			break;
		case 5: printf("사용할 아이템을 선택하세요.\n1.포션 2.증거 3.플래쉬 4.도끼\n");
			std::cin >> player_select_number;
			if (player_select_number == 1) {
				Item_Inventory = Item_Inventory ^ Potion;
			}
			else if (player_select_number == 2) {
				Item_Inventory = Item_Inventory ^ Evidence;
			}
			else if (player_select_number == 3) {
				Item_Inventory = Item_Inventory ^ Flash;
			}
			else if (player_select_number == 4) {
				Item_Inventory = Item_Inventory ^ Axe;
			}
			else printf("선택된 번호가 잘못되었습니다.\n");
			break;
		case 6: 
			printf("현재 인벤토리에\n");
			if ((Item_Inventory & 0b0001) == 0b0001) {
				printf("포션\n");
			}
			else if ((Item_Inventory & 0b0010) == 0b0010) {
				printf("증거\n");
			}
			else if ((Item_Inventory & 0b0100) == 0b0100) {
				printf("증거\n");
			}
			else if ((Item_Inventory & 0b1000) == 0b1000) {
				printf("증거\n");
			}
			printf("가 있습니다.\n");
			break;
		case 7: exit++;
			break;
		default:printf("선택된 번호가 잘못되었습니다.\n");
			break;
		}
	}
	printf("게임이 종료되었습니다.\n");*/

	//5번

	//주사위 게임 만들기
	//초기 세팅
	//플레이어와 컴퓨터 모두 일정 금액(예: 10000원)으로 시작한다.
	//1차 주사위 굴리기
	//게임 시작 시, 플레이어와 컴퓨터가 각각 주사위(1~6)를 한 번 굴린다.
	//각자 주사위 결과를 공개한다.
	//배팅
	//이전 판에서 진 쪽이 배팅 금액을 제시한다.
	//제시한 배팅 금액은 두 사람 모두의 현재 소지 금액 이하이어야 한다.
	//배팅 금액은 두 사람 모두에게서 차감된다.
	//2차 주사위 굴리기
	//다시 플레이어와 컴퓨터가 각각 주사위를 한 번씩 굴린다.
	//(1차 + 2차) 주사위의 합을 계산한다.
	//승패 판정 및 금액 증감
	//합이 더 큰 쪽이 배팅 금액의 총합(즉, 2×배팅금액)을 모두 가져간다.
	//동점일 경우 배팅 금액은 그대로 반환한다.
	//다음 판 진행
	//소지금이 0 이하인 쪽이 나오면 게임 종료.

	/*srand(time(0));
	int Player_money = 10000;
	int Computer_money = 10000;
	int Batting_money=0;
	int Computer_dice_number;
	int Player_dice_number;
	int Computer_dice_sum = 0;
	int Player_dice_sum = 0;

	while (Player_money > 0 && Computer_money > 0) {
		printf("첫 번째 주사위를 굴립니다. \n");

		Computer_dice_number = rand() % 6 + 1;
		Player_dice_number = rand() % 6 + 1;
		Computer_dice_sum += Computer_dice_number;
		Player_dice_sum += Player_dice_number;
		printf("첫 번째 플레이어 주사위의 수 :%d\n", Player_dice_number);
		printf("첫 번째 컴퓨터 주사위의 수 :%d\n", Computer_dice_number);

		printf("이전 주사위 눈에서 진사람이 배팅합니다. 같으면 랜덤배팅됩니다. \n");
		if (Computer_dice_number < Player_dice_number) {

				printf("컴퓨터가 배팅할 금액을 입력합니다. : \n");
				Batting_money = rand() % 2000;

				while ((Batting_money > Computer_money) || (Batting_money > Player_money)) {
					printf("배팅할수 없습니다 금액이 부족합니다. \n");
					printf("다시 배팅금액을 정합니다\n");
					Batting_money = rand() % 2000;
				}
				printf("배팅된 금액은 %d입니다..\n", Batting_money * 2);
				Computer_money -= Batting_money;
				Player_money -= Batting_money;
			
			
		}
		else if (Computer_dice_number > Player_dice_number) {
			printf("플레이어 : 배팅할 금액을 입력하세요 : \n");
			std::cin >> Batting_money;

			while ((Batting_money > Computer_money) || (Batting_money > Player_money)) {
				printf("배팅할수 없습니다 금액이 부족합니다. \n");
				printf("다시 배팅금액을 정합니다\n");
				std::cin >> Batting_money;
			}
			printf("배팅된 금액은 %d입니다..\n", Batting_money * 2);
			Computer_money -= Batting_money;
			Player_money -= Batting_money;
		}
		else {
			printf("눈금이 같으므로 랜덤배팅합니다.\n");
			Batting_money = rand() % 2000;
			while ((Batting_money > Computer_money) || (Batting_money > Player_money)) {
				printf("배팅할수 없습니다 금액이 부족합니다. \n");
				printf("다시 배팅금액을 정합니다\n");
				Batting_money = rand() % 2000;
			}
			printf("배팅된 금액은 %d입니다..\n", Batting_money * 2);
			Computer_money -= Batting_money;
			Player_money -= Batting_money;
		}

		printf("두 번째 주사위를 굴립니다. \n");

		Computer_dice_number = rand() % 6 + 1;
		Player_dice_number = rand() % 6 + 1;
		Computer_dice_sum += Computer_dice_number;
		Player_dice_sum += Player_dice_number;
		printf("두 번째 플레이어 주사위의 수 :%d\n", Player_dice_number);
		printf("두 번째 컴퓨터 주사위의 수 :%d\n", Computer_dice_number);
		printf("컴퓨터 주사위의 합 :%d\n", Computer_dice_sum);
		printf("플레이어 주사위의 합 :%d\n", Player_dice_sum);

		if (Player_dice_sum > Computer_dice_sum) {
			Player_money += Batting_money * 2;
			printf("플레이어가 이겼습니다.\n");
			printf("플레이어의 현재 돈 : %d\n", Player_money);
			printf("컴퓨터의 현재 돈 : %d\n", Computer_money);
		}
		else if (Player_dice_sum < Computer_dice_sum) {
			Computer_money += Batting_money * 2;
			printf("컴퓨터가 이겼습니다.\n");
			printf("플레이어의 현재 돈 : %d\n", Player_money);
			printf("컴퓨터의 현재 돈 : %d\n", Computer_money);
		}
		else {
			printf("합이 서로 같습니다 무승부 \n");
			printf("배팅금액을 돌려받습니다. \n");
			Computer_money += Batting_money;
			Player_money += Batting_money;
			
		}
	}*/

	//6번
	
	srand(time(0));
	int Player_money = 100;
	int Player_select_Number;
	int Player_Batting=999999;
	int Player_Winning_Sum=0;
	int computer_OddEvenNumber;
	bool regameTrigger = false;
	

	while (Player_money>0 || regameTrigger ==true){
		do
		{
			printf("현재금액 : %d\n", Player_money);
			printf("플레이어 : 홀짝을 선택해주세요\n1.홀수 2.짝수\n");
			std::cin >> Player_select_Number;

			if (Player_select_Number > 2) {
				printf("잘못된 입력입니다 .\n\n");
			}
			else {
				continue;
			}

		} while (Player_select_Number>2);
		//보기에 없는 숫자 선택시 반복


		while (((Player_money < Player_Batting) && (regameTrigger == false)) || (Player_Batting >= 0)) {
			printf("\n배팅금액을 입력해주세요\n\n");
			std::cin >> Player_Batting;

			if (Player_Batting > Player_money) {
				printf("\n다시 입력해주세요 . \n\n");

			}
			else if (Player_Batting == 0) {
				printf("\n 0은 입력할수 없습니다. . \n\n");
			}
			else {
				printf("\n배팅이 올바르게 완료되었습니다. \n\n");
			}
		}
		computer_OddEvenNumber = rand() % 2 + 1;//컴퓨터 홀짝 랜덤
		if (regameTrigger == false) {
			Player_money -= Player_Batting;
		}
		else {
			printf("연승 도전 중 \n");
		}
		 //돈 차감
		if (Player_select_Number == computer_OddEvenNumber) {
			do
			{
				printf("컴퓨터가 선택한 수 : %d\n", computer_OddEvenNumber);
				printf("플레이어 승리\n");
				printf("두 가지중 한 가지를 선택해주세요.\n 1.연승도전 2.스탑\n");
				std::cin >> Player_select_Number;

				if (Player_select_Number > 2) {
					printf("잘못된 입력입니다 .\n\n");
				}
				else {
					continue;
				}

			} while (Player_select_Number>2);
			//보기에 없는 숫자 선택시 반복
			
			
			switch (Player_select_Number) {
			case 1:

					Player_Batting *= 2;
					regameTrigger = true;
					printf("현재 배팅금액은 %d 입니다.\n\n",Player_Batting);
					printf("이어서 진행합니다. \n");
					break;
				case 2: 

					if (regameTrigger == true) {
						Player_money += Player_Batting;
					}
					else{
						Player_money += Player_Batting * 2;
					}
					regameTrigger = false;
					printf("\n이긴금액을 소지금액에 추가했습니다\n\n");
					printf("현재금액 : %d\n\n",Player_money);
					break;
				default:
					break;
			}
			
		}
		else {
			regameTrigger = false;
			printf("컴퓨터가 선택한 수 : %d\n", computer_OddEvenNumber);
			printf("플레이어 패배\n\n");
		}
	}
}
	
	


 
