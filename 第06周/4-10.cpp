#include <iostream>
using namespace std;

void zhuanhuan(int n0);

int main()
{
    int n;
	A:
	cout << "请输入一个在-1000000—+1000000范围内的整数：" << endl;
    cin >> n;
	if ((n>=1000000)||(n<-1000000))
	{
		cout << "输入错误!!" << endl;
		goto A;
	}

    cout << "输出:" << endl;
    if  (n<0)
    {
        cout << "-";
        n=-n;
    }
    zhuanhuan(n);
    cout << endl;

    return 0; 
}

void zhuanhuan(int n0)
{
     int i;
	 i=n0/10;
     if (i!=0)
	 {
        zhuanhuan(i);
	 }
     cout << char(n0%10+48);
}
