#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
���� PaymentMethod ֧����ʽ�������� ���п� class Card�����п�class Card ������ ���ÿ�CreaditCard
class Item ����Ʒ�� ��Ʒ�����۸�����
class PaymentSystem�� ֧��ϵͳ��ִ��bill
class bill�� �˵����洢vector<Item*>, ͳ�Ƽ۸�

*/


//����֧����ʽ class PaymentMethod, ���ֽ�Crash�����п�Card (���ÿ� Creadcard, ���DebitCard)��
class PaymentMethod{
public:
	virtual void pay(int cents) = 0;
};

//class Card�����п����̳��� PaymentMethod
class Card :public PaymentMethod{
private:
	string name, num;		//�˻����� ����
public:
	Card(string name, string num){
		this->name = name;
		this ->num = num;
	}
	string toString(){
		return this->getType() + "card[name = " + name + ", num=" + num + "]";
	}
	void pay(int cents){
		cout << "Payed" << cents << "cents using" << toString() << endl;  //��ӡ֧���۸��֧����ʽ
		this->executeTransaction(cents);		
	}

protected:
	virtual string getType() = 0;						//��ȡ������ CreaditCard or DebitCard
	virtual void executeTransaction(int cents) = 0;		//ִ�н���
};

//���ÿ�CreaditCard �̳��� Card
class CreaditCard :public Card{
public:
	CreaditCard(string name, string num):Card(name,num){}  //���أ��̳�Class Card::Card()
protected:
	string getType(){							//��̬�����ؿ�����
		return "Creadit";
	}
	void executeTransaction(int cents){			//��̬��ִ�н���
		cout << cents << "paid using" << getType() << "Card." << endl; //���� CreaditCard::getType()
	}
};

class Item{
private:
	string item_name;
	int price = 10;
	int num;
public:
	Item(string name, int num){
		this->item_name = name;
		this->num = num;
	}

	int money(){
		return price*num;
	}
};

class Bill{
private:
	vector<Item*> items;  //���� ��Ʒ ��vector
public:
	void add(Item* item){ 
		items.push_back(item); 
	}
	int getTotalPrivce(){  //��������item���ܼ۸�
		int all_money = 0;

		for (int i = 0; i < 2; i++)
			all_money += items[i]->money();

		return all_money;
	}
	void pay(PaymentMethod* paymentMethod){
		paymentMethod->pay(getTotalPrivce());
	}
};

class PaymentSystem{
public:
	void pay(PaymentMethod* creaditcard){
		Bill* bill = new Bill();
		Item* item1 = new Item("1234", 10);
		Item* item2 = new Item("4567", 5);
		bill->add(item1);   //����Ʒ item1 ������˵���
		bill->add(item2);	//����Ʒ item2 ������˵���
		
		bill->pay(creaditcard);  //���ÿ�֧���� �������ÿ��࣬�˻�����Li Si�����ţ�96110
	}
};

int main()
{
	PaymentSystem *payment = new PaymentSystem();
	CreaditCard *creaditcard = new CreaditCard("Li Si", "96110");
	payment->pay(creaditcard);
	system("pause");
	return 0;
}