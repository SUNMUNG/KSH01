#include "practice0910.h"
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <random>
#include <string>
#include <limits.h>
#include <direct.h>
#include <fstream>

void practice09101()
{
	char HelloString[]="Hello String";
	char c;
	std::cin >> c;
	isFindChar(HelloString, c);
	
}

void isFindChar(char* HelloStr, int c)
{
	int number = 0;

	while (HelloStr[number] != '\0') {
		if (HelloStr[number] == c) {
			printf("�ش��ϴ� ���ڰ� �ֽ��ϴ�.\n");
			printf("%d ��° �� �ֽ��ϴ�.\n", number);
		}
		number++;
	}
}
int FindCharIndex(const char* TargetString, const char TargetCharacter)
{
	int Index = 0;
	bool IsFind = false;
	while (TargetString[Index] != '\0')
	{
		if (TargetString[Index] == TargetCharacter)
		{
			IsFind = true;
			break;
		}
		Index++;
	}

	if (!IsFind)
	{
		Index = -1;
	}
	return Index;
}

//���ڿ��� ���̸� �����ϴ� �Լ� �����
//int MyStringLength(const char* Target);
void practice09102()
{
	char HelloString[] = "Hello String";
	printf("�迭�� ���̴� %d �Դϴ�.",MyStringLength(HelloString));
}

int MyStringLength(char* Target)
{
	int length = 0;


	while (Target[length] != '\0') {
		length++;
	}


	return length+1;
}

//���ڿ��� �����ϴ� �Լ� �����
//void MyStringCopy(const char* Source, char* Destination);

void practice09103()
{
	int count = 0;
	char Source[] = "Hello String";
	char Destination[] = "";

	MyStringCopy(Source, Destination);

	
	for (int i = 0; i < 13; i++) {
		if (Destination[i] != '\0') {
			printf("%c", Destination[i]);
		}
	}
	
}

void MyStringCopy(char* Source, char* Destination)
{
	int length = 0;
	while (Source[length] != '\0') {
		Destination[length] = Source[length];
		length++;
	}
	Destination[length] = '\0';

}
//���ڿ��� ��ġ�� �Լ� �����(Source �ڿ� Destination�� ������ ���̱�)
//void MyStringCat(char* Source, const char* Destination);

void practice09104()
{
	char Source[] = "Hello";
	char Destination[] = " String";

	MyStringCat(Source, Destination);

}

void MyStringCat(char* Source, char* Destination)
{
	int Slength = 0;
	int Dlength = 0;
	int TotalLen = 0;
	int count=0;

	while (Source[Slength] != '\0') {
		Slength++;
	}
	while (Destination[Dlength] != '\0') {
		Dlength++;
	}
	TotalLen = Slength + Dlength;

	for (int i = Slength; i < TotalLen; i++) {
		Source[i] = Destination[count];
		count++;
	}
	Source[TotalLen+1] = '\0';


	for (int i = 0; i < TotalLen; i++) {
		if (Source[i] != '\0') {
			printf("%c", Source[i]);
		}
	}



}
//���ڿ� �ΰ��� ���ϴ� �Լ� �����
//���� ���� �� ���ڿ��� ������ 0, ù��°�� ������ ����, �ι�°�� ������ ���
//int MyStringCompare(const char* String1, const char* string2);

void practice09105()
{
	char String1[] = "Hello";
	char String2[] = "Hello";
	char String3[] = "Hea";
	char String4[] = "Hez";

	printf("%d", MyStringCompare(String1, String2)); //0
	printf("%d", MyStringCompare(String1, String3)); //1  65+@ >65
	printf("%d", MyStringCompare(String1, String4)); //-1 65+@ < z

}
int MyStringCompare(const char* String1, const char* String2)
{
	int length = 0;

	while (String1[length] != '\0') {
		if (String1[length] != String2[length]) {
			if (String1[length] > String2[length]) {
				return 1;
			}
			else {
				return -1;
			}
		}
		length++;
	}

	return 0;
}
//���ڿ��� �Է� �޾� ������ �����ϴ� �Լ� �����
//int MyAtoI(const char* Source);

void practice09106()
{
	char String[100] = "";


	printf("���ڿ��� �Է����ּ��� : \n");

	std::cin >> String;

	printf("%d", MyAtoI(String));
}
int MyAtoI(const char* Source)
{
	int zari = 1;
	int res = 0;
	int count = 0;
	int num[100];

	while (Source[count] != '\0') {

		num[count] = Source[count] - 48;
		count++;
	}
	for (int i = count - 1; i >= 0; i--) {
		res += num[i] * zari;
		zari *= 10;
	}


	return res;
}
//���ڿ��� �Է� �޾� �Ǽ��� �����ϴ� �Լ� �����
//float MyAtoF(const char* Source);
void practice09107()
{
	char String[100] = "";


	printf("���ڿ��� �Է����ּ��� : \n");

	std::cin >> String;

	printf("%.2f", MyAtoF(String));
}

float MyAtoF(const char* Source)
{

	float zari = 0.01;
	float res = 0.0f;
	int frontNum = 0;
	float BackNum = 0.0f;
	int count = 0;
	int num[100];

	while (Source[count] != '\0') {
		num[count] = Source[count] - 48;
		if (Source[count] == '.') {
			num[count] = -1;
		}
		count++;
	}


	for (int i = count - 1; i >=0; i--) {
		if (num[i] == -1) continue;
		res += num[i] * zari;
		zari *= 10.0f;
	}

	
	


	return res;

}

void practice09108()
{
	const int size = 32;
	int count =0;
	int length = 0;
	char InputString[size];
	printf("������ �Է��ϼ���.\n");
	std::cin.getline(InputString, size);

	while (InputString[length] != '\0') {
		length++;
	}
	
	while (InputString[count] != '\0') {
		if (InputString[count] == ',') {
			break;
		}
		count++;
	}
	for (int i = count + 1; i < length; i++) {
		if(InputString[i] >'a' && InputString[i] < 'z')
		InputString[i] -= 32;

	}
	printf("%s\n", InputString);

}

void practice09109()
{
	char Working[256];

	if (_getcwd(Working, sizeof(Working)) != nullptr) {
		printf("�۾� ���丮 : %s\n", Working);
	}

	ReadFile();

}

void ReadFile()
{
	const char* FilePath = ".\\Data\\TestData.txt";

	std::ifstream InputFile(FilePath);
	if (!InputFile.is_open()) {
		printf("������ ���� �����ϴ�.\n");
		printf("[%s] ��θ� Ȯ���ϼ���..\n", FilePath);
		return;
	}

	std::string FileContents(
		(std::istreambuf_iterator<char>(InputFile)),
		std::istreambuf_iterator<char>());

	printf("���� ������ ������ �����ϴ�.\n");
	printf("%s\n", FileContents.c_str());
}

void practice091010()
{
	std::string str1 = "Hello";
	std::string str2("World");

	const char* Temp1 = "Hello";
	char Temp2[32] = { 0 };

}

void practice091011() {
	//Miro4();
	ReadMap();
}

void ReadMap()
{
	const char* FilePath = ".\\Data\\MapData.txt";
	int Ycount = 0;
	std::string MapData;
	std::ifstream InputFile(FilePath);
	if (!InputFile.is_open()) {
		printf("������ ���� �����ϴ�.\n");
		printf("[%s] ��θ� Ȯ���ϼ���..\n", FilePath);
		return;
	}

	std::string FileContents(
		(std::istreambuf_iterator<char>(InputFile)),
		std::istreambuf_iterator<char>());
	MapData = FileContents.c_str();

	std::string SMaze;
	int zari = 1;
	char MazeXY[6] = { 0 };
	int FMazeHeight = 0;
	int FMazeWidth = 0;

	size_t EnterPos = MapData.find('\n');
	size_t CommaPos = MapData.find(',');

	
	//�����̽� ������ �ѹ� ������ x,y���� ����
	for (int i = 0; i < EnterPos; i++) {
		MazeXY[i] = MapData.at(i);
	}
	MazeXY[EnterPos] = '\0';

	for (int i = static_cast<int>(CommaPos) - 1; i >= 0; i--) {
		FMazeWidth = (MazeXY[i] - '0') * zari;
		zari *= 10;
	}
	zari = 1;
	//static_cast int ����ؼ� ���� �迭������ X
	for (int i = static_cast<int>(EnterPos) - 1; i > static_cast<int>(CommaPos); i--) {
		FMazeHeight = (MazeXY[i] - '0') * zari;
		zari *= 10;
	}
	zari = 1;
	
	//�����
	while (FMazeHeight!=Ycount) {
		int Maxpos = MapData.length();
		int previousPos = EnterPos;
		EnterPos = MapData.find('\n', EnterPos + 1);

		if (EnterPos == std::string::npos) EnterPos = Maxpos;
		for (int i = previousPos; i <= EnterPos; i++) {
			if (MapData[i] == '\n')continue;

			if (MapData[i] == '1') {
				printf("# ");
			}
			else if (MapData[i] == '0') {
				printf(". ");
			}
			else if (MapData[i] == '2') {
				printf("S ");
			}
			else if (MapData[i] == '3') {
				printf("E ");
			}
			else if (MapData[i] == '4') {
				printf("P ");
			}
		}
		Ycount++;
		printf("\n");
	}
	int PlayerPos = 21;
	//38
	//������ �迭������ �� ( n-���ΰ��� ) �Ʒ� (n+���ΰ���) �翷 +-1
	//�̵����� ���� ���
	printf("w(W): ��, s(S): �Ʒ�, a(A): ����, d(D): ������\n");
	printf("�̵� ������ ���� : ");
	if (MapData[PlayerPos-1 + FMazeWidth-1] == '0') {
		printf("s(S): �Ʒ�, ");
	}
	if (MapData[PlayerPos - FMazeWidth] == '0') {
		printf("w(W): ��, ");
	}
	if (MapData[PlayerPos -1] == '0') {
		printf("a(A): ����, ");
	}
	if (MapData[PlayerPos + 1] == '0') {
		printf("d(D): ������ ");
	}

	
	
}


	void Miro4()
	{
		// �̷� ũ��
		const int MazeHeight = 10;
		const int MazeWidth = 20;
		int PlayerPosX = 1;
		int PlayerPosY = 1;
		int EndPosX = 18;
		int EndPosY = 7;
		char PlayerMove;

		
	
		// �̷� �迭
		int Maze[MazeHeight][MazeWidth] =
		{//0										//19
			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{1,2,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,1,0,1},
			{1,1,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,0,1},
			{1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1},
			{1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
			{1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1},
			{1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1},
			{1,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,3,1},
			{1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
	/*9*/	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
		};


		//�����Ȳ �̷� ���
		while (Maze[PlayerPosY][PlayerPosX] != Maze[EndPosY][EndPosX]) {

			for (int i = 0; i < MazeHeight; i++) {
				for (int j = 0; j < MazeWidth; j++) {
					if (Maze[i][j] == 1) {
						printf("# ");
					}
					else if (Maze[i][j] == 0) {
						printf(". ");
					}
					else if (Maze[i][j] == 2) {
						printf("S ");
					}
					else if (Maze[i][j] == 3) {
						printf("E ");
					}
					else if (Maze[i][j] == 4) {
						printf("P ");
					}
					else {
						printf("@ ");
					}
				}
				printf("\n");
			}

			//�̵����� ���� ���
			printf("w(W): ��, s(S): �Ʒ�, a(A): ����, d(D): ������\n");
			printf("�̵� ������ ���� : ");
			if (Maze[PlayerPosY + 1][PlayerPosX] == 0) {
				printf("s(S): �Ʒ�, ");
			}
			if (Maze[PlayerPosY - 1][PlayerPosX] == 0) {
				printf("w(W): ��, ");
			}
			if (Maze[PlayerPosY][PlayerPosX - 1] == 0) {
				printf("a(A): ����, ");
			}
			if (Maze[PlayerPosY][PlayerPosX + 1] == 0) {
				printf("d(D): ������ ");
			}

			printf("\n�̵� ������ �Է��ϼ���.\n");
			std::cin >> PlayerMove;

			//�� �Ǵ� ���� ������ ��ǥ�̵�
			if (PlayerMove == 'W' || PlayerMove == 'w') {
				if (Maze[PlayerPosY - 1][PlayerPosX] == 1) {
					printf("�̵��Ҽ� �����ϴ�.\n");
				}
				else {
					Maze[PlayerPosY][PlayerPosX] = 0;
					PlayerPosY -= 1;
				}
			}
			else if (PlayerMove == 'S' || PlayerMove == 's') {
				if (Maze[PlayerPosY + 1][PlayerPosX] == 1) {
					printf("�̵��Ҽ� �����ϴ�.\n");
				}
				else {
					Maze[PlayerPosY][PlayerPosX] = 0;
					PlayerPosY += 1;
				}
			}
			else if (PlayerMove == 'A' || PlayerMove == 'a') {
				if (Maze[PlayerPosY][PlayerPosX - 1] == 1) {
					printf("�̵��Ҽ� �����ϴ�.\n");
				}
				else {
					Maze[PlayerPosY][PlayerPosX] = 0;
					PlayerPosX -= 1;
				}
			}
			else if (PlayerMove == 'D' || PlayerMove == 'd') {
				if (Maze[PlayerPosY][PlayerPosX + 1] == 1) {
					printf("�̵��Ҽ� �����ϴ�.\n");
				}
				else {
					Maze[PlayerPosY][PlayerPosX] = 0;
					PlayerPosX += 1;
				}
			}
			else {
				printf("�ٸ�Ű�� �Է��Ͽ����ϴ�.\n");
			}
			//�̵��� ��ǥ�� �÷��̾� �̵�
			Maze[PlayerPosY][PlayerPosX] = 4; //4 �� �÷��̾�
		}


		//������ �̷θ�� ����Ʈ
		for (int i = 0; i < MazeHeight; i++) {
			for (int j = 0; j < MazeWidth; j++) {
				if (Maze[i][j] == 1) {
					printf("# ");
				}
				else if (Maze[i][j] == 0) {
					printf(". ");
				}
				else if (Maze[i][j] == 2) {
					printf("S ");
				}
				else if (Maze[i][j] == 3) {
					printf("E ");
				}
				else if (Maze[i][j] == 4) {
					printf("P ");
				}
				else {
					printf("@ ");
				}
			}
			printf("\n");
		}
		printf("�ⱸ�� �����Ͽ����ϴ�.\n");
	}


