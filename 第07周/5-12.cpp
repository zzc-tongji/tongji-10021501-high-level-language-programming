#include <iostream>
using namespace std;

char encrypt(char x);

int main()
{
	char a[20]="Victory is ours!";
	char b[20]={'\0'};

	cout << "原码：" << a << endl;

	int i;
	for (i=0;a[i]!='\0';i++)
	{
		b[i]=encrypt(a[i]);
	}

	cout << "密码：" << b << endl;

	return 0;
}

char encrypt(char x)
{
	
	if ((x>=65)&&(x<=90))
	{
		return (90-(x-65));
	}
	else if ((x>=97)&&(x<=122))
	{
		return (122-(x-97));
	}
	else
	{
		return x;
	}
}
