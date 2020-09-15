#pragma once
#include "Ã¨ÇÁ±âº».h"
#include <time.h>

static int maiH = 870;
static int zedH = 800;
static int zinH = 750;
class ¸¶½ºÅÍÀÌ : public character
{
private:
	friend class ¾ÆÀÌÅÛ;
	int stemina = 870; //Ã¼·Â
	int ad = 70; //°ø°İ·Â
	int defend = 45; //¹æ¾î·Â
	int adattack = 25; // ¹°¸®°üÅë·Â
	int adspeed = 1; //°ø°İ¼Óµµ
	int speed = 300; //ÀÌ¼Ó
	int Et = 0; //eÀç»ç¿ë ´ë±â½Ã°£
	int Rt = 0; //±Ã±Ø±â Àç»ç¿ë ´ë±â½Ã°£
public:
	¸¶½ºÅÍÀÌ() : character(stemina, ad, defend, adattack, speed)
	{
		cout << "³ªÀÇ°ËÀº ´ç½ÅÀÇ °ÍÀÌ¿À.." << endl;
	}
	int Hre()
	{
		return 1;
	}
	//ÇÇÇØ
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
		cout << c.hurt(this->ad, c.Rdefend(), this->adattack) << "¸¸Å­ ÇÇÇØ¸¦ ÀÔÇû½À´Ï´Ù" << endl;
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
		cout << "¿ìÁÖ·ù °Ë¼ú!" << endl;
		if (c.Hre() == 2)
		{
			zedH -= c.hurt(this->ad +50, c.Rdefend(), this->adattack);
		}
		cout << c.hurt(this->ad + 50, c.Rdefend(), this->adattack) << "¸¸Å­ ÇÇÇØ¸¦ ÀÔÇû½À´Ï´Ù"<<endl;
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
		cout << "Á¤½Å°ú À°Ã¼.." << endl;
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
			cout << "Ã¼·ÂÀÌ ¸ğµÎ ´Ù Â÷ ÀÖ½À´Ï´Ù"<<endl;
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
		cout << "¿ìÁÖ·ù °Ë¼ú..!" << endl;
		if (Et == 0)
		{
			ad = ad + 30;
			adattack = adattack += 20;
		}
		else
		{
			cout << "Àç»ç¿ë ´ë±â½Ã°£ÀÌ" << Et << "ÃÊ ³²¾Ò½À´Ï´Ù" << endl;
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
		cout << "»ı°¢ÀÇ ¼Óµµ~!" << endl;
		if (Rt == 0)
		{
			speed += 300;
			adspeed += 2;
			Rt = 30;
		}
		else
		{
			cout << "Àç»ç¿ë ´ë±â½Ã°£ÀÌ" << Rt << "ÃÊ ³²¾Ò½À´Ï´Ù" << endl;
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

	//¿©±â¼­ºÎÅÍ ¸®ÅÏ
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
	//¼î¿ì
	void showdata()
	{
		cout << "¸¶½ºÅÍÀÌ" << endl;
		cout << "Ã¼·Â" << maiH<<endl;
		cout << "°ø°İ·Â" << ad<<endl;
		cout << "¹æ¾î·Â" << defend<<endl;
		cout << "¹°¸®°üÅë·Â" << adattack<<endl;
		cout << "°ø¼Ó" << adspeed<<endl;
		cout << "ÀÌ¼Ó" << speed<<endl;
		
	}

};

class Á¦µå : public character
{
private:
	int stemina = 800; //Ã¼·Â
	int ad = 80; //°ø°İ·Â
	int defend = 40; //¹æ¾î·Â
	int adattack = 30; // ¹°¸®°üÅë·Â
	int adspeed = 1; //°ø°İ¼Óµµ
	int speed = 300; //ÀÌ¼Ó
	bool W = false;//±×¸²ÀÚ Á¸Àç ¿©ºÎ
	int Wn = 0;//±×¸²ÀÚ Á¸Àç ÇÏ´Â ½Ã°£
public:
	Á¦µå() : character(stemina, ad, defend, adattack, speed)
	{
		cout << "º¸ÀÌÁö ¾Ê´Â °ËÀÌ °¡Àå ¹«¼­¿î¹ı" << endl;
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
		cout << c.hurt(this->ad, c.Rdefend(), this->adattack) << "¸¸Å­ ÇÇÇØ¸¦ ÀÔÇû½À´Ï´Ù";
		cout << "À¸¾ï";
	}

	void Qattack(character& c)
	{
		cout << "½­~" << endl;
		srand(time(NULL));
		int num = rand() % 2;
		if (num == 0)
		{
			cout << "¹«ºù~" << endl;
		}
		else if (num == 1&&W == true)
		{
			cout<<c.hurt(this->ad + 30, c.Rdefend(), this->adattack)*2<<"¸¸Å­ ÇÇÇØ¸¦ ÀÔÇû½À´Ï´Ù"<<endl;
			if (c.Hre() == 1)
			{
				maiH -= c.hurt(this->ad, c.Rdefend(), this->adattack)*2;
			}
			else if (c.Hre() == 3)
			{
				zinH -= c.hurt(this->ad, c.Rdefend(), this->adattack)*2;
			}
			cout << "À¸¾ï" << endl;

		}
		else if (num == 1 && W == false)
		{
			cout << c.hurt(this->ad + 30, c.Rdefend(), this->adattack) << "¸¸Å­ ÇÇÇØ¸¦ ÀÔÇû½À´Ï´Ù" << endl;
			if (c.Hre() == 1)
			{
				maiH -= c.hurt(this->ad+30, c.Rdefend(), this->adattack);
			}
			else if (c.Hre() == 3)
			{
				zinH -= c.hurt(this->ad+30, c.Rdefend(), this->adattack);
			}
			cout << "À¸¾ï" << endl;
		}

		//±×¸²ÀÚ ¾ø¾Ö±â
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
			cout << "½µ" << endl;
			W = true;
			Wn = 8;
		}
		else
		{
			cout << "¾ÆÁ÷ Àç»ç¿ë ´ë±â½Ã°£ÀÌ" << Wn << "ÃÊ ³²¾Ò½À´Ï´Ù" << endl;
		}
	}

	void Eattack(character& c)
	{
		cout << "®g" << endl;
		if (W == true)
		{
			cout << c.hurt(this->ad, c.Rdefend(), this->adattack)*2 << "¸¸Å­ ÇÇÇØ¸¦ ÀÔÇû½À´Ï´Ù" << endl;
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
			cout << c.hurt(this->ad + 10, c.Rdefend(), this->adattack) << "¸¸Å­ ÇÇÇØ¸¦ ÀÔÇû½À´Ï´Ù" << endl;
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
		cout << c.hurt(this->ad + 100, c.Rdefend(), this->adattack) << "¸¸Å­ ÇÇÇØ¸¦ ÀÔÇû½À´Ï´Ù" << endl;
		cout << "Æß~" << endl;
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

	//¿©±â¼­ºÎÅÍ ¸®ÅÏÇÏ´Â°Å
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
		cout << "Á¦µå" << endl;
		cout << "Ã¼·Â" << zedH << endl;
		cout << "°ø°İ·Â" << ad << endl;
		cout << "¹æ¾î·Â" << defend << endl;
		cout << "¹°¸®°üÅë·Â" << adattack << endl;
		cout << "°ø¼Ó" << adspeed << endl;
		cout << "ÀÌ¼Ó" << speed << endl;

	}
};


class Â¡Å©½º : public character
{
private:
	int stemina = 750; //Ã¼·Â
	int ad = 76; //°ø°İ·Â
	int defend = 43; //¹æ¾î·Â
	int adattack = 30; // ¹°¸®°üÅë·Â
	int adspeed = 0.4; //°ø°İ¼Óµµ
	int speed = 300; //ÀÌ¼Ó
	int n = 0; // q´ë±â½Ã°£
	int Wn = 0; //w´ë±â½Ã°£
public:
	Â¡Å©½º() : character(stemina, ad, defend, adattack, speed)
	{
		cout << "¾À³ª°Ô ³î¾Æº¼±î????" << endl;
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
		cout << c.hurt(this->ad, c.Rdefend(), this->adattack) << "¸¸Å­ ÇÇÇØ¸¦ ÀÔÇû½À´Ï´Ù";
		if (n > 1)//q´ë±â½Ã°£Ã¼Å©
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
		cout << "Ã¶ÄÀÃ¶ÄÀ" << endl;
		if (n == 0)
		{
			n = 3;
			adspeed = adspeed + 1.3;
			ad = ad + 30;
		}
		else
		{
			cout << "Àç»ç¿ë ´ë±â½Ã°£ÀÌ" << n << "ÃÊ ³²¾Ò½À´Ï´Ù" << endl;
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
		cout << "ÀÌ¾ß¾ÆÇÏÇÏ" << endl;
		if (Wn != 0)
		{
			adattack += 30;
			Wn = 3;
		}
		else if (Wn == 0)
		{
			cout << "Àç»ç¿ë ´ë±â½Ã°£ÀÌ" << Wn << "³²¾Ò½À´Ï´Ù" << endl;
		}
		if (n > 1)//q´ë±â½Ã°£Ã¼Å©
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
		cout << "Çª½¹Çª½¹" << endl;
		cout << c.hurt(this->ad + 70, c.Rdefend(), this->adattack) << "¸¸Å­ ÇÇÇØ¸¦ ÀÔÇû½À´Ï´Ù" << endl;
		if (c.Hre() == 1)
		{
			maiH -= c.hurt(this->ad + 70, c.Rdefend(), this->adattack);
		}
		else if (c.Hre() == 2)
		{
			zedH -= c.hurt(this->ad + 70, c.Rdefend(), this->adattack);
		}
		if (n > 1)//q´ë±â½Ã°£Ã¼Å©
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
		cout << "ÀÌ¾æÈ£~" << endl; 
		cout << c.hurt(this->ad + 150, c.Rdefend(), this->adattack) << "¸¸Å­ ÇÇÇØ¸¦ ÀÔÇû½À´Ï´Ù" << endl;
		if (c.Hre() == 1)
		{
			maiH -= c.hurt(this->ad+150, c.Rdefend(), this->adattack);
		}
		else if (c.Hre() == 2)
		{
			zedH -= c.hurt(this->ad+150, c.Rdefend(), this->adattack);
		}
		if (n > 1)//q´ë±â½Ã°£Ã¼Å©
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
	//¿©±â¼­ºÎÅÍ ¸®ÅÏ
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
		cout << "Â¡Å©½º" << endl;
		cout << "Ã¼·Â" << zinH << endl;
		cout << "°ø°İ·Â" << ad << endl;
		cout << "¹æ¾î·Â" << defend << endl;
		cout << "¹°¸®°üÅë·Â" << adattack << endl;
		cout << "°ø¼Ó" << adspeed << endl;
		cout << "ÀÌ¼Ó" << speed << endl;

	}
};