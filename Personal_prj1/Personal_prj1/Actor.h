#pragma once

class Actor
{
public:
	virtual void Attack(Actor* Target);
	virtual void Suffer(int InDamage);

	Actor() = default;
	virtual ~Actor() {};
protected:
	int MaxHp = 50;
	int Hp = 50;
	int Mp = 0;
	int Exp = 0;

	int Atk = 10;
	int Def = 5;
	int Spd = 5;

	int Counter = 10;
	int Dodge = 20;
	int Crit = 10;
};