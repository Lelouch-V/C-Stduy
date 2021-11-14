#include<iostream>
#include<string>
using namespace std;

//��Բ
class DrawCircle
{
public:
	virtual void drawCiricle(int radius, int x, int y){}
	virtual ~DrawCircle(){}
};

//���ƺ�ɫԲ
class RedCircle : public DrawCircle
{
public:
	void drawCiricle(int radius, int x, int y){
		cout << "Drawing Circle[red, radius: "<< radius;
		cout << " , x: " << x << ", y:" << y << "]" << endl;
	}
};

//������ɫԲ
class GreenCircle :public DrawCircle
{
public:
	void drawCiricle(int radius, int x, int y){
		cout << "Drawing Circle[green, radius: " << radius;
		cout << " , x: " << x << ", y:" << y << "]" << endl;
	}
};


class Shape
{
protected:
	DrawCircle *drawCircle;
public:
	Shape(DrawCircle *drawCircle){
		this->drawCircle = drawCircle;
	}
	virtual ~Shape(){}
	
	virtual void draw() = 0;
};

class Circle :public Shape{
private:
	int x, y, radius;
public:
	Circle(int x, int y, int radius, DrawCircle* drawCircle) :Shape(drawCircle)
	{
		this->x = x;
		this->y = y;
		this->radius = radius;
	}
	void draw(){
		drawCircle->drawCiricle(radius,x,y);
	}
};

int main()
{
	Shape *redCircle = new Circle(100, 100, 10, new RedCircle);//���ƺ�ɫԲ��
	Shape *greenCircle = new Circle(100, 100, 10, new GreenCircle );//���ƺ�ɫԲ��
	redCircle->draw();
	greenCircle->draw();


	system("pause");
	return 0;
}