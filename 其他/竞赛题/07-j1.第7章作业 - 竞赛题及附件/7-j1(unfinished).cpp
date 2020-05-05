#include <iostream>
#include <ctime>
#include <cmath>
#include <windows.h>
using namespace std;

/* 将光标移动到指定位置 */
void move(HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout,coord);	
}

/* 设置指定的颜色

   颜色的取值由背景色+前景色组成，各16种
	   fg_color：0-7    黑   蓝   绿   青   红   粉   黄   白
	             8-15 亮黑 亮蓝 亮绿 亮青 亮红 亮粉 亮黄 亮白
	   bg_color：0-7    黑   蓝   绿   青   红   粉   黄   白
		         8-15 亮黑 亮蓝 亮绿 亮青 亮红 亮粉 亮黄 亮白
   最终的颜色为 背景色*16+前景色 */
void setcolor(HANDLE hout, const int bg_color, const int fg_color)
{
	SetConsoleTextAttribute(hout, bg_color*16+fg_color);
}

/* 在指定位置，用指定颜色，显示一个字符串 */
void showstr(HANDLE hout, const int X, const int Y, const int bg_color, const int fg_color, const char *str)
{
	const char *p;
	move(hout, X, Y);
	setcolor(hout, bg_color, fg_color);
	for (p=str; *p; p++)
		putchar(*p);
}

/* 在指定位置，用指定颜色，显示一个字符 */
void showch(HANDLE hout, const int X, const int Y, const int bg_color, const int fg_color, const char ch)
{
	move(hout, X, Y);
	setcolor(hout, bg_color, fg_color);
	putchar(ch);
}

/* 在指定位置显示继续信息 */
void to_be_continued(HANDLE hout, char *prompt)
{
	setcolor(hout, 0, 7);
	move(hout, 0, 22);
	cout << prompt << "显示完成，按回车键继续...";
	getchar();
	system("cls"); //调用系统命令清除屏幕
}

int main()
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄

	if (1) {
		int x, y;

		/* 显示16*16的配色框 */
		for (y=0; y<16; y++) {
			for (x=0; x<16; x++) {
				showstr(hout, x*2, y, y, x, "x ");	//在xy位置显示"x "，用x坐标的值做前景色，y坐标的值做背景色
				}
			cout << endl; //16个前景色变换完成后，换一行
			Sleep(100);  //延时0.1秒（以毫秒为单位，1000=1秒）
			}

		to_be_continued(hout, "配色显示");
		}

	if (1) {
		const int MAX_X = 50;
		int x;

		/* 将一个数字从左向右移动 */	
		for (x=0; x<MAX_X; x++) {
			/* 显示一个1 */
			showstr(hout, x, 0, 0, 7, "  *");
			showstr(hout, x, 1, 0, 7, " **");
			showstr(hout, x, 2, 0, 7, "* *");
			showstr(hout, x, 3, 0, 7, "  *");
			showstr(hout, x, 4, 0, 7, "  *");
			showstr(hout, x, 5, 0, 7, "  *");
			showstr(hout, x, 6, 0, 7, "  *");
			showstr(hout, x, 7, 0, 7, "  *");
			showstr(hout, x, 8, 0, 7, "*****");

			/* 延时0.1秒 */
			Sleep(100);	

			if (x<49) {
				/* 清除显示(最后一次保留) */
				showstr(hout, x, 0, 0, 7, "   ");
				showstr(hout, x, 1, 0, 7, "   ");
				showstr(hout, x, 2, 0, 7, "   ");
				showstr(hout, x, 3, 0, 7, "   ");
				showstr(hout, x, 4, 0, 7, "   ");
				showstr(hout, x, 5, 0, 7, "   ");
				showstr(hout, x, 6, 0, 7, "   ");
				showstr(hout, x, 7, 0, 7, "   ");
				showstr(hout, x, 8, 0, 7, "     ");
				}
			}

		to_be_continued(hout, "右移特效");
		}

	if (1) {
		/* 在屏幕的[0,0]-[60,20]区域内随机显示100个字符，值随机，颜色随机
		   说明：未判断位置重复，可能最终字符数少于100
		         未判断前景色/背景色重复，可能某些位置只看到颜色，看不到字符 */	
		const int MAX_X = 60, MAX_Y = 20;
		int x, y, fg_color, bg_color, num;
		char ch;
		
		srand(time(0)); //生成种子

		for (num=0; num<100; num++) {
			x        = rand()%(MAX_X+1);
			y        = rand()%(MAX_Y+1);
			fg_color = rand()%16;
			bg_color = rand()%16;
			ch       = 33+rand()%94;   //ASCII码表中33-126为可见图形字符
			
			/* 显示一个1 */
			showch(hout, x, y, bg_color, fg_color, ch);

			/* 延时0.05秒 */
			Sleep(50);	
			}

		to_be_continued(hout, "随机字符");
		}

	if (1) {
		const int MAX_X = 40, MAX_Y = 15;   //演示区域[0,0]-[40,15]
		const int LOOP_TIME = 20;           //循环显示时间为20秒
		int DELAY = 30;	                    //延时定为30毫秒
		long start_time = time(0);          //取当前系统时间
		char snake[20]="***";               //初始三个*，其它全部\0
		char empty[20]="   ";               //初始三个空格，其它全部\0
		int x, row, y, col, snake_len;
		int bg_color=0, fg_color=15;

		/* 演示时间为LOOP_TIME秒，演示区域[0,0]-[40,15] */	
		while(time(0)-start_time <= LOOP_TIME) {
			snake_len = strlen(snake); //计算一次长度，避免重复调用strlen

			/* 在第0行：从左到右移动 */
			for (x=0; x<=MAX_X-snake_len+1; x++) {
				showstr(hout, x, 0, bg_color, fg_color, snake);
				
				Sleep(DELAY);	//延时
				
				showstr(hout, x, 0, 0, 7, empty); //清除
				}

			fg_color=(fg_color-1+16)%16;
			bg_color=(bg_color+1)%16;

			/* 在第MAX_X列：向下移动 */
			for (y=1; y<MAX_Y; y++) {
				/* 若干个y列，每列都显示一个'*' */
				for (col=y; col >= (y <= snake_len ? 1 : y-snake_len+1); col--)
					showch(hout, MAX_X, col, bg_color, fg_color, '*');
				/* 剩下的部分（在第0行还没有拐弯的部分依旧显示在第0行） */
				if (y < snake_len)
					showstr(hout, MAX_X-(snake_len-y)+1, 0, bg_color, fg_color, &snake[y]);

				Sleep(DELAY);	//延时

				/* 清除显示 */
				for (col=y; col >= (y <= snake_len ? 1 : y-snake_len+1); col--)
					showch(hout, MAX_X, col, 0, 7, ' ');
				if (y < snake_len)
					showstr(hout, MAX_X-(snake_len-y)+1, 0, 0, 7, &empty[y]);
				}

			/* 头已经到达第MAX_Y行，尾部还竖着 */
			for (row=1; row<=snake_len-1;  row++) {
				/* 第MAX_Y行显示 */
				showstr(hout, MAX_X-row+1, MAX_Y, bg_color, fg_color, &snake[snake_len-row]);
				/* 竖行显示 */
				for(col=1; col<=snake_len-row; col++)
					showch(hout, MAX_X, MAX_Y-col, bg_color, fg_color, '*');

				Sleep(DELAY);
				
				/* 清除显示 */
				showstr(hout, MAX_X-row+1, MAX_Y, 0, 7, &empty[snake_len-row]);
				for(col=1; col<=snake_len-row; col++)
					showch(hout, MAX_X, MAX_Y-col, 0, 7, ' ');
				}

			fg_color=(fg_color-1+16)%16;
			bg_color=(bg_color+1)%16;

			/* 在第MAX_Y行：从右到左移动 */
			for (x=MAX_X-snake_len+1; x>=0; x--) {
				showstr(hout, x, MAX_Y, bg_color, fg_color, snake);

				Sleep(DELAY);	//延时
				
				showstr(hout, x, MAX_Y, 0, 7, empty); //清除
				}

			fg_color=(fg_color-1+16)%16;
			bg_color=(bg_color+1)%16;

			/* 在第0列：向上移动 */
			for (y=MAX_Y-1; y>=1; y--) {
				/* 若干个y列，每列都显示一个'*' */
				for (col=y; col <= (y+snake_len<MAX_Y ? y+snake_len-1 : MAX_Y-1); col++)
					showch(hout, 0, col, bg_color, fg_color, '*');
				/* 剩下的部分（在第MAX_Y行还没有拐弯的部分依旧显示在第MAX_Y行） */
				if (y+snake_len > MAX_Y)
					showstr(hout, 0, MAX_Y, bg_color, fg_color, &snake[MAX_Y-y]);

				Sleep(DELAY);	//延时

				/* 清除显示 */
				for (col=y; col <= (y+snake_len<MAX_Y ? y+snake_len-1 : MAX_Y-1); col++)
					showch(hout, 0, col, 0, 7, ' ');
				if (y+snake_len > MAX_Y)
					showstr(hout, 0, MAX_Y, 0, 7, &empty[MAX_Y-y]);
				}

			/* 头已经到达第0行，尾部还竖着 */
			for (row=1; row<=snake_len-1;  row++) {
				/* 第MAX_Y行显示 */
				showstr(hout, 0, 0, bg_color, fg_color, &snake[snake_len-row]);
				/* 竖行显示 */
				for(col=1; col<=snake_len-row; col++)
					showch(hout, 0, col, bg_color, fg_color, '*');

				Sleep(DELAY);
				
				/* 清除显示 */
				showstr(hout, 0, 0, 0, 7, &empty[snake_len-row]);
				for(col=1; col<=snake_len-row; col++)
					showch(hout, 0, col, 0, 7, ' ');
				}

			/* 绕完一圈，蛇的长度+3，但不能超过数组大小20 */
			if (snake_len<=16) {
				strcat(&snake[snake_len], "***");  //数组的后面已保证全部\0，因此不再判断\0
				strcat(&empty[snake_len], "   ");  //用于清除痕迹的字符串同步加长
				}

			/* 下一圈的延时减少3ms */
			if (DELAY >= 3)
				DELAY -= 3;
			}

		to_be_continued(hout, "贪吃蛇");
		}

	if (1) {
		const double PI = 3.14159;
		int LOOP_TIME = 20;						//循环20次
		int CENTER_X = 20, CENTER_Y = 10, R=10;	//圆心初值(20,10),半径初值10
		int bg_color = 0, fg_color = 15;		//颜色初值
		int x, y;						
		int angle;

		srand(time(0)); //生成种子

		while(LOOP_TIME--) {
			/* 递增角度为15°，sin/cos函数的单位是弧度 */
			for (angle=0; angle<360; angle+=15) {
				/* 考虑到x/y的屏幕纵横比，如果直接xy，显示为椭圆，将x*2后显示得近似于圆
				   另：x/y的坐标值为整型量，同时浮点数还考虑了四舍五入 */
				x = CENTER_X + 2*(R*cos(PI*angle/180)+0.5); //2*x后近似于圆
				y = CENTER_Y +   (R*sin(PI*angle/180)+0.5);
				showch(hout, x, y, bg_color, fg_color, '*');
				}

			Sleep(500);  //延时0.2秒

			if (LOOP_TIME>0) { //最后一个不要消除
				for (angle=0; angle<360; angle+=15) {
					/* 考虑到x/y的屏幕纵横比，如果直接xy，显示为椭圆，将x*2后显示得近似于圆
					   另：x/y的坐标值为整型量，同时浮点数还考虑了四舍五入 */
					x = CENTER_X + 2*(R*cos(PI*angle/180)+0.5); //2*x后近似于圆
					y = CENTER_Y +   (R*sin(PI*angle/180)+0.5);
					showch(hout, x, y, 0, 7, ' ');	//清除
					}
				}

			CENTER_X = 20+rand()%21;	//随机生成圆心X[20..40]
			CENTER_Y = 10+rand()%11;	//随机生成圆心Y[10..20]
			R        = 5+rand()%6;		//随机生成半径值[5..10]
			bg_color = rand()%16;		//随机生成背景色
			fg_color = rand()%16;		//随机生成前景色
			}

		to_be_continued(hout, "圆特效");
		}

	return 0;
}
