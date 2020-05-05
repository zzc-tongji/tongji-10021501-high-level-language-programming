#include <iostream>
#include <iomanip>
#include <cmath>
#include <time.h>

using namespace std;

char a[12][28]={'\0'}; //可用范围：行1-10，列1-26
int mine[50][2]={0};

void display_a(); //显示区域 
void land_mine(); //埋地雷
void handle();    //填充无地雷区域

int main()
{
	land_mine();
	handle();
	display_a();

	cout << endl << "按回车键结束" << endl;
	getchar();

	return 0;
}

void display_a()
{
	int i,j;
	for (i=1;i<=10;i++)
	{
		for (j=1;j<=26;j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void land_mine()
{
	srand(time(0));
	int i,j,counter;
	for (counter=0;counter<=49;)
	{
		i=rand()%10+1;
		j=rand()%26+1;
		if (a[i][j]!='*')
		{
			a[i][j]='*';
			mine[counter][0]=i;
			mine[counter][1]=j;
			counter++;
		}
	}
}

void handle()
{
	int i,j,p,q,counter=48;
	for (i=1;i<=10;i++)
	{
		for (j=1;j<=26;j++)
		{	
			if (a[i][j]=='*') continue;
			for (p=i-1;p<=i+1;p++)
			{
				for (q=j-1;q<=j+1;q++)
				{
					if (a[p][q]=='*') counter++;
				}
			}
			a[i][j]=(char)counter;
			counter=48;
		}
	}
}
