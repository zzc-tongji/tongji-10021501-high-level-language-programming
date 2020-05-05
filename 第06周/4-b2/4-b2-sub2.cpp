#include <iostream>
#include <cmath>
using namespace std;

void solve1(double a,double b,double c,double judge)
{
	double x1,x2;
	x1=(-b+sqrt(judge))/(2*a);
	x2=(-b-sqrt(judge))/(2*a);
	
	cout << "该一元二次方程有两个不相等的实数根" << endl;
	cout << "x1=" << x1 << endl;
	cout << "x2=" << x2 << endl;
}
