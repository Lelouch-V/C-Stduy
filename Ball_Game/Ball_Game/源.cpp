

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
 类 Game 为游戏规则
 类 Team 为游戏玩家
 Game 调用 Team / Team 加入Game
*/

int main()
{
	Team *aa = new Team("TA");			//Team构造函数，传入private变量TA 给 string name
	Team *bb = new Team("TB");			//Team构造函数，传入private变量TB 给 string name
	Game *football = new Game(aa,bb);	//Game构造函数，传入Team类型指针

	football->increamentGoal(aa);		//给 aa队+1分
	football->increamentGoal(aa);		//给 aa队+1分
	football->increamentGoal(bb);		//给 bb队+1分
	football->getResults();

	system("pause");
	return 0;


}