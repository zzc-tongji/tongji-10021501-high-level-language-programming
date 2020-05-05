#include <iostream>
using namespace std;

int main()
{
    int a,b,c;
    cout << "input a,b" << endl;
    cin >> a >> b;
    c=a+b;
	cout << "a+b=" << a+b << endl;
    return 0;
}

/*
错因：
1.未声明整型变量c；
2.流提取运算符<< 错写成 流插入运算符>>；
3.int main()后面多了一个分号;
4.未对a,b赋初值;
5.缺少预处理指令;
6.缺少命名空间;
7.main函数最后缺少了return0;
*/
