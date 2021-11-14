
#include<iostream>
#include<vector>
using namespace std;
/*
ʵ��һ���򵥵ĳ�������ϵͳ���˿�ѡ��ͼ�����Ʒ��item����
���빺�ﳵ��ShoppingCart����������̨��Cashier����ÿ�����ﳵ�е���Ʒͳ�Ƽ۸񣬲����ˡ�
*/

class Book;

class Visitor
{
public:
	virtual void visit(Book *book) = 0;
};

class Item
{
public:
	virtual void accept(Visitor* visitor) = 0;
	virtual double getPrice() = 0;
};

class Book :public Item
{
private:
	double price;
public:
	Book(double price)
	{
		this->price = price;
	}
	void accept(Visitor* visitor)
	{
		visitor->visit(this);
	}
	double getPrice()
	{
		return price;
	}
};

class Cashier :public Visitor
{
private:
	double totalForCart=0;
public:
	void visit(Book*book)
	{
		double money = book->getPrice();
		//Book�۸񳬹�10Ԫ��8��
		if (money <= 10){
			totalForCart += money;
		}
		else {
			totalForCart += (money * 0.8);
		}
		cout <<"totalForCart= "<< totalForCart << endl;
	}
	double getTotal()
	{
		//cout << totalForCart << endl;
		return totalForCart;
	}
};

class ShoppingCart
{
private:
	vector<Item*>items;
public:
	double calculatePrice()
	{
		Cashier* visitor = new Cashier();

		for (int i = 0; i < items.size(); i++){
			items[i]->accept(visitor);
		}
		double total = visitor->getTotal();
		return total;
	}
	void add(Item*e){
		items.push_back(e);
	}
};

int main()
{
	ShoppingCart *A = new ShoppingCart();
	Book *booka = new Book(20);
	Book *bookb = new Book(10);

	A->add(booka);
	A->add(bookb);
	cout<<A->calculatePrice()<<endl;

	system("pause");
	return 0;
}

