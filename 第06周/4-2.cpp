#include <iostream>
#include <cmath>
using namespace std;

void solve0(double b,double c);
void solve1(double a,double b,double c,double judge);
void solve2(double a,double b);
void solve3(double a,double b,double c,double judge);

int main()
{
	double a0,b0,c0;
	double judge0;
	cout << "****解一元二次方程ax^2+bx+c=0****" << endl;
	
	cout << "请依次输入系数a,b,c，用空格隔开：" << endl;
	cin >> a0 >> b0 >> c0;
	
	judge0=b0*b0-4*a0*c0;
	if (fabs(a0)<pow(10,-10))
	{
		solve0(b0,c0);
	}
	else if (judge0>0)
	{
		solve1(a0,b0,c0,judge0);
	}
	else if (judge0==0)
	{
		solve2(a0,b0);
	}
	else
	{
		solve3(a0,b0,c0,judge0);
	}

	return 0;
}

void solve0(double b,double c)
{
	cout << "a为0，这是一元一次方程" << endl;

	if ((b==0)&&(c!=0))
	{
		cout << "该一元一次方程无解!!" << endl;
	}
	else if (c==0)
	{
		cout << "该一元一次方程的解为 x=0" <<  endl;
	}
	else
	{
		cout << "该一元一次方程的解为 x=" << (-c/b) <<  endl;
	}
}


void solve1(double a,double b,double c,double judge)
{
	double x1,x2;
	x1=(-b+sqrt(judge))/(2*a);
	x2=(-b-sqrt(judge))/(2*a);
	
	cout << "该一元二次方程有两个不相等的实数根" << endl;
	cout << "x1=" << x1 << endl;
	cout << "x2=" << x2 << endl;
}

void solve2(double a,double b)
{
	cout << "该一元二次方程有两个相等的实数根" << endl;
	cout << "x1=x2=" << -b/(2*a) << endl;
}

void solve3(double a,double b,double c,double judge)
{
	cout << "该一元二次方程有一对共轭复数根" << endl;
	double i;
	i=sqrt(-judge)/(2*a);
	cout << "x1=" << -b/(2*a) << "+" << i << "i" << endl;
	cout << "x2=" << -b/(2*a) << "-" << i << "i" << endl;
}
