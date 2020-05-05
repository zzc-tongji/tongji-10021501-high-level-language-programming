#include <iostream>
using namespace std;
	
struct date
{
	int year;
	int month;
	int day;
};

int main()
{
	int day_feb=28;
	int solve=0;
	date today;

	cin >> today.year >> today.month >> today.day;

	//判断闰年，已完成
	if (((today.year%4==0)&&(today.year%100!=0))||(today.year%400==0))
	{
		day_feb=29;
	}

	//日期存在性 
	bool exist=true;
	switch (today.month)
	{
		case 12:((today.day>=1)&&(today.day<=31))?(exist=true):(exist=false);
			break;
		case 11:((today.day>=1)&&(today.day<=30))?(exist=true):(exist=false);
			break;
		case 10:((today.day>=1)&&(today.day<=31))?(exist=true):(exist=false);
			break;
		case 9:((today.day>=1)&&(today.day<=30))?(exist=true):(exist=false);
			break;
		case 8:((today.day>=1)&&(today.day<=31))?(exist=true):(exist=false);
			break;
		case 7:((today.day>=1)&&(today.day<=31))?(exist=true):(exist=false);
			break;
		case 6:((today.day>=1)&&(today.day<=30))?(exist=true):(exist=false);
			break;
		case 5:((today.day>=1)&&(today.day<=31))?(exist=true):(exist=false);
			break;
		case 4:((today.day>=1)&&(today.day<=30))?(exist=true):(exist=false);
			break;
		case 3:((today.day>=1)&&(today.day<=31))?(exist=true):(exist=false);
			break;
		case 2:((today.day>=1)&&(today.day<=day_feb))?(exist=true):(exist=false);
			break;
		case 1:((today.day>=1)&&(today.day<=31))?(exist=true):(exist=false);
			break;
		default:exist=false;	
	}

	//运算 
	if (exist)
	{
		switch (today.month)
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
			case 3:solve=solve+day_feb;
			case 2:solve=solve+31;
			case 1:solve=solve+0;
				break;
			default:;
		}
		solve=solve+today.day;
		cout << solve << endl;
	}
	else
	{
		cout << "输入错误" << endl;
	}

	//system("PAUSE"); //如果是C++作业就注释掉
	return 0;
}
