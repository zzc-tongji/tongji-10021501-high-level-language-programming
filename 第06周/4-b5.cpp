#include <iostream>
using namespace std;

unsigned int Fibonacci_1(short int objective_pri); //中间函数，目的是满足输入数据形式和输出数据要求
unsigned int Fibonacci_2(unsigned int x1,unsigned int x2,short int objective_pri,short int processing_pri); //求值函数，目的是满足迭代要求

int main()
{
	short int n;
REINPUT:
	cout << "请输入一个在1-48（含）范围内的整数：" << endl;
	cin >> n;
	if ((n<=0)||(n>=49))
	{
		cout << "输入错误" << endl;
		goto REINPUT;
	}

	cout << "该项为" << Fibonacci_1(n) << endl;

	return 0;
}

unsigned int Fibonacci_1(short int objective_pri) //中间函数，目的是满足输入数据形式和输出数据要求
{
	if (objective_pri==1)
	{
		return 0;
	}
	else if (objective_pri==2)
	{
		return 1;
	}
	else
	{
		return (Fibonacci_2(0,1,objective_pri,2));
	}
}

unsigned int Fibonacci_2(unsigned int x1,unsigned int x2,short int objective_pri,short int processing_pri) //求值函数，目的是满足迭代要求
{
	unsigned int x;
	x=x1+x2;
	processing_pri=processing_pri+1;

	if(objective_pri==processing_pri)
	{
		return x;
	}
	else
	{
		x1=x2;
		x2=x;
		x=Fibonacci_2(x1,x2,objective_pri,processing_pri);
	}

}

