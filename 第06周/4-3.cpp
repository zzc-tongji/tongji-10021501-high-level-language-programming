#include <iostream>
#include <cmath>
using namespace std;

bool prime (unsigned long int x0);

int main()
{
	unsigned long int x;
	A:
	cout << "请输入一个在2-4000000000范围内的整数" << endl;
	cin >> x;
	if ((x<=1))
	{
		cout << "输入错误!!" << endl;
		goto A;
	}

	bool judge=1;
	judge=prime(x);

	if (judge)
	{
		cout << "这是一个素数" << endl;
	}
	else
	{
		cout << "这不是一个素数" << endl;
	}

	return 0;
}

bool prime (unsigned long int x0)
{
	unsigned int i;
	unsigned int s;
	s=sqrt(x0)+1;

	if (x0==2)
	{
		return (true);
	}

	for (i=2;i<=s;i++)
	{
		if (x0%i==0)
		{
			return (false);
		}
	}

	return (true);
}
