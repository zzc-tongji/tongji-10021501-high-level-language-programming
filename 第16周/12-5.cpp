#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

const double PI=3.14159265358979;

class Shape
{
	public:
		virtual void set_value(double a1=0,double a2=0,double a3=0){}
		virtual void area(){}
		virtual double get_area(){return 0;}
};

class Circle:public Shape
{
	protected:
		double r;
		double S;
	public:
		Circle(double r0=0)
		{
			r=r0;
			S=0;
		}
		virtual void set_value(double a1=0,double a2=0,double a3=0)
		{r=a1;}
		virtual void area()
		{
			S=PI*r*r;
			cout << "圆的面积：" << S << endl;
		}
		virtual double get_area()
		{return S;}
};

class Square:public Shape
{
	protected:
		double a;
		double S;
	public:
		Square(double a0=0)
		{
			a=a0;
			S=0;
		}
		virtual void set_value(double a1=0,double a2=0,double a3=0)
		{a=a1;}
		virtual void area()
		{
			S=a*a;
			cout << "正方形的面积：" << S << endl;
		}
		virtual double get_area()
		{return S;}
};

class Rectangle:public Shape
{
	protected:
		double a;
		double b;
		double S;
	public:
		Rectangle(double a0=0,double b0=0)
		{
			a=a0;
			b=b0;
			S=0;
		}
		virtual void set_value(double a1=0,double a2=0,double a3=0)
		{
			a=a1;
			b=a2;
		}
		virtual void area()
		{
			S=a*b;
			cout << "长方形的面积：" << S << endl;
		}
		virtual double get_area()
		{return S;}
};

class Trapezoid:public Shape
{
	protected:
		double a;
		double b;
		double h;
		double S;
	public:
		Trapezoid(double a0=0,double b0=0,double h0=0)
		{
			a=a0;
			b=b0;
			h=h0;
			S=0;
		}
		virtual void set_value(double a1=0,double a2=0,double a3=0)
		{
			a=a1;
			b=a2;
			h=a3;
		}
		virtual void area()
		{
			S=0.5*(a+b)*h;
			cout << "梯形的面积：" << S << endl;
		}
		virtual double get_area()
		{return S;}
};

class Triangle:public Shape
{
	protected:
		double a;
		double b;
		double c;
		double S;
	public:
		Triangle(double a0=0,double b0=0,double c0=0)
		{
			a=a0;
			b=b0;
			c=c0;
			S=0;
		}
		virtual void set_value(double a1=0,double a2=0,double a3=0)
		{
			a=a1;
			b=a2;
			c=a3;
		}
		virtual void area()
		{
			if (a+b>c && b+c>a && c+a>b)
			{
				double t=0.5*(a+b+c);
				S=pow(t*(t-a)*(t-b)*(t-c),0.5);
				cout << "三角形的面积：" << S << endl;
			}
			else
			{
				cout << "三角形的面积：非法取值！" << endl;
			}
		}
		virtual double get_area()
		{return S;}
};

int main()
{
    Circle    c1(1); 
    Square    s1(1); 
    Rectangle r1(2,3); 
    Trapezoid t1(2,3,5); 
    Triangle  t2(5,12,13); 
    Shape *s[5] = {&c1, &s1, &r1, &t1, &t2}; 
 
    int   i; 
    for(i=0; i<5; i++) 
        s[i]->area(); //分别打印不同形状图形的面积 

	//system("PAUSE"); //如果是C++作业就注释掉
	return 0;
}
