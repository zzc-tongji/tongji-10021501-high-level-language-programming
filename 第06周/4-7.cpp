#include <iostream>
#include <cmath>
using namespace std;

bool prime (unsigned long int x0);
void godbah(unsigned long int x1);

int main()
{
	unsigned long int x;
	A:
	cout << "璇疯緭鍏ヤ竴涓湪6-4000000000鑼冨洿鍐呯殑鍋舵暟" << endl;
	cin >> x;
	if ((x<=5)||(x%2!=0))
	{
		cout << "杈撳叆閿欒!!" << endl;
		goto A;
	}

	godbah(x);

	return 0;
}

bool prime (unsigned long int x0)
{
	unsigned long int i;
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

void godbah(unsigned long int x1)
{
	unsigned long int i;
	unsigned long int j;
	bool i_pr;
	bool j_pr;

	for (i=2;i<x1;i++)
	{
		j=x1-i;
		i_pr=prime(i);
		j_pr=prime(j);
		
		if (i_pr&&j_pr)
		{
			cout << x1 << "=" << i << "+" << j << endl;
			break;
		}
	}	
}
