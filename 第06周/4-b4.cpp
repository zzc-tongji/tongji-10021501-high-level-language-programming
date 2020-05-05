#include <iostream>
using namespace std;

void zhuanhuan(int x);

int main()
{
	int n;
REINPUT:
	cout << "请输入一个在-1000000—+1000000范围内的整数：" << endl;
    cin >> n;
	if ((n>=1000000)||(n<-1000000))
	{
		cout << "输入错误!!" << endl;
		goto REINPUT;
	}

	cout << "输出:" << endl;
    
	bool positive=true;
	if  (n<0)
    {
        n=-n;
		positive=false;
    }

	zhuanhuan(n);
	
	if  (!positive)
    {
        cout << "-";
    }
    cout << endl;

    return 0; 
}

void zhuanhuan(int x)
{
	int i;
	i=x%10;
	if (i!=0)
	{
		cout << char(i+48);
		zhuanhuan(x/10);
	}
}
