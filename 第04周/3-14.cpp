#include <iostream>
using namespace std;

int main()
{
	long int a1=0,a2=0,a3=0,a4=0,temp=0;
	cout << "请依次输入四个整数（绝对值不大于20亿），中间用空格隔开：" << endl;
	cin >> a1 >> a2 >> a3 >> a4;

	if (a1>a2) //比较a1和a2
	{
		temp=a1;
		a1=a2;
		a2=temp;
	}
	if (a1>a3) //比较a1和a3
	{
		temp=a1;
		a1=a3;
		a3=temp;
	}
	if (a1>a4) //比较a1和a4
	{
		temp=a1;
		a1=a4;
		a4=temp;
	}
	if (a2>a3) //比较a2和a3
	{
		temp=a2;
		a2=a3;
		a3=temp;
	}
	if (a2>a4) //比较a2和a4
	{
		temp=a2;
		a2=a4;
		a4=temp;
	}
	if (a3>a4) //比较a3和a4
	{
		temp=a3;
		a3=a4;
		a4=temp;
	}
	
	printf("按从小到大排列依次为\n");
	printf("%d %d %d %d \n",a1,a2,a3,a4);


	return 0;
}
