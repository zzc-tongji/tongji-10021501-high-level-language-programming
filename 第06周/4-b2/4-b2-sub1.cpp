#include <iostream>
#include <cmath>
using namespace std;

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
