#include <iostream>
using namespace std;

void move_and_output(int *p,int n1,int m1);

int main()
{
	int a[20]={0};
	int n,m,counter;

	cout << "请输入数字的总个数n：" << endl;
	cin >> n;
	cout << "请依次输入这些数：" << endl;
	for (counter=0;counter<n;counter++)
	{
		cin >> *(a+counter);
	}
	cout << "请输入后移量m：" << endl;
	cin >> m;

	move_and_output(a,n,m);

	return 0;

}

void move_and_output(int *p,int n1,int m1)
{
	int counter;
	cout << "结果：" << endl;
	for (counter=0;counter<=n1-1;counter++)
	{
		if (p+counter-m1>=p)
		{
			cout << *(p+counter-m1) << " ";
		}
		else
		{
			cout << *(p+counter-m1+n1) << " ";
		}
	}
	cout << endl;
}
