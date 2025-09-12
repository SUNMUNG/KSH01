#pragma once

struct Enemy
{
	std::string Name ="고블린";
	float Health =100.0f;
	float Attackpower=10.0f;
	int DropGold=100;

	Enemy() {

	}
	Enemy(std::string name) {
		Name = name;
	}

	Enemy(float modifier) {
		Health = modifier * 10;
		Attackpower = modifier * 5;
		DropGold = modifier * 100;
	}

	Enemy(std::string name, float Health, float attackpower, int dropgold) 
		: Name(name),Health(Health),Attackpower(attackpower),DropGold(dropgold)
	{

		/*Name = name;
		Health = Health;
		Attackpower = attackpower;
		DropGold = dropgold;*/
	}
	Enemy operator+(const Enemy& other) const {
		return Enemy(
			Name+"(+합체)", 
			Health + other.Health,
			Attackpower * 0.7f + other.Attackpower * 0.7f, 
			DropGold + other.DropGold
		);
	}
	Enemy operator-(const Enemy& other) const {
		return Enemy(
			Name + "(-합체)",
			Health - other.Health/2,
			Attackpower - (other.Attackpower)/2,
			DropGold - (other.DropGold)/2
		);
	}
	Enemy operator*(float Multiplier) const {
		return Enemy(
			Name + "(*합체)",
			Health * Multiplier,
			Attackpower * Multiplier,
			DropGold * Multiplier
		);
	}
	Enemy operator*=(float Multiplier){
		return Enemy(
			Name + "(*=합체)",
			this->Health = Health * Multiplier,
			this->Attackpower = Attackpower * Multiplier,
			this->DropGold = DropGold * Multiplier
		);
	}
};

struct Boss
{
	std::string Name = "보스";
	float Helath = 1000.0f;
	float Attakpower = 100.0f;
	int DropGold = 1000;
};

struct Item
{
	std::string Name = "포션";
	float HPAdd = 10.0f;
	int BuyGold = 10;
	int SellGold = BuyGold/10;
};
void practice09121();

void practice09122();

void practice09123();

void printEnemy(Enemy enemy);

void practice09124();

struct Position
{
	int x;
	int y;

	Position(int x, int y) {
		this->x = x;
		this->y = y;
	}
	Position operator+(const Position& other) const {
		return Position(x+other.x,y+other.y);
	}
	Position operator-(const Position& other) const {
		return Position(x - other.x, y - other.y);
	}

};

void SprintXY(Position pos);