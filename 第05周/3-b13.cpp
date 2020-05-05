#include <iostream>
using namespace std;

int main()
{	
	double x;
	cin >> x;
	
	double x_integer;
	double x_decimal;
	double x_decimal_int__stored_double;
	double decimal_changed;
	int x_decimal_int__stored_int;
	
	x_integer=(int)x;
	x_decimal=x-x_integer;
	x_decimal_int__stored_double=100*x_decimal;
	decimal_changed=x_decimal_int__stored_double+0.5;
	x_decimal_int__stored_int=int(decimal_changed);
	
	int x_100;
	x_100=100*x_integer+x_decimal_int__stored_int;
	
	int R_50,R_20,R_10,R_5,R_1,R_5jiao,R_1jiao,R_5fen,R_2fen,R_1fen;
	R_50=x_100/5000;
	R_20=(x_100-5000*R_50)/2000;
	R_10=(x_100-5000*R_50-2000*R_20)/1000;
	R_5=(x_100-5000*R_50-2000*R_20-1000*R_10)/500;
	R_1=(x_100-5000*R_50-2000*R_20-1000*R_10-500*R_5)/100;
	R_5jiao=(x_100-5000*R_50-2000*R_20-1000*R_10-500*R_5-100*R_1)/50;
	R_1jiao=(x_100-5000*R_50-2000*R_20-1000*R_10-500*R_5-100*R_1-50*R_5jiao)/10;
	R_5fen=(x_100-5000*R_50-2000*R_20-1000*R_10-500*R_5-100*R_1-50*R_5jiao-10*R_1jiao)/5;
	R_2fen=(x_100-5000*R_50-2000*R_20-1000*R_10-500*R_5-100*R_1-50*R_5jiao-10*R_1jiao-5*R_5fen)/2;
	R_1fen=(x_100-5000*R_50-2000*R_20-1000*R_10-500*R_5-100*R_1-50*R_5jiao-10*R_1jiao-5*R_5fen-2*R_2fen)/1;
	
	cout << "总数量：" << (R_50+R_20+R_10+R_5+R_1+R_5jiao+R_1jiao+R_5fen+R_2fen+R_1fen) << "张" << endl;
	cout << "50元：" << R_50 << "张" << endl;
	cout << "20元：" << R_20 << "张" << endl;
	cout << "10元：" << R_10 << "张" << endl;
	cout << " 5元：" << R_5 << "张" << endl;
	cout << " 1元：" << R_1 << "张" << endl;
	cout << " 5角：" << R_5jiao << "张" << endl;
	cout << " 1角：" << R_1jiao << "张" << endl;
	cout << " 5分：" << R_5fen << "张" << endl;
	cout << " 2分：" << R_2fen << "张" << endl;
	cout << " 1分：" << R_1fen << "张" << endl;
	
	return 0;
} 
