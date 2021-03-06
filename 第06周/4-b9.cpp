#include <iostream>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X=69;
const int MAX_Y=17;

/* 将光标移动到指定位置 */
void move(HANDLE hout, int X, int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout,coord);	
}

/* 在指定位置处打印一个指定的字符 */
void show(HANDLE hout, int X, int Y, char ch)
{
	move(hout, X, Y);
	putchar(ch);
}

int main()
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
	int    i;

	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
	srand(time(0));

	cout << "************************************************************************" << endl;
	cout << "*                                                                      *" << endl;
	cout << "*                                                                      *" << endl;
	cout << "*                                                                      *" << endl;
	cout << "*                                                                      *" << endl;
	cout << "*                                                                      *" << endl;
	cout << "*                                                                      *" << endl;
	cout << "*                                                                      *" << endl;
	cout << "*                                                                      *" << endl;
	cout << "*                                                                      *" << endl;
	cout << "*                                                                      *" << endl;
	cout << "*                                                                      *" << endl;
	cout << "*                                                                      *" << endl;
	cout << "*                                                                      *" << endl;
	cout << "*                                                                      *" << endl;
	cout << "*                                                                      *" << endl;
	cout << "*                                                                      *" << endl;
	cout << "*                                                                      *" << endl;
	cout << "************************************************************************" << endl;

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数*/
	for (i=0; i<20; i++)
		show(hout, rand()%MAX_X+1, rand()%MAX_Y+1, 'A'+rand()%26);

	/* 在此处添加需要的代码-begin */
	
	int x,y;
	x=35;
	y=9;
	move(hout,x,y);
	
	for (;;)
	{
		char a;
		a=getch();

		if ((a=='Q')||(a=='q'))
		{
			move(hout,0,23);
			goto QUIT;
		}
		else if ((a=='J')||(a=='j'))
		{
			if (x!=1)
			{
				x=x-1;
				move(hout,x,y);
			}
		}
		else if ((a=='L')||(a=='l'))
		{
			if (x!=69)
			{
				x=x+1;
				move(hout,x,y);
			}
		}
		else if ((a=='I')||(a=='i'))
		{
			if (y!=1)
			{
				y=y-1;
				move(hout,x,y);
			}
		}
		else if ((a=='K')||(a=='k'))
		{
			if (y!=17)
			{
				y=y+1;
				move(hout,x,y);
			}
		}
		else if (a==' ')
		{
			show(hout,x,y,' ');
			cout << '\b';
		}
		else
		{;}
	}

QUIT:

	/* 在此处添加需要的代码-end */

	cout << "游戏结束，按任意键退出." << endl;
	getchar();
	return 0;
}
