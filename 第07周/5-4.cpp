#include <iostream>
using namespace std;

int main()
{
	double a[10]={16,24,32,41,50,62,75,87,93};
	int i;
	for (i=0;i<=8;i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	cout << "请输入一个数：";
	cin >> a[9];
	
	double temp;
	for (i=0;i<=8;i++)
	{
		if (a[i]>a[9])
		{
			temp=a[i];
			a[i]=a[9];
			a[9]=temp;
		}
	}
	
	for (i=0;i<=9;i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	return 0;
}
