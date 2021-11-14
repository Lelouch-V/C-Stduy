#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
父类 PaymentMethod 支付方式；派生出 银行卡 class Card；银行卡class Card 派生出 信用卡CreaditCard
class Item ：物品： 物品名，价格，数量
class PaymentSystem： 支付系统，执行bill
class bill： 账单，存储vector<Item*>, 统计价格

*/


//定义支付方式 class PaymentMethod, 有现金Crash，银行卡Card (信用卡 Creadcard, 储蓄卡DebitCard)等
class PaymentMethod{
public:
	virtual void pay(int cents) = 0;
};

//class Card（银行卡）继承自 PaymentMethod
class Card :public PaymentMethod{
private:
	string name, num;		//账户名， 卡号
public:
	Card(string name, string num){
		this->name = name;
		this ->num = num;
	}
	string toString(){
		return this->getType() + "card[name = " + name + ", num=" + num + "]";
	}
	void pay(int cents){
		cout << "Payed" << cents << "cents using" << toString() << endl;  //打印支付价格和支付方式
		this->executeTransaction(cents);		
	}

protected:
	virtual string getType() = 0;						//获取卡类型 CreaditCard or DebitCard
	virtual void executeTransaction(int cents) = 0;		//执行交易
};

//信用卡CreaditCard 继承自 Card
class CreaditCard :public Card{
public:
	CreaditCard(string name, string num):Card(name,num){}  //重载，继承Class Card::Card()
protected:
	string getType(){							//多态：返回卡类型
		return "Creadit";
	}
	void executeTransaction(int cents){			//多态：执行交易
		cout << cents << "paid using" << getType() << "Card." << endl; //调用 CreaditCard::getType()
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
	vector<Item*> items;  //包含 物品 的vector
public:
	void add(Item* item){ 
		items.push_back(item); 
	}
	int getTotalPrivce(){  //计算所有item的总价格
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
		bill->add(item1);   //将物品 item1 添加入账单中
		bill->add(item2);	//将物品 item2 添加入账单中
		
		bill->pay(creaditcard);  //信用卡支付。 创建信用卡类，账户名：Li Si；卡号：96110
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