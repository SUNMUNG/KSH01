#pragma once
class IBattle
{
public:
	virtual void AttackDamage(IBattle* Target) = 0;
	virtual void TakeDamage(int inDamage) = 0;
	virtual ~IBattle() {}

};
