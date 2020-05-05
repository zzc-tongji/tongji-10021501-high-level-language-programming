#include <iostream>
using namespace std;

class Days {
	private:
		int year;
		int month;
		int day;
		int is_leap_year();  //判断是否闰年，是：返回1  /   否：返回0
	public:
		int calc_days();     //计算是当年的第几天
		/* 下面可以补充其它需要的类成员函数的定义，数量不限 */
		bool day_exist();
		Days(int y,int m,int d):year(y),month(m),day(d){}
};

/* 此处给出类成员函数的体外实现 */
int Days::is_leap_year()
{
	return ((year%4==0) && (year%100!=0)) || (year%400==0);
}

int Days::calc_days()
{
	int solve=0;
	if (day_exist())
	{
		switch (month)
		{
			case 12:solve=solve+30;
			case 11:solve=solve+31;
			case 10:solve=solve+30;
			case 9:solve=solve+31;
			case 8:solve=solve+31;
			case 7:solve=solve+30;
			case 6:solve=solve+31;
			case 5:solve=solve+30;
			case 4:solve=solve+31;
			case 3:solve=solve+28+is_leap_year();
			case 2:solve=solve+31;
			case 1:solve=solve+0;
				break;
			default:;
		}
		solve=solve+day;
		return solve;
	}
	else
	{
		return -1;
	}
}

bool Days::day_exist()
{
	bool exist=true;
	switch (month)
	{
		case 12:((day>=1)&&(day<=31))?(exist=true):(exist=false);
			break;
		case 11:((day>=1)&&(day<=30))?(exist=true):(exist=false);
			break;
		case 10:((day>=1)&&(day<=31))?(exist=true):(exist=false);
			break;
		case 9:((day>=1)&&(day<=30))?(exist=true):(exist=false);
			break;
		case 8:((day>=1)&&(day<=31))?(exist=true):(exist=false);
			break;
		case 7:((day>=1)&&(day<=31))?(exist=true):(exist=false);
			break;
		case 6:((day>=1)&&(day<=30))?(exist=true):(exist=false);
			break;
		case 5:((day>=1)&&(day<=31))?(exist=true):(exist=false);
			break;
		case 4:((day>=1)&&(day<=30))?(exist=true):(exist=false);
			break;
		case 3:((day>=1)&&(day<=31))?(exist=true):(exist=false);
			break;
		case 2:((day>=1)&&(day<=28+is_leap_year()))?(exist=true):(exist=false);
			break;
		case 1:((day>=1)&&(day<=31))?(exist=true):(exist=false);
			break;
		default:exist=false;
	}
	return exist;
}

/* main函数不准动 */
int main()
{
	if (1) {
		Days d1(2012,3,18);
		cout << "应该输出78， 实际是：" << d1.calc_days() << endl;
		}

	if (1) {
		Days d1(2011,12,31);
		cout << "应该输出365，实际是：" << d1.calc_days() << endl;
		}
	
	if (1) {
		Days d1(2012,12,31);
		cout << "应该输出366，实际是：" << d1.calc_days() << endl;
		}
		
	if (1) {
		Days d1(2011,2,29);
		cout << "应该输出-1， 实际是：" << d1.calc_days() << endl;
		}

	return 0;
}
