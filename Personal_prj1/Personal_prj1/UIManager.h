#pragma once


class UIManager
{

public:
	void SetUser(Actor* InUser);

private:
	Actor* User;
	Actor* Enemy;

};