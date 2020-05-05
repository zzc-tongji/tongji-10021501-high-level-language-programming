#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

int main()
{
	char a[3][81]={'\0'};
	int i,j;
	int capital_letter=0,small_letter=0,number=0,space=0,others=0;

	cout << "请输入三句话，每句话不超过80个字符" << endl;
	for (i=0;i<=2;i++)
	{
		gets(a[i]);
	}
	
	for (i=0;i<=2;i++)
	{
		for (j=0;j<=80;j++)
		{
			if (a[i][j]!='\0')
			{
				if((a[i][j]>='A')&&(a[i][j]<='Z'))
				{
					capital_letter++;
				}
				else if ((a[i][j]>='a')&&(a[i][j]<='z'))
				{
					small_letter++;
				}
				else if ((a[i][j]>='0')&&(a[i][j]<='9'))
				{
					number++;
				}
				else if (a[i][j]==' ')
				{
					space++;
				}
				else
				{
					others++;
				}
			}	
		}
	}

	cout << "大写字母：" << setw(3) << capital_letter << endl;
	cout << "小写字母：" << setw(3) << small_letter << endl;
	cout << "数    字：" << setw(3) << number << endl;
	cout << "空    格：" << setw(3) << space << endl;
	cout << "其他字符：" << setw(3) << others << endl;

	return 0;
}
