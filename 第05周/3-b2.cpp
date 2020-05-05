#include <iostream>
using namespace std;

int main()
{
	long int x=0;
	cout << "请输入一个五位整数：" << endl;
	cin >> x;
	
	long int b10e0=0; //个位
	long int b10e1=0; //十位
	long int b10e2=0; //百位
	long int b10e3=0; //千位
	long int b10e4=0; //万位

	b10e0=x%10;
	b10e1=(x-1*b10e0)%100/10;
	b10e2=(x-1*b10e0-10*b10e1)%1000/100;
	b10e3=(x-1*b10e0-10*b10e1-100*b10e2)%10000/1000;
	b10e4=(x-1*b10e0-10*b10e1-100*b10e2-1000*b10e3)%100000/10000;

	cout << "万位：" << b10e4 << endl;
	cout << "千位：" << b10e3 << endl;
	cout << "百位：" << b10e2 << endl;
	cout << "十位：" << b10e1 << endl;
	cout << "个位：" << b10e0 << endl;
	
	return 0;
}
