

#include<iostream>
#include<string>
using namespace std;

class Team{
private:
	string name;
	int goal;
public:
	Team(string name){
		this->name = name;
		goal = 0;
	}
	void increamentGoal(){
		goal++;
	}
	int getGoal(){
		return goal;
	}
	string getName(){
		return name;
	}
};

class Game{
private:
	Team *a, *b;
public:
	Game(Team *t1, Team *t2){
		a = t1;
		b = t2;
	}
	void getResults(){
		cout << a->getName() << ":" << a->getGoal() << endl;
		cout << b->getName() << ":" << b->getGoal() << endl;
	}
	void increamentGoal(Team *t){
		t->increamentGoal();
	}
};

/*
 �� Game Ϊ��Ϸ����
 �� Team Ϊ��Ϸ���
 Game ���� Team / Team ����Game
*/

int main()
{
	Team *aa = new Team("TA");			//Team���캯��������private����TA �� string name
	Team *bb = new Team("TB");			//Team���캯��������private����TB �� string name
	Game *football = new Game(aa,bb);	//Game���캯��������Team����ָ��

	football->increamentGoal(aa);		//�� aa��+1��
	football->increamentGoal(aa);		//�� aa��+1��
	football->increamentGoal(bb);		//�� bb��+1��
	football->getResults();

	system("pause");
	return 0;


}