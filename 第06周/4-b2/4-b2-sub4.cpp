#include <iostream>
#include <cmath>
using namespace std;

void solve3(double a,double b,double c,double judge)
{
	cout << "该一元二次方程有一对共轭复数根" << endl;
	double i;
	i=sqrt(-judge)/(2*a);
	cout << "x1=" << -b/(2*a) << "+" << i << "i" << endl;
	cout << "x2=" << -b/(2*a) << "-" << i << "i" << endl;
}
