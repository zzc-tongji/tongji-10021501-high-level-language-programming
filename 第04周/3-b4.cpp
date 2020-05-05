#include <iostream>
using namespace std;

int main()
{
	double x,y;
	cout << "请依次输入横坐标x与纵坐标y，中间用空格隔开：" << endl;
	cin >> x >> y;

	if ((x==0)||(y==0))
	{
		cout << "该点高度为0米" << endl;
	}
	else if ((x>0)&&(y>0)&&(y<=-x+3))
	{
		cout << "该点高度为1米" << endl;
	}
	else if ((x>0)&&(y<0)&&(y>=x-3))
	{
		cout << "该点高度为2米" << endl;
	}
	else if ((x<0)&&(y<0)&&(y>=-x-3))
	{
		cout << "该点高度为3米" << endl;
	}
	else if ((x<0)&&(y>0)&&(y<=x+3)) 
	{
		cout << "该点高度为4米" << endl;
	}	
	else 
	{
		cout << "该点高度为0米" << endl;
	}

    return 0;
}
