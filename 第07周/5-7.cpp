#include <iostream>
using namespace std;

int choose_largest(double h1,double h2,double h3,double h4,double h5,double h6); //输出某行元素中最大元素所在列数
int choose_smallest(double l1,double l2,double l3,double l4,double l5); //输出某列元素中最小元素所在行数

int main()
{
	double a[6][7]={0};
	int i,j;
	int x,y;
	bool judge=false;
	
	cout << "请依次输入5x6矩阵的各个元素的值：" << endl;
	for (i=1;i<=5;i++)
	{
		for (j=1;j<=6;j++)
		{
			cin >> a[i][j];
		}
	}

	for(i=1;i<=5;i++)
	{
		x=choose_largest(a[i][1],a[i][2],a[i][3],a[i][4],a[i][5],a[i][6]);
		y=choose_smallest(a[1][x],a[2][x],a[3][x],a[4][x],a[5][x]);
		//cout << i << "," << x << "," << y << endl; //测试用
		if (y==i)
		{
			cout << "找出一个鞍点(" << i << "," << x << ")" << endl;
			judge=true;
		}
	}
	if (!judge)
	{
		cout << "该矩阵无鞍点" << endl;
	}

	return 0;
}

int choose_largest(double h1,double h2,double h3,double h4,double h5,double h6) //输出某行元素中最大元素所在列数
{
	int solve;
	
	solve=1;
	if (h1<h2)
	{
		solve=2;
		h1=h2;
	}
	if (h1<h3)
	{
		solve=3;
		h1=h3;
	}
	if (h1<h4)
	{
		solve=4;
		h1=h4;
	}
	if (h1<h5)
	{
		solve=5;
		h1=h5;
	}
	if (h1<h6)
	{
		solve=6;
	}

	return(solve);
}

int choose_smallest(double l1,double l2,double l3,double l4,double l5) //输出某列元素中最小元素所在行数
{
	int solve;
	
	solve=1;
	if (l1>l2)
	{
		solve=2;
		l1=l2;
	}
	if (l1>l3)
	{
		solve=3;
		l1=l3;
	}
	if (l1>l4)
	{
		solve=4;
		l1=l4;
	}
	if (l1>l5)
	{
		solve=5;
	}

	return(solve);
}
