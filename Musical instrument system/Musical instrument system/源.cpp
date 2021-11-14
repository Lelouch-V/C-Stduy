#include<iostream>
#include<string>
#include<vector>

using namespace std;

/*
������Music ����ʹ�ø�������Instrument��������͵����Ȳ�����
���� Instrument
	������� Precussion
	������Stringed
	������Wind	
		ľ������Woodwind
		ͭ������Brass
*/


//ö�ٸ�������
enum Note{
	MIDDLE_C,
	C_SHARP,
	B_FLAT
};

//������ࡪ������
class Instrument{
public:
	virtual void play(Note n)=0;		//����
	virtual void adjust() = 0;	//����
};

//������
class Wind :public Instrument
{
public:
	void play(Note n)
	{
		cout << "Wind.play()" << n << endl;
	}
	void adjust()
	{
		cout << "Wind.adjust()" << endl;
	}
};

//ͭ������
class Brass :public Wind
{
public:
	void play(Note n)
	{
		cout << "Brass.play()" << n << endl;
	}
	void adjust()
	{
		cout << "Brass.adjust()" << endl;
	}
};

//ľ������
class Woodwind :public Wind
{
public:
	void play(Note n)
	{
		cout << "Woodwind.play()" << n << endl;
	}
	void adjust()
	{
		cout << "Woodwind.adjust()" << endl;
	}
};


class Music
{
public:
	void tune(Instrument *i)		//C������
	{
		i->play(MIDDLE_C);
	}
	void adjust(Instrument *i)		//����
	{
		i->adjust();
	}
	void tuneAll( vector<Instrument*>v )	//�������������е���������
	{
		vector<Instrument*>::iterator it;
		for (it = v.begin(); it != v.end(); it++)
		{
			this->adjust(*it);
			this->tune(*it);
		}
	}
};

int main()
{
	Music* music = new Music();

	vector<Instrument*>orchestra;
	orchestra.push_back(new Wind());
	orchestra.push_back(new Brass());
	orchestra.push_back(new Woodwind());
	music->tuneAll(orchestra);

	system("pause");
	return 0;
}