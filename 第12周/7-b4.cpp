#include <iostream>
#include <ctime>

using namespace std;

struct tj_time {
	int tj_year;	//表示年份
	int tj_month;	//表示月(1-12)
	int tj_day;	//表示日(1-28/29/30/31)
	int tj_hour;	//表示小时(0-23)
	int tj_minute;	//表示分(0-59)
	int tj_second;	//表示秒(0-59)
};

/* 可以在此定义其它需要的函数 */

const int s_entr=60;
const int m_entr=60;
const int h_entr=24;
const int month_entr=13;

int is_leap_year(int year);

void entrance(struct tj_time *x)
{
	while (x->tj_second>=s_entr)
	{
		//分进位
		x->tj_second=x->tj_second-s_entr;
		x->tj_minute++;
		//时进位，分归零
		if (x->tj_minute>=m_entr)
		{
			x->tj_minute=0;
			x->tj_hour++;
			//日进位，时归零
			if (x->tj_hour>=h_entr)
			{
				x->tj_hour=0;
				x->tj_day++;
				//月进位，日归一
				switch (x->tj_month)
				{
					case 1:
						if (x->tj_day>=31+1)
						{
							x->tj_day=1;
							x->tj_month++;
						}
						break;
					case 2:
						if (x->tj_day>=28+is_leap_year(x->tj_year)+1)
						{
							x->tj_day=1;
							x->tj_month++;
						}
						break;
					case 3:
						if (x->tj_day>=31+1)
						{
							x->tj_day=1;
							x->tj_month++;
						}
						break;
					case 4:
						if (x->tj_day>=30+1)
						{
							x->tj_day=1;
							x->tj_month++;
						}
						break;
					case 5:
						if (x->tj_day>=31+1)
						{
							x->tj_day=1;
							x->tj_month++;
						}
						break;
					case 6:
						if (x->tj_day>=30+1)
						{
							x->tj_day=1;
							x->tj_month++;
						}
						break;
					case 7:
						if (x->tj_day>=31+1)
						{
							x->tj_day=1;
							x->tj_month++;
						}
						break;
					case 8:
						if (x->tj_day>=31+1)
						{
							x->tj_day=1;
							x->tj_month++;
						}
						break;
					case 9:
						if (x->tj_day>=30+1)
						{
							x->tj_day=1;
							x->tj_month++;
						}
						break;
					case 10:
						if (x->tj_day>=31+1)
						{
							x->tj_day=1;
							x->tj_month++;
						}
						break;
					case 11:
						if (x->tj_day>=30+1)
						{
							x->tj_day=1;
							x->tj_month++;
						}
						break;
					case 12:
						if (x->tj_day>=31+1)
						{
							x->tj_day=1;
							x->tj_month++;
						}
						break;
					default:;
				}
				//年进位，月归一
				if (x->tj_month>=month_entr)
				{
					x->tj_month=1;
					x->tj_year++;
				}
			}
		}
	}
}

/* 调用系统的转换函数将表示描述的整型值转换为与本题相似的结构体并输出 */
void system_time_output(int input_time)
{
    struct tm *tt;	//struct tm 为系统定义的结构体

    tt = localtime((long *)&input_time);	//localtime为系统函数

    /* tm_*** 为struct tm中的成员，和本题的struct tj_time具体的内容不完全符合，具体含义自己查找相关资料 */
    cout << tt->tm_year+1900 << '-' << tt->tm_mon + 1 << '-' << tt->tm_mday << ' ' << tt->tm_hour << ':' << tt->tm_min << ':' << tt->tm_sec << endl;

    return;
}

/* 输出函数 */
void tj_time_output(struct tj_time *tp)
{
    /* 实现自定义结构的输出，输出形式与system_time_output相同 */
    cout << tp->tj_year << '-' << tp->tj_month << '-' << tp->tj_day << ' ' << tp->tj_hour << ':' << tp->tj_minute << ':' << tp->tj_second << endl;

}

int is_leap_year(int year)
{
	return ((year%4==0) && (year%100!=0)) || (year%400==0);
}

struct tj_time *tj_time_convert(int input_time)
{
    static struct tj_time result;	//定义静态局部变量，不准动

    /* 实现过程开始，在下面添加相应的定义及执行语句即可 */

	result.tj_year=1970;
	result.tj_month=1;
	result.tj_day=1;
	result.tj_hour=8;
	result.tj_minute=0;
	result.tj_second=0;
	
	result.tj_second=result.tj_second+input_time;

	entrance(&result);

    /* 实现过程结束 */

    return &result;	//注意，返回的是静态局部变量的地址，本语句不准动
}

int main()
{
	int test_time[] = {1, 123456789, 349823021, 987654321, 1202990407, 1216468807, 1250312143, 1272636353, 1326193524, 1336549496, 1392837128, 1625675376, 2052743737};
	int i;
	struct tj_time *tp;

	for (i=0; i<sizeof(test_time)/sizeof(int); i++) {
		cout << "当时秒数        ：" << test_time[i] << endl;
		cout << "系统转换的结果  ：";
		system_time_output(test_time[i]);
	
		cout << "自定义转换的结果：";
		tp = tj_time_convert(test_time[i]);
		tj_time_output(tp);

		cout << endl << "按回车键继续" << endl;
		getchar();
		}

	if (1) {
		struct tj_time *tp;
		int t=time(0);		//系统函数，取当前系统时间（从1970-01-01 00:00:00开始的秒数）

		cout << "系统转换的当前系统时间：";
		system_time_output(t);
	
		cout << "自定义转换当前系统时间：";
		tp = tj_time_convert(t);
		tj_time_output(tp);

		cout << endl << "按回车键继续" << endl;
		getchar();
		}

	return 0;
}
