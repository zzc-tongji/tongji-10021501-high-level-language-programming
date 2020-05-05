#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double a,b0=1,b1=1;
	cout << "Input a" << endl;
	cin >> a;
	for (b0=a;fabs(b0-b1)>=0.00001;)
	{
		b0=b1;
		b1=0.5*(b0+a/b0);	
	}
	cout << "sqrt(a)=" << b1 << endl;
	return 0;
}
