#include <iostream>
#include <cmath>
#include "4-b2.h"
using namespace std;

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
