#include "test.h"
#include <stdio.h>
int Sum(int n, int m) {
	int sum = 0;
	sum = n + m;
	return sum;
}

void printHelloworld()
{
	printf("Hello world");
}

int multiply(int n, int m)
{
	int mul = 0;
	mul = n * m;
	return mul;
}

int division(int n, int m)
{
	int div=0;
	div = n / m;
	return div;
}

int minus(int n, int m)
{
	int minus = 0;
	minus = n - m;
	return minus;
}

int TestRecurcive(int num)
{
	printf("Recucive %d\n",num);
	if (num > 0) {
		return TestRecurcive(num - 1);
	}
	return 0;
}

int factorial(int num)
{
	int res = 1;

	res = res* factorial(num - 1);

	return num - 1;
}

void oldtales()
{
	/*int num;
	printf("����� �Է��ϼ��� : ");
	std::cin >> num;

	if ((num & 1) == 1) {
		printf("Ȧ���Դϴ�.\n");
	}
	else {
		printf("¦���Դϴ�.\n");
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
		printf("���� ����ؼ� �Է��ϼ��� 0�� �Է��ϸ� ������ ���� ���: ");
		std::cin >> num;
		sum += num;
	}
	printf("���� : %d\n", sum);*/

	//1-2.
	/*do
	{
		printf("���� ����ؼ� �Է��ϼ��� 0�� �Է��ϸ� ������ ���� ���: ");
		std::cin >> num;
		sum += num;

	} while (num != 0);
	printf("���� : %d\n", sum);*/

	//2.
	/*printf("���� �Է��ϼ��� : ");
	std::cin >> num;

	for (int i = 1; i < 10; i++) {
		printf("%d * %d = %d\n", num, i, num * i);
	}*/

	//3.
	/*printf("���� �Է��ϼ��� : ");
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

	/*printf("���� �Է��ϼ��� : ");
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

	printf("�յ���� : \n");
	std::uniform_int_distribution<> uniformDis(1, 100);

	for (int i = 0; i < 10; i++) {
		int number = uniformDis(Generate);
		printf("%d", number);
		if (i < 9) {
			printf(",");
		}
		printf("\n");
	}

	printf("���Ժ��� : \n");
	std::normal_distribution<> normalDis(80, 10);

	for (int i = 0; i < 10; i++) {
		float number2 = normalDis(Generate);
		printf("%.2f", number2);
		if (i < 9) {
			printf(",");
		}
		printf("\n");
	}*/

	//1��

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
	//printf("�ֻ��� �� 6�� ���Դ� Ƚ�� : %d\n",count);

	//2��



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
		printf("���������� ����\n");
		printf("������ ���ðڽ��ϱ�?\n");
		printf("1.���� 2.���� 3.��\n");
		int number = uniformDis(Generate);
		std::cin >> InputNumber;
		InputNumber--;
		if (InputNumber == Scissor) {
			printf("���� �� �� : ����\n");
		}
		else if (InputNumber == Rock) {
			printf("���� �� �� : ����\n");
		}
		else if (InputNumber == Paper) {
			printf("���� �� �� : ���ڱ�\n");
		}
		else printf("�ش��ϴ� ���ڰ� �����ϴ�. \n");

		if (number == Scissor) {
			printf("��밡 �� �� : ����\n");
		}
		else if (number == Rock) {
			printf("��밡 �� �� : ����\n");
		}
		else if (number == Paper) {
			printf("��밡 �� �� : ���ڱ�\n");
		}


		if (number == InputNumber) {
			printf("1");
			printf("�����ϴ�.\n");
		}
		else if (((number == 3 && InputNumber == 1))) {
			printf("2");
			printf("�̰���ϴ�\n");
		}
		else if ((number == 1 && InputNumber == 3))  {
			printf("3");
			printf("�����ϴ�\n");
		}
		else if (number < InputNumber) {
			printf("4");
			printf("�̰���ϴ�\n");
		}
		else if (number > InputNumber)
		{
			printf("5");
			printf("�����ϴ�\n");
		}*/



		//3��

		/*srand(time(0));
		int player_num=-1;
		int com_num = rand() % 100 + 1;
		int count = 5;

		while (count > 0) {
			printf("�����ϴ� ���ڸ� �Է��ϼ��� : ");
			std::cin >> player_num;

			if (player_num == com_num) {
				printf("�����Դϴ�");
				break;
			}
			else if (player_num > com_num) {
				printf("�� ����\n");
				count--;
				printf("��ȸ�� %d�� ���ҽ��ϴ�.\n",count);
			}
			else if (player_num < com_num) {
				printf("�� ����\n");
				count--;
				printf("��ȸ�� %d�� ���ҽ��ϴ�.\n",count);
			}
			else {
				printf("�����Դϴ�.\n");
			}
		}
		printf("��ȸ�� �����Ǿ����ϴ�.\n");
		printf("������ϴ� ���� : %d �����ϴ�.\n",com_num);*/


		//4��

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

			printf("�߰� �� �������� ��ȣ�� �����ϼ���\n");
			printf("1.���� 2.���� 3.�÷��� 4.���� 5.���� 6.���� �κ��丮 Ȯ�� 7.����\n");
			std::cin >> player_select_number;

			switch (player_select_number) {
			case 1: printf("�κ��丮�� ������ �߰��߽��ϴ�\n");
				Item_Inventory = Item_Inventory | Potion;
				printf("%d\n", Item_Inventory);
				break;
			case 2: printf("�κ��丮�� ���Ÿ� �߰��߽��ϴ�\n");
				Item_Inventory = Item_Inventory | Evidence;
				printf("%d\n", Item_Inventory);
				break;
			case 3: printf("�κ��丮�� �÷����� �߰��߽��ϴ�\n");
				Item_Inventory = Item_Inventory | Flash;
				printf("%d\n", Item_Inventory);
				break;
			case 4: printf("�κ��丮�� ������ �߰��߽��ϴ�\n");
				Item_Inventory = Item_Inventory | Axe;
				printf("%d\n", Item_Inventory);
				break;
			case 5: printf("����� �������� �����ϼ���.\n1.���� 2.���� 3.�÷��� 4.����\n");
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
				else printf("���õ� ��ȣ�� �߸��Ǿ����ϴ�.\n");
				break;
			case 6:
				printf("���� �κ��丮��\n");
				if ((Item_Inventory & 0b0001) == 0b0001) {
					printf("����\n");
				}
				else if ((Item_Inventory & 0b0010) == 0b0010) {
					printf("����\n");
				}
				else if ((Item_Inventory & 0b0100) == 0b0100) {
					printf("����\n");
				}
				else if ((Item_Inventory & 0b1000) == 0b1000) {
					printf("����\n");
				}
				printf("�� �ֽ��ϴ�.\n");
				break;
			case 7: exit++;
				break;
			default:printf("���õ� ��ȣ�� �߸��Ǿ����ϴ�.\n");
				break;
			}
		}
		printf("������ ����Ǿ����ϴ�.\n");*/

		//5��

		//�ֻ��� ���� �����
		//�ʱ� ����
		//�÷��̾�� ��ǻ�� ��� ���� �ݾ�(��: 10000��)���� �����Ѵ�.
		//1�� �ֻ��� ������
		//���� ���� ��, �÷��̾�� ��ǻ�Ͱ� ���� �ֻ���(1~6)�� �� �� ������.
		//���� �ֻ��� ����� �����Ѵ�.
		//����
		//���� �ǿ��� �� ���� ���� �ݾ��� �����Ѵ�.
		//������ ���� �ݾ��� �� ��� ����� ���� ���� �ݾ� �����̾�� �Ѵ�.
		//���� �ݾ��� �� ��� ��ο��Լ� �����ȴ�.
		//2�� �ֻ��� ������
		//�ٽ� �÷��̾�� ��ǻ�Ͱ� ���� �ֻ����� �� ���� ������.
		//(1�� + 2��) �ֻ����� ���� ����Ѵ�.
		//���� ���� �� �ݾ� ����
		//���� �� ū ���� ���� �ݾ��� ����(��, 2�����ñݾ�)�� ��� ��������.
		//������ ��� ���� �ݾ��� �״�� ��ȯ�Ѵ�.
		//���� �� ����
		//�������� 0 ������ ���� ������ ���� ����.

		/*srand(time(0));
		int Player_money = 10000;
		int Computer_money = 10000;
		int Batting_money=0;
		int Computer_dice_number;
		int Player_dice_number;
		int Computer_dice_sum = 0;
		int Player_dice_sum = 0;

		while (Player_money > 0 && Computer_money > 0) {
			printf("ù ��° �ֻ����� �����ϴ�. \n");

			Computer_dice_number = rand() % 6 + 1;
			Player_dice_number = rand() % 6 + 1;
			Computer_dice_sum += Computer_dice_number;
			Player_dice_sum += Player_dice_number;
			printf("ù ��° �÷��̾� �ֻ����� �� :%d\n", Player_dice_number);
			printf("ù ��° ��ǻ�� �ֻ����� �� :%d\n", Computer_dice_number);

			printf("���� �ֻ��� ������ ������� �����մϴ�. ������ �������õ˴ϴ�. \n");
			if (Computer_dice_number < Player_dice_number) {

					printf("��ǻ�Ͱ� ������ �ݾ��� �Է��մϴ�. : \n");
					Batting_money = rand() % 2000;

					while ((Batting_money > Computer_money) || (Batting_money > Player_money)) {
						printf("�����Ҽ� �����ϴ� �ݾ��� �����մϴ�. \n");
						printf("�ٽ� ���ñݾ��� ���մϴ�\n");
						Batting_money = rand() % 2000;
					}
					printf("���õ� �ݾ��� %d�Դϴ�..\n", Batting_money * 2);
					Computer_money -= Batting_money;
					Player_money -= Batting_money;


			}
			else if (Computer_dice_number > Player_dice_number) {
				printf("�÷��̾� : ������ �ݾ��� �Է��ϼ��� : \n");
				std::cin >> Batting_money;

				while ((Batting_money > Computer_money) || (Batting_money > Player_money)) {
					printf("�����Ҽ� �����ϴ� �ݾ��� �����մϴ�. \n");
					printf("�ٽ� ���ñݾ��� ���մϴ�\n");
					std::cin >> Batting_money;
				}
				printf("���õ� �ݾ��� %d�Դϴ�..\n", Batting_money * 2);
				Computer_money -= Batting_money;
				Player_money -= Batting_money;
			}
			else {
				printf("������ �����Ƿ� ���������մϴ�.\n");
				Batting_money = rand() % 2000;
				while ((Batting_money > Computer_money) || (Batting_money > Player_money)) {
					printf("�����Ҽ� �����ϴ� �ݾ��� �����մϴ�. \n");
					printf("�ٽ� ���ñݾ��� ���մϴ�\n");
					Batting_money = rand() % 2000;
				}
				printf("���õ� �ݾ��� %d�Դϴ�..\n", Batting_money * 2);
				Computer_money -= Batting_money;
				Player_money -= Batting_money;
			}

			printf("�� ��° �ֻ����� �����ϴ�. \n");

			Computer_dice_number = rand() % 6 + 1;
			Player_dice_number = rand() % 6 + 1;
			Computer_dice_sum += Computer_dice_number;
			Player_dice_sum += Player_dice_number;
			printf("�� ��° �÷��̾� �ֻ����� �� :%d\n", Player_dice_number);
			printf("�� ��° ��ǻ�� �ֻ����� �� :%d\n", Computer_dice_number);
			printf("��ǻ�� �ֻ����� �� :%d\n", Computer_dice_sum);
			printf("�÷��̾� �ֻ����� �� :%d\n", Player_dice_sum);

			if (Player_dice_sum > Computer_dice_sum) {
				Player_money += Batting_money * 2;
				printf("�÷��̾ �̰���ϴ�.\n");
				printf("�÷��̾��� ���� �� : %d\n", Player_money);
				printf("��ǻ���� ���� �� : %d\n", Computer_money);
			}
			else if (Player_dice_sum < Computer_dice_sum) {
				Computer_money += Batting_money * 2;
				printf("��ǻ�Ͱ� �̰���ϴ�.\n");
				printf("�÷��̾��� ���� �� : %d\n", Player_money);
				printf("��ǻ���� ���� �� : %d\n", Computer_money);
			}
			else {
				printf("���� ���� �����ϴ� ���º� \n");
				printf("���ñݾ��� �����޽��ϴ�. \n");
				Computer_money += Batting_money;
				Player_money += Batting_money;

			}
		}*/

		//6��

		//srand(time(0));
		//int Player_money = 100;
		//int Player_select_Number;
		//int Player_Batting=999999;
		//int Player_Winning_Sum=0;
		//int computer_OddEvenNumber;
		//bool regameTrigger = false;
		//
		//while (Player_money>0 || regameTrigger ==true){
		//	do
		//	{
		//		printf("����ݾ� : %d\n", Player_money);
		//		printf("�÷��̾� : Ȧ¦�� �������ּ���\n1.Ȧ�� 2.¦��\n");
		//		std::cin >> Player_select_Number;
		//		if (Player_select_Number > 2) {
		//			printf("�߸��� �Է��Դϴ� .\n\n");
		//		}
		//		else {
		//			continue;
		//		}
		//	} while (Player_select_Number>2);
		//	//���⿡ ���� ���� ���ý� �ݺ�
		//	while (((Player_money < Player_Batting) && (regameTrigger == false)) || (Player_Batting >= 0)) {
		//		printf("\n���ñݾ��� �Է����ּ���\n\n");
		//		std::cin >> Player_Batting;
		//		if (Player_Batting > Player_money) {
		//			printf("\n�ٽ� �Է����ּ��� . \n\n");
		//		}
		//		else if (Player_Batting == 0) {
		//			printf("\n 0�� �Է��Ҽ� �����ϴ�. . \n\n");
		//		}
		//		else {
		//			printf("\n������ �ùٸ��� �Ϸ�Ǿ����ϴ�. \n\n");
		//		}
		//	}
		//	computer_OddEvenNumber = rand() % 2 + 1;//��ǻ�� Ȧ¦ ����
		//	if (regameTrigger == false) {
		//		Player_money -= Player_Batting;
		//	}
		//	else {
		//		printf("���� ���� �� \n");
		//	}
		//	 //�� ����
		//	if (Player_select_Number == computer_OddEvenNumber) {
		//		do
		//		{
		//			printf("��ǻ�Ͱ� ������ �� : %d\n", computer_OddEvenNumber);
		//			printf("�÷��̾� �¸�\n");
		//			printf("�� ������ �� ������ �������ּ���.\n 1.���µ��� 2.��ž\n");
		//			std::cin >> Player_select_Number;
		//			if (Player_select_Number > 2) {
		//				printf("�߸��� �Է��Դϴ� .\n\n");
		//			}
		//			else {
		//				continue;
		//			}
		//		} while (Player_select_Number>2);
		//		//���⿡ ���� ���� ���ý� �ݺ�
		//		
		//		
		//		switch (Player_select_Number) {
		//		case 1:
		//				Player_Batting *= 2;
		//				regameTrigger = true;
		//				printf("���� ���ñݾ��� %d �Դϴ�.\n\n",Player_Batting);
		//				printf("�̾ �����մϴ�. \n");
		//				break;
		//			case 2: 
		//				if (regameTrigger == true) {
		//					Player_money += Player_Batting;
		//				}
		//				else{
		//					Player_money += Player_Batting * 2;
		//				}
		//				regameTrigger = false;
		//				printf("\n�̱�ݾ��� �����ݾ׿� �߰��߽��ϴ�\n\n");
		//				printf("����ݾ� : %d\n\n",Player_money);
		//				break;
		//			default:
		//				break;
		//		}
		//		
		//	}
		//	else {
		//		regameTrigger = false;
		//		printf("��ǻ�Ͱ� ������ �� : %d\n", computer_OddEvenNumber);
		//		printf("�÷��̾� �й�\n\n");
		//	}
		//}
}

void day0905()
{
}
