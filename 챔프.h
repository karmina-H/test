#pragma once
#include "챔프기본.h"
#include <time.h>

static int maiH = 870;
static int zedH = 800;
static int zinH = 750;
class 마스터이 : public character
{
private:
	friend class 아이템;
	int stemina = 870; //체력
	int ad = 70; //공격력
	int defend = 45; //방어력
	int adattack = 25; // 물리관통력
	int adspeed = 1; //공격속도
	int speed = 300; //이속
	int Et = 0; //e재사용 대기시간
	int Rt = 0; //궁극기 재사용 대기시간
public:
	마스터이() : character(stemina, ad, defend, adattack, speed)
	{
		cout << "나의검은 당신의 것이오.." << endl;
	}
	int Hre()
	{
		return 1;
	}
	//피해
	int hurt(int ad, int defend, int adattack)
	{
		return ad + defend - adattack;
	}
	void baseattack(character& c)
	{
		if (c.Hre() == 2)
		{
			zedH -= c.hurt(this->ad, c.Rdefend(), this->adattack);
		}
		else if (c.Hre() == 3)
		{
			zinH -= c.hurt(this->ad, c.Rdefend(), this->adattack);
		}
		cout << c.hurt(this->ad, c.Rdefend(), this->adattack) << "만큼 피해를 입혔습니다" << endl;
		if (Et > 1)
		{
			Et--;
		}
		else if (Et == 1)
		{
			Et--;
			ad -= 30;
			adattack -= 20;
		}
		if (Rt > 1)
		{
			Rt--;
		}
		else if (Rt == 1)
		{
			Rt--;
			speed -= 300;
			adspeed -= 2;
		}
	}

	void Qattack(character& c)
	{
		cout << "우주류 검술!" << endl;
		if (c.Hre() == 2)
		{
			zedH -= c.hurt(this->ad +50, c.Rdefend(), this->adattack);
		}
		cout << c.hurt(this->ad + 50, c.Rdefend(), this->adattack) << "만큼 피해를 입혔습니다"<<endl;
		if (Et > 1)
		{
			Et--;
		}
		else if (Et == 1)
		{
			Et--;
			ad -= 30;
			adattack -= 20;
		}
		if (Rt > 1)
		{
			Rt--;
		}
		else if (Rt == 1)
		{
			Rt--;
			speed -= 300;
			adspeed -= 2;
		}
	}

	void Wattack()
	{
		cout << "정신과 육체.." << endl;
		if (maiH<=770)
		{
			stemina += 100;
		}
		else if (maiH < 870)
		{
			stemina = 870;
		}
		else if (maiH == 870)
		{
			cout << "체력이 모두 다 차 있습니다"<<endl;
		}
		if (Et > 1)
		{
			Et--;
		}
		else if (Et == 1)
		{
			Et--;
			ad -= 30;
			adattack -= 20;
		}
		if (Rt > 0)
		{
			Rt--;
		}
		else if (Rt == 1)
		{
			Rt--;
			speed -= 300;
			adspeed -= 2;
		}

	}

	void Eattack()
	{
		cout << "우주류 검술..!" << endl;
		if (Et == 0)
		{
			ad = ad + 30;
			adattack = adattack += 20;
		}
		else
		{
			cout << "재사용 대기시간이" << Et << "초 남았습니다" << endl;
		}
		if (Rt > 1)
		{
			Rt--;
		}
		else if (Rt == 1)
		{
			Rt--;
			speed -= 300;
			adspeed -= 2;
		}
	}

	void Rattack()
	{
		cout << "생각의 속도~!" << endl;
		if (Rt == 0)
		{
			speed += 300;
			adspeed += 2;
			Rt = 30;
		}
		else
		{
			cout << "재사용 대기시간이" << Rt << "초 남았습니다" << endl;
		}
		if (Et > 1)
		{
			Et--;
		}
		else if (Et == 0)
		{
			ad -= 30;
			adattack -= 20;
		}
	}

	//여기서부터 리턴
	virtual int Rstemina()
	{
		return stemina;
	}
	virtual int Rad()
	{
		return ad;
	}
	virtual int Rdefend()
	{
		return defend;
	}
	virtual int Radattack()
	{
		return adattack;
	}
	//쇼우
	void showdata()
	{
		cout << "마스터이" << endl;
		cout << "체력" << maiH<<endl;
		cout << "공격력" << ad<<endl;
		cout << "방어력" << defend<<endl;
		cout << "물리관통력" << adattack<<endl;
		cout << "공속" << adspeed<<endl;
		cout << "이속" << speed<<endl;
		
	}

};

class 제드 : public character
{
private:
	int stemina = 800; //체력
	int ad = 80; //공격력
	int defend = 40; //방어력
	int adattack = 30; // 물리관통력
	int adspeed = 1; //공격속도
	int speed = 300; //이속
	bool W = false;//그림자 존재 여부
	int Wn = 0;//그림자 존재 하는 시간
public:
	제드() : character(stemina, ad, defend, adattack, speed)
	{
		cout << "보이지 않는 검이 가장 무서운법" << endl;
	}

	int Hre()
	{
		return 2;
	}

	void baseattack(character& c)
	{
		if (c.Hre() == 1)
		{
			maiH -= c.hurt(this->ad, c.Rdefend(), this->adattack);
		}
		else if (c.Hre() == 3)
		{
			 zinH -= c.hurt(this->ad, c.Rdefend(), this->adattack);
		}
		cout << c.hurt(this->ad, c.Rdefend(), this->adattack) << "만큼 피해를 입혔습니다";
		cout << "으억";
	}

	void Qattack(character& c)
	{
		cout << "쉭~" << endl;
		srand(time(NULL));
		int num = rand() % 2;
		if (num == 0)
		{
			cout << "무빙~" << endl;
		}
		else if (num == 1&&W == true)
		{
			cout<<c.hurt(this->ad + 30, c.Rdefend(), this->adattack)*2<<"만큼 피해를 입혔습니다"<<endl;
			if (c.Hre() == 1)
			{
				maiH -= c.hurt(this->ad, c.Rdefend(), this->adattack)*2;
			}
			else if (c.Hre() == 3)
			{
				zinH -= c.hurt(this->ad, c.Rdefend(), this->adattack)*2;
			}
			cout << "으억" << endl;

		}
		else if (num == 1 && W == false)
		{
			cout << c.hurt(this->ad + 30, c.Rdefend(), this->adattack) << "만큼 피해를 입혔습니다" << endl;
			if (c.Hre() == 1)
			{
				maiH -= c.hurt(this->ad+30, c.Rdefend(), this->adattack);
			}
			else if (c.Hre() == 3)
			{
				zinH -= c.hurt(this->ad+30, c.Rdefend(), this->adattack);
			}
			cout << "으억" << endl;
		}

		//그림자 없애기
		if (Wn > 1)
		{
			Wn--;
		}
		else if (Wn == 1)
		{
			Wn--;
			W = false;
		}
	}

	void Wattack()
	{
		if (Wn == 0)
		{
			cout << "슉" << endl;
			W = true;
			Wn = 8;
		}
		else
		{
			cout << "아직 재사용 대기시간이" << Wn << "초 남았습니다" << endl;
		}
	}

	void Eattack(character& c)
	{
		cout << "췩" << endl;
		if (W == true)
		{
			cout << c.hurt(this->ad, c.Rdefend(), this->adattack)*2 << "만큼 피해를 입혔습니다" << endl;
			if (c.Hre() == 1)
			{
				maiH -= c.hurt(this->ad, c.Rdefend(), this->adattack) * 2;
			}
			else if (c.Hre() == 3)
			{
				zinH -= c.hurt(this->ad, c.Rdefend(), this->adattack)*2;
			}
		}
		else if (W == false)
		{
			cout << c.hurt(this->ad + 10, c.Rdefend(), this->adattack) << "만큼 피해를 입혔습니다" << endl;
			if (c.Hre() == 1)
			{
				maiH -= c.hurt(this->ad+10, c.Rdefend(), this->adattack);
			}
			else if (c.Hre() == 3)
			{
				zinH -= c.hurt(this->ad+10, c.Rdefend(), this->adattack);
			}
		}

		if (Wn != 0)
		{
			Wn--;
		}
		if (Wn == 0)
		{
			W = false;
		}
	}

	void Rattack(character& c)
	{
		cout << c.hurt(this->ad + 100, c.Rdefend(), this->adattack) << "만큼 피해를 입혔습니다" << endl;
		cout << "펌~" << endl;
		if (c.Hre() == 1)
		{
			maiH -= c.hurt(this->ad + 100, c.Rdefend(), this->adattack);
		}
		else if (c.Hre() == 3)
		{
			zinH -= c.hurt(this->ad + 100, c.Rdefend(), this->adattack);
		}
		if (Wn != 0)
		{
			Wn--;
		}
	    else if (Wn == 0)
		{
			W = false;
		}
	}

	//여기서부터 리턴하는거
	virtual int Rstemina()
	{
		return stemina;
	}
	virtual int Rad()
	{
		return ad;
	}
	virtual int Rdefend()
	{
		return defend;
	}
	virtual int Radattack()
	{
		return adattack;
	}
	
	void showdata()
	{
		cout << "제드" << endl;
		cout << "체력" << zedH << endl;
		cout << "공격력" << ad << endl;
		cout << "방어력" << defend << endl;
		cout << "물리관통력" << adattack << endl;
		cout << "공속" << adspeed << endl;
		cout << "이속" << speed << endl;

	}
};


class 징크스 : public character
{
private:
	int stemina = 750; //체력
	int ad = 76; //공격력
	int defend = 43; //방어력
	int adattack = 30; // 물리관통력
	int adspeed = 0.4; //공격속도
	int speed = 300; //이속
	int n = 0; // q대기시간
	int Wn = 0; //w대기시간
public:
	징크스() : character(stemina, ad, defend, adattack, speed)
	{
		cout << "씬나게 놀아볼까????" << endl;
	}

	int Hre()
	{
		return 3;
	}

	int hurt(int ad, int defend, int adattack)
	{
		return ad + defend - adattack;
	}
	
	void baseattack(character& c)
	{
		if (c.Hre() == 1)
		{
			maiH -= c.hurt(this->ad, c.Rdefend(), this->adattack);
		}
		else if (c.Hre() == 2)
		{
			zedH -= c.hurt(this->ad, c.Rdefend(), this->adattack);
		}
		cout << c.hurt(this->ad, c.Rdefend(), this->adattack) << "만큼 피해를 입혔습니다";
		if (n > 1)//q대기시간체크
		{
			n--;
		}
		else if (n == 1)
		{
			n--;
			adspeed -= 1.3;
			ad -= 30;
		}
		if (Wn > 1)
		{
			Wn--;
		}
		else if (Wn == 1)
		{
			Wn--;
			adattack -= 30;
		}

	}
	void Qattack(character& c)
	{
		cout << "철컥철컥" << endl;
		if (n == 0)
		{
			n = 3;
			adspeed = adspeed + 1.3;
			ad = ad + 30;
		}
		else
		{
			cout << "재사용 대기시간이" << n << "초 남았습니다" << endl;
		}
		if (Wn > 1)
		{
			Wn--;
		}
		else if (Wn == 1)
		{
			Wn--;
			adattack -= 30;
		}

	}
	void Wattack(character& c)
	{
		cout << "이야아하하" << endl;
		if (Wn != 0)
		{
			adattack += 30;
			Wn = 3;
		}
		else if (Wn == 0)
		{
			cout << "재사용 대기시간이" << Wn << "남았습니다" << endl;
		}
		if (n > 1)//q대기시간체크
		{
			n--;
		}
		else if (n == 1)
		{
			n--;
			adspeed -= 1.3;
			ad -= 30;
		}
	}
	void Eattack(character& c)
	{
		cout << "푸슝푸슝" << endl;
		cout << c.hurt(this->ad + 70, c.Rdefend(), this->adattack) << "만큼 피해를 입혔습니다" << endl;
		if (c.Hre() == 1)
		{
			maiH -= c.hurt(this->ad + 70, c.Rdefend(), this->adattack);
		}
		else if (c.Hre() == 2)
		{
			zedH -= c.hurt(this->ad + 70, c.Rdefend(), this->adattack);
		}
		if (n > 1)//q대기시간체크
		{
			n--;
		}
		else if (n == 1)
		{
			n--;
			adspeed -= 1.3;
			ad -= 30;
		}
		if (Wn > 1)
		{
			Wn--;
		}
		else if (Wn == 1)
		{
			Wn--;
			adattack -= 30;
		}
	}

	void Rattack(character& c)
	{
		cout << "이얏호~" << endl; 
		cout << c.hurt(this->ad + 150, c.Rdefend(), this->adattack) << "만큼 피해를 입혔습니다" << endl;
		if (c.Hre() == 1)
		{
			maiH -= c.hurt(this->ad+150, c.Rdefend(), this->adattack);
		}
		else if (c.Hre() == 2)
		{
			zedH -= c.hurt(this->ad+150, c.Rdefend(), this->adattack);
		}
		if (n > 1)//q대기시간체크
		{
			n--;
		}
		else if (n == 1)
		{
			n--;
			adspeed -= 1.3;
			ad -= 30;
		}
		if (Wn > 1)
		{
			Wn--;
		}
		else if (Wn == 1)
		{
			Wn--;
			adattack -= 30;
		}
	}
	//여기서부터 리턴
	virtual int Rstemina()
	{
		return stemina;
	}
	virtual int Rad()
	{
		return ad;
	}
	virtual int Rdefend()
	{
		return defend;
	}
	virtual int Radattack()
	{
		return adattack;
	}

	void showdata()
	{
		cout << "징크스" << endl;
		cout << "체력" << zinH << endl;
		cout << "공격력" << ad << endl;
		cout << "방어력" << defend << endl;
		cout << "물리관통력" << adattack << endl;
		cout << "공속" << adspeed << endl;
		cout << "이속" << speed << endl;

	}
};