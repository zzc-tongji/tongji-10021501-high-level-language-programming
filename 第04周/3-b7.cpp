#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double a,b,c,x1,x2;
	double judge;
	cout << "****解一元二次方程ax^2+bx+c=0****" << endl;
	cout << "请依次输入系数a,b,c，用空格隔开：" << endl;
	cin >> a >> b >> c;

	bool legal_equation=1; //是否为合法的一元二次方程
	
	judge=b*b-4*a*c;

	if (a==0)
	{
		legal_equation=0;
	}

	if (legal_equation)
	{
		if (judge>0)
		{
			x1=(-b+sqrt(judge))/(2*a);
			x2=(-b-sqrt(judge))/(2*a);
			cout << "该一元二次方程有两个不相等的实数根" << endl;
			cout << "x1=" << x1 << endl;
			cout << "x2=" << x2 << endl;
		}
		else if (judge==0)
		{
			cout << "该一元二次方程有两个相等的实数根" << endl;
			cout << "x1=x2=" << -b/(2*a) << endl;
		}
		else
		{
			cout << "该一元二次方程没有实数根" << endl;
			double i;
			i=sqrt(-judge)/(2*a);
			cout << "x1=" << -b/(2*a) << "+" << i << "i" << endl;
			cout << "x2=" << -b/(2*a) << "-" << i << "i" << endl;
		}
	}
	else
	{
		cout << "a为0，这不是一元二次方程" << endl;
	}

	return 0;
}
