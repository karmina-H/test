#pragma once
#include "è���⺻.h"
#include <time.h>

static int maiH = 870;
static int zedH = 800;
static int zinH = 750;
class �������� : public character
{
private:
	friend class ������;
	int stemina = 870; //ü��
	int ad = 70; //���ݷ�
	int defend = 45; //����
	int adattack = 25; // ���������
	int adspeed = 1; //���ݼӵ�
	int speed = 300; //�̼�
	int Et = 0; //e���� ���ð�
	int Rt = 0; //�ñر� ���� ���ð�
public:
	��������() : character(stemina, ad, defend, adattack, speed)
	{
		cout << "���ǰ��� ����� ���̿�.." << endl;
	}
	int Hre()
	{
		return 1;
	}
	//����
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
		cout << c.hurt(this->ad, c.Rdefend(), this->adattack) << "��ŭ ���ظ� �������ϴ�" << endl;
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
		cout << "���ַ� �˼�!" << endl;
		if (c.Hre() == 2)
		{
			zedH -= c.hurt(this->ad +50, c.Rdefend(), this->adattack);
		}
		cout << c.hurt(this->ad + 50, c.Rdefend(), this->adattack) << "��ŭ ���ظ� �������ϴ�"<<endl;
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
		cout << "���Ű� ��ü.." << endl;
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
			cout << "ü���� ��� �� �� �ֽ��ϴ�"<<endl;
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
		cout << "���ַ� �˼�..!" << endl;
		if (Et == 0)
		{
			ad = ad + 30;
			adattack = adattack += 20;
		}
		else
		{
			cout << "���� ���ð���" << Et << "�� ���ҽ��ϴ�" << endl;
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
		cout << "������ �ӵ�~!" << endl;
		if (Rt == 0)
		{
			speed += 300;
			adspeed += 2;
			Rt = 30;
		}
		else
		{
			cout << "���� ���ð���" << Rt << "�� ���ҽ��ϴ�" << endl;
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

	//���⼭���� ����
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
	//���
	void showdata()
	{
		cout << "��������" << endl;
		cout << "ü��" << maiH<<endl;
		cout << "���ݷ�" << ad<<endl;
		cout << "����" << defend<<endl;
		cout << "���������" << adattack<<endl;
		cout << "����" << adspeed<<endl;
		cout << "�̼�" << speed<<endl;
		
	}

};

class ���� : public character
{
private:
	int stemina = 800; //ü��
	int ad = 80; //���ݷ�
	int defend = 40; //����
	int adattack = 30; // ���������
	int adspeed = 1; //���ݼӵ�
	int speed = 300; //�̼�
	bool W = false;//�׸��� ���� ����
	int Wn = 0;//�׸��� ���� �ϴ� �ð�
public:
	����() : character(stemina, ad, defend, adattack, speed)
	{
		cout << "������ �ʴ� ���� ���� �������" << endl;
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
		cout << c.hurt(this->ad, c.Rdefend(), this->adattack) << "��ŭ ���ظ� �������ϴ�";
		cout << "����";
	}

	void Qattack(character& c)
	{
		cout << "��~" << endl;
		srand(time(NULL));
		int num = rand() % 2;
		if (num == 0)
		{
			cout << "����~" << endl;
		}
		else if (num == 1&&W == true)
		{
			cout<<c.hurt(this->ad + 30, c.Rdefend(), this->adattack)*2<<"��ŭ ���ظ� �������ϴ�"<<endl;
			if (c.Hre() == 1)
			{
				maiH -= c.hurt(this->ad, c.Rdefend(), this->adattack)*2;
			}
			else if (c.Hre() == 3)
			{
				zinH -= c.hurt(this->ad, c.Rdefend(), this->adattack)*2;
			}
			cout << "����" << endl;

		}
		else if (num == 1 && W == false)
		{
			cout << c.hurt(this->ad + 30, c.Rdefend(), this->adattack) << "��ŭ ���ظ� �������ϴ�" << endl;
			if (c.Hre() == 1)
			{
				maiH -= c.hurt(this->ad+30, c.Rdefend(), this->adattack);
			}
			else if (c.Hre() == 3)
			{
				zinH -= c.hurt(this->ad+30, c.Rdefend(), this->adattack);
			}
			cout << "����" << endl;
		}

		//�׸��� ���ֱ�
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
			cout << "��" << endl;
			W = true;
			Wn = 8;
		}
		else
		{
			cout << "���� ���� ���ð���" << Wn << "�� ���ҽ��ϴ�" << endl;
		}
	}

	void Eattack(character& c)
	{
		cout << "�g" << endl;
		if (W == true)
		{
			cout << c.hurt(this->ad, c.Rdefend(), this->adattack)*2 << "��ŭ ���ظ� �������ϴ�" << endl;
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
			cout << c.hurt(this->ad + 10, c.Rdefend(), this->adattack) << "��ŭ ���ظ� �������ϴ�" << endl;
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
		cout << c.hurt(this->ad + 100, c.Rdefend(), this->adattack) << "��ŭ ���ظ� �������ϴ�" << endl;
		cout << "��~" << endl;
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

	//���⼭���� �����ϴ°�
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
		cout << "����" << endl;
		cout << "ü��" << zedH << endl;
		cout << "���ݷ�" << ad << endl;
		cout << "����" << defend << endl;
		cout << "���������" << adattack << endl;
		cout << "����" << adspeed << endl;
		cout << "�̼�" << speed << endl;

	}
};


class ¡ũ�� : public character
{
private:
	int stemina = 750; //ü��
	int ad = 76; //���ݷ�
	int defend = 43; //����
	int adattack = 30; // ���������
	int adspeed = 0.4; //���ݼӵ�
	int speed = 300; //�̼�
	int n = 0; // q���ð�
	int Wn = 0; //w���ð�
public:
	¡ũ��() : character(stemina, ad, defend, adattack, speed)
	{
		cout << "������ ��ƺ���????" << endl;
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
		cout << c.hurt(this->ad, c.Rdefend(), this->adattack) << "��ŭ ���ظ� �������ϴ�";
		if (n > 1)//q���ð�üũ
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
		cout << "ö��ö��" << endl;
		if (n == 0)
		{
			n = 3;
			adspeed = adspeed + 1.3;
			ad = ad + 30;
		}
		else
		{
			cout << "���� ���ð���" << n << "�� ���ҽ��ϴ�" << endl;
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
		cout << "�̾߾�����" << endl;
		if (Wn != 0)
		{
			adattack += 30;
			Wn = 3;
		}
		else if (Wn == 0)
		{
			cout << "���� ���ð���" << Wn << "���ҽ��ϴ�" << endl;
		}
		if (n > 1)//q���ð�üũ
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
		cout << "Ǫ��Ǫ��" << endl;
		cout << c.hurt(this->ad + 70, c.Rdefend(), this->adattack) << "��ŭ ���ظ� �������ϴ�" << endl;
		if (c.Hre() == 1)
		{
			maiH -= c.hurt(this->ad + 70, c.Rdefend(), this->adattack);
		}
		else if (c.Hre() == 2)
		{
			zedH -= c.hurt(this->ad + 70, c.Rdefend(), this->adattack);
		}
		if (n > 1)//q���ð�üũ
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
		cout << "�̾�ȣ~" << endl; 
		cout << c.hurt(this->ad + 150, c.Rdefend(), this->adattack) << "��ŭ ���ظ� �������ϴ�" << endl;
		if (c.Hre() == 1)
		{
			maiH -= c.hurt(this->ad+150, c.Rdefend(), this->adattack);
		}
		else if (c.Hre() == 2)
		{
			zedH -= c.hurt(this->ad+150, c.Rdefend(), this->adattack);
		}
		if (n > 1)//q���ð�üũ
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
	//���⼭���� ����
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
		cout << "¡ũ��" << endl;
		cout << "ü��" << zinH << endl;
		cout << "���ݷ�" << ad << endl;
		cout << "����" << defend << endl;
		cout << "���������" << adattack << endl;
		cout << "����" << adspeed << endl;
		cout << "�̼�" << speed << endl;

	}
};