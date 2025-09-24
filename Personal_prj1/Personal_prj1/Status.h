
struct Status
{
	int CurrentHp = 50;
	int Hp = 50;
	int Mp = 0;
	int Exp = 0;

	int Atk = 10;
	int Def = 10;
	int Spd = 20;

	int Counter = 5;
	int Dodge = 10;
	int Crit = 10;
	int CritDmg = 20;

	Status() = default;
	Status(int InHp, int InMp, int InExp,
		int InAtk, int InDef, int InSpd,
		int InCounter, int InDodge, int InCrit, int InCrtiDmg)
		: CurrentHp(InHp), Hp(InHp), Mp(InMp), Exp(InExp),
		Atk(InAtk), Def(InDef), Spd(InSpd),
		Counter(InCounter), Dodge(InDodge), Crit(InCrit), CritDmg(InCrtiDmg) {}
};
