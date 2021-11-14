
#include<iostream>
#include<string>
using namespace std;

//客户类，分为真实的客户和虚拟客户
class Customer{
protected:
	string name;
public:
	virtual bool isNil() = 0;
	virtual string getName() = 0;
};


//创建真实的客户对象
class RealCutomer:public Customer{
public:
	RealCutomer(string name)
	{
		this->name = name;
	}
	bool isNil()
	{
		return false;
	}
	string getName()
	{
		return name;
	}
};

//虚假的客户
class NullCustomer :public Customer{
public:
	bool isNil()
	{
		return true;
	}
	string getName()
	{
		return "Not Available in Customer Database";
	}
};

class CustomerFactory{
private:
	//string names[3] = { "Rob", "Joe", "Julie" };	//客户列表  无法初始化
	string names[3];
public:
	CustomerFactory()
	{
		names[0] = "Rob";
		names[1] = "Joe";
		names[2] = "Julie";
	}
	Customer* getCustomer(string name)				//在客户列表中索引客户，并建立客户对象
	{
		for (int i = 0; i < 3; i++)
		{
			if (names[i].compare(name) == 0)
				return new RealCutomer(name);
		}
		NullCustomer *it = new NullCustomer();
		return new NullCustomer();						//没有索引到，建立一个虚假客户对象
	}
	

};

class CRM{
public:
	void getCustomer()
	{
		CustomerFactory* cf = new CustomerFactory();
		//定义customer
		Customer* customer1 = cf->getCustomer("Rob");
		Customer* customer2 = cf->getCustomer("Ben");
		Customer* customer3 = cf->getCustomer("Joe");
		Customer* customer4 = cf->getCustomer("Julie");

		cout << "Customers" << endl;
		cout << customer1->getName() << endl;  delete customer1;
		cout << customer2->getName() << endl;  delete customer2;
		cout << customer3->getName() << endl;  delete customer3;
		cout << customer4->getName() << endl;  delete customer4;
		delete cf;
	}

};

int main()
{
	CRM* crm = new CRM();
	crm->getCustomer();
	delete crm;

	system("pause");
	return 0;
}



