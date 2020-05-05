#include <iostream>
using namespace std;
int add(int,int);
int main()
{
	int a,b;
	cout << "input a,b" << endl;
    cin >> a >> b;
	int c=add(a,b);
	cout << "a+b=" << c << endl;
	return 0;
}
int add(int x,int y)
{
	int z;
	z=x+y;
	return(z);
}

/*
错因：
1.整型变量c未声明;
2.函数add()未提前声明;
3.c=add(a,b)语句后面少了分号;
4.int add(int x,int y)后面多了分号;
5.整型变量z未声明;
6.a,b未赋值，系统会输出随机的结果;
*/
