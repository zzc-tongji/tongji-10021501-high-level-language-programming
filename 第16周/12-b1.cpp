#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

class integral
{
	protected:
		double a;
		double b;
		double result;
		double precious;
	public:
		integral(double b0=0,double a0=0)
		{
			a=a0;
			b=b0;
			precious=0.000001;
		}
		void set(double precious0,double b0,double a0)
		{
			a=a0;
			b=b0;
			precious=(precious0?precious:0.000001);
		}
		virtual double value(){return 0;}
};

class integral_sin:public integral
{
	public:
		integral_sin(double b0=0,double a0=0):integral(b0,a0){}
		virtual double value()
		{
			if (fabs(a-b)<=precious)
			{
				return 0;
			}
			else if (a<b)
			{
				double division=(b-a)*precious;
				double c=0;
				
				for (c=a,result=0;c<=b;c+=division)
				{
					result+=division*sin(c);
				}
				
				return result;
			}
			else
			{
				double division=(b-a)*precious;
				double c=0;
				
				for (c=a,result=0;c>=b;c+=division)
				{
					result+=division*sin(c);
				}
				
				return result;
			}
		}
};

class integral_cos:public integral
{
	public:
		integral_cos(double b0=0,double a0=0):integral(b0,a0){}
		virtual double value()
		{
			if (fabs(a-b)<=precious)
			{
				return 0;
			}
			else if (a<b)
			{
				double division=(b-a)*precious;
				double c=0;
				
				for (c=a,result=0;c<=b;c+=division)
				{
					result+=division*cos(c);
				}
				
				return result;
			}
			else
			{
				double division=(b-a)*precious;
				double c=0;
				
				for (c=a,result=0;c>=b;c+=division)
				{
					result+=division*cos(c);
				}
				
				return result;
			}
		}
};

class integral_exp:public integral
{
	public:
		integral_exp(double b0=0,double a0=0):integral(b0,a0){}
		virtual double value()
		{
			if (fabs(a-b)<=precious)
			{
				return 0;
			}
			else if (a<b)
			{
				double division=(b-a)*precious;
				double c=0;
				
				for (c=a,result=0;c<=b;c+=division)
				{
					result+=division*exp(c);
				}
				
				return result;
			}
			else
			{
				double division=(b-a)*precious;
				double c=0;
				
				for (c=a,result=0;c>=b;c+=division)
				{
					result+=division*exp(c);
				}
				
				return result;
			}
		}
};

istream & operator >> (istream &input,integral &X)
{
	double a0,b0,precious0;
	cout << "请依次输入：精度（输入0则默认为0.000001） 积分上限 积分下限" << endl;
	input >> precious0 >> b0 >> a0;
	X.set(precious0,b0,a0);
	return input;
}

int main()
{
	integral_sin s1;
	integral_cos s2;
	integral_exp s3;
	integral    *p;

	cin >> s1; 						//输入上下限及 x 的值
	p = &s1;
	cout << p->value() << endl; 	//打印 sinxdx 的值
	cin >> s2; 						//输入上下限及 x 的值
	p = &s2;
	cout << p->value() << endl; 	//打印 cosxdx 的值
	cin >> s3; 						//输入上下限及 x 的值
	p = &s3;
	cout << p->value() << endl; 	//打印 expxdx 的值

	return 0;
}



