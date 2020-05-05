#include <iostream>
using namespace std;

int max(int p,int q);
int max(int p,int q,int r);
int max(int p,int q,int r,int s);

int main()
{
	int n=1,a=1,b=1,c=1,d=1;
	A:
	cout << "请输入（数据个数仅限2,3,4，数据需为不大于2000000000的正整数）：" << endl;
	cin >> n;
	switch (n)
	{
		case 2:
			cin >> a >> b;
			break;
		case 3:
			cin >> a >> b >> c;
			break;
		case 4:
			cin >> a >> b >> c >> d;
			break;
		default:
			cout << "输入错误" << endl;
			cin.clear();
			cin.sync();
			goto A;
	}
	if ((a<=0)||(a>=2000000001))
	{
		cout << "输入错误" << endl;
		cin.clear();
		cin.sync();
		goto A;
	}
	else if ((b<=0)||(a>=2000000001))
	{
		cout << "输入错误" << endl;
		cin.clear();
		cin.sync();
		goto A;
	}
	else if ((c<=0)||(a>=2000000001))
	{
		cout << "输入错误" << endl;
		cin.clear();
		cin.sync();
		goto A;
	}
	else if ((d<=0)||(a>=2000000001))
	{
		cout << "输入错误" << endl;
		cin.clear();
		cin.sync();
		goto A;
	}

	cout << "这" << n << "个数中的";
	if (n==2)
	{
		cout << "最大数为" << max(a,b) << endl;
	}
	else if (n==3)
	{
		cout << "最大数为" << max(a,b,c) << endl;
	}
	else 
	{
		cout << "最大数为" << max(a,b,c,d) << endl;
	}

	return 0;
}

int max(int p,int q)
{
	return ((p>q)?(p):(q));
}

int max(int p,int q,int r)
{
	return ((max(p,q)>r)?(max(p,q)):(r));
}

int max(int p,int q,int r,int s)
{
	return ((max(p,q,r)>s)?(max(p,q,r)):(s));
}
