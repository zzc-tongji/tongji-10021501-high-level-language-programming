#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double i;

int main()
{
	double x;
	double x_integer;
	double x_decimal;
	double x_decimal_int__stored_double;
	double decimal_changed;

	long int x_decimal_int__stored_int;


	long int b10e002; //百分位
	long int b10e001; //十分位
	long int b10e00; //个位
	long int b10e01; //十位
	long int b10e02; //百位
	long int b10e03; //千位
	long int b10e04; //万位
	long int b10e05; //十万位
	long int b10e06; //百万位
	long int b10e07; //千万位
	long int b10e08; //亿位
	long int b10e09; //十亿位
	
	cout << "请输入一个在0.01到10000000000之间的浮点数：" << endl;
	cin >> x;
	
	//整数部分提取
	b10e09=long int( x/pow(10,9) );
	b10e08=long int( (x-b10e09*pow(10,9))/pow(10,8) );
	b10e07=long int( (x-b10e09*pow(10,9)-b10e08*pow(10,8))/pow(10,7) );
	b10e06=long int( (x-b10e09*pow(10,9)-b10e08*pow(10,8)-b10e07*pow(10,7))/pow(10,6) );
	b10e05=long int( (x-b10e09*pow(10,9)-b10e08*pow(10,8)-b10e07*pow(10,7)-b10e06*pow(10,6))/pow(10,5) );
	b10e04=long int( (x-b10e09*pow(10,9)-b10e08*pow(10,8)-b10e07*pow(10,7)-b10e06*pow(10,6)-b10e05*pow(10,5))/pow(10,4) );
	b10e03=long int( (x-b10e09*pow(10,9)-b10e08*pow(10,8)-b10e07*pow(10,7)-b10e06*pow(10,6)-b10e05*pow(10,5)-b10e04*pow(10,4))/pow(10,3) );
	b10e02=long int( (x-b10e09*pow(10,9)-b10e08*pow(10,8)-b10e07*pow(10,7)-b10e06*pow(10,6)-b10e05*pow(10,5)-b10e04*pow(10,4)-b10e03*pow(10,3))/pow(10,2) );
	b10e01=long int( (x-b10e09*pow(10,9)-b10e08*pow(10,8)-b10e07*pow(10,7)-b10e06*pow(10,6)-b10e05*pow(10,5)-b10e04*pow(10,4)-b10e03*pow(10,3)-b10e02*pow(10,2))/pow(10,1) );
	b10e00=long int( (x-b10e09*pow(10,9)-b10e08*pow(10,8)-b10e07*pow(10,7)-b10e06*pow(10,6)-b10e05*pow(10,5)-b10e04*pow(10,4)-b10e03*pow(10,3)-b10e02*pow(10,2)-b10e01*pow(10,1))/pow(10,0) );

	//小数部分整体提取，表示为2位整数的形式，存在double型变量中
	x_integer=b10e09*pow(10,9)+b10e08*pow(10,8)+b10e07*pow(10,7)+b10e06*pow(10,6)+b10e05*pow(10,5)+b10e04*pow(10,4)+b10e03*pow(10,3)+b10e02*pow(10,2)+b10e01*pow(10,1)+b10e00*pow(10,0);
	x_decimal=x-x_integer;
	x_decimal_int__stored_double=100*x_decimal;

	//数字处理
	decimal_changed=x_decimal_int__stored_double+0.5;

	//处理完的数字存在long int型变量中
	x_decimal_int__stored_int=long int(decimal_changed);
	
	//小数部分提取
	b10e001=x_decimal_int__stored_int/10;
	b10e002=x_decimal_int__stored_int%10;
	
	/* 测试用
	cout << b10e09 << b10e08 << b10e07 << b10e06 << b10e05  << b10e04 << b10e03 << b10e02 << b10e01 << b10e00 << "." << b10e001 << b10e002 << endl; //正确
	cout << endl; 
	*/
	
	cout << "十亿位：" << b10e09<< endl;
	cout << "亿位：  " << b10e08<< endl;
	cout << "千万位：" << b10e07<< endl;
	cout << "百万位：" << b10e06<< endl;
	cout << "十万位：" << b10e05<< endl;
	cout << "万位：  " << b10e04<< endl;
	cout << "千位：  " << b10e03<< endl;
	cout << "百位：  " << b10e02<< endl;
	cout << "十位：  " << b10e01<< endl;
	cout << "个位：  " << b10e00<< endl;
	cout << "十分位：" << b10e001<< endl;
	cout << "百分位：" << b10e002<< endl;

	return 0;
}
