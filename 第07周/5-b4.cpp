#include <iostream>
using namespace std;

int main()
{
	char a[101]={'\0'};
	char b[101]={'\0'};

	cout << "输入句子（不超过100 个字母）：" << endl;
	gets(a);
	
	if ((a[0]>=97)&&(a[0]<=122))
	{
		b[0]=a[0]-32;
	}
	else
	{
		b[0]=a[0];
	}
	
	int i;
	for (i=1;a[i]!='\0';i++)
	{
		if (a[i-1]==' ')
		{
			if ((a[i]>=97)&&(a[i]<=122))
			{
				b[i]=a[i]-32;
			}
			else
			{
				b[i]=a[i];
			}
		}
		else
		{
			if ((a[i]>=65)&&(a[i]<=90))
			{
				b[i]=a[i]+32;
			}
			else
			{
				b[i]=a[i];
			}
		}
	}

	cout << "改正过的句子：" << endl;
	cout << b << endl;

	return 0;
}
