#include <iostream>
using namespace std;

int main()
{
	char a[3][31]={'\0'};
	char b[3][31]={'\0'};
	int i;

	cout << "璇蜂緷娆¤緭鍏ヤ笁涓瓧绗︿覆锛屾瘡涓笉瓒呰繃30涓瓧绗︼細" << endl;
	for (i=0;i<=2;i++)
	{
		gets(a[i]);
	}

	if ((strcmp(a[0],a[1])<0) && (strcmp(a[0],a[2])<0))
	{
		strcpy(b[0],a[0]);

		if (strcmp(a[1],a[2])<0)
		{
			strcpy(b[1],a[1]);
			strcpy(b[2],a[2]);
		}
		else //strcmp(a[2],a[1])<0
		{
			strcpy(b[1],a[2]);
			strcpy(b[2],a[1]);
		}
	}
	else if ((strcmp(a[1],a[0])<0) && (strcmp(a[1],a[2])<0))
	{	
		strcpy(b[0],a[1]);

		if (strcmp(a[0],a[2])<0)
		{
			strcpy(b[1],a[0]);
			strcpy(b[2],a[2]);
		}
		else //strcmp(a[2],a[0])<0
		{
			strcpy(b[1],a[2]);
			strcpy(b[2],a[0]);
		}
	}
	else //((strcmp(a[2],a[0])<0) && (strcmp(a[2],a[1])<0))
	{
		strcpy(b[0],a[2]);

		if (strcmp(a[0],a[1])<0)
		{
			strcpy(b[1],a[0]);
			strcpy(b[2],a[1]);
		}
		else //strcmp(a[1],a[0])<0
		{
			strcpy(b[1],a[1]);
			strcpy(b[2],a[0]);
		}
	}

	cout << "浠庡皬鍒板ぇ鎺掑垪涓猴細" << endl;
	for (i=0;i<=2;i++)
	{
		cout << b[i] <<  endl;
	}

	return 0;
}
