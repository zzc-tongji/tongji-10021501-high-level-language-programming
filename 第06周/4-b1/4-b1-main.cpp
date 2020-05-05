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
