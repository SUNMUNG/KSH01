#include "Goblin.h"

void Goblin::MultiHit()
{
	int MultiHitAtk = Atk * 0.5f;
	printf("��Ƽ��Ʈ�� �����߽��ϴ� : %d�� ����\n", MultiHitAtk);
}

Goblin::Goblin(std::string inName, int inHp, int inAtk)
{
	Name = inName;
	Health = inHp;
	Atk = inAtk;
}

Goblin::Goblin(std::string inName)
	:Monster(inName)
{
}
