#include<iostream>
#include<string>
#include<vector>

using namespace std;

/*
音乐类Music 可以使用各类乐器Instrument进行演奏和调音等操作。
乐器 Instrument
	打击乐器 Precussion
	弦乐器Stringed
	管乐器Wind	
		木管乐器Woodwind
		铜管乐器Brass
*/


//枚举各种音调
enum Note{
	MIDDLE_C,
	C_SHARP,
	B_FLAT
};

//抽象基类——乐器
class Instrument{
public:
	virtual void play(Note n)=0;		//演奏
	virtual void adjust() = 0;	//调音
};

//管乐器
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

//铜管乐器
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

//木管乐器
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
	void tune(Instrument *i)		//C调演奏
	{
		i->play(MIDDLE_C);
	}
	void adjust(Instrument *i)		//调音
	{
		i->adjust();
	}
	void tuneAll( vector<Instrument*>v )	//对所有乐器进行调音和演奏
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