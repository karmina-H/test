#pragma once
#include<iostream>
using namespace std;
#include "아이템.h"

class character
{
private:
	int stemina; //체력
	int* ptr = &stemina;
	int ad; //공격력
	int defend; //방어력
	int adattack; // 물리관통력
	int speed; //이속
public:
	character(int s, int a, int d, int aa, int speed) : stemina(s), ad(a), defend(d), adattack(aa), speed(speed)
	{}
	virtual void baseattack()
	{}
	virtual void Qattack()
	{}
	virtual void Wattack()
	{}
	virtual void Eattack()
	{}
	virtual void Rattack()
	{}
	int hurt(int ad, int defend, int adattack)
	{
		return ad + defend - adattack;
	}
	virtual int Hre() = 0;
	virtual int Rstemina() = 0;
	virtual int Rad() = 0;
	virtual int Rdefend() = 0;
	virtual int Radattack() = 0;
	
};