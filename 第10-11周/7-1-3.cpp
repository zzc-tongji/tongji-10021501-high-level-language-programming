#include <iostream>
using namespace std;

int day(struct date *p_today);

struct date
{
	int y;
	int m;
	int d;
};

int main()
{
	struct date today;
	int result;

	cin >> today.y >> today.m >> today.d;
	
	result=day(&today);
	if (result)
	{
		cout << result << endl;
	}
	else
	{
		cout << "输入错误" << endl;
	}

	//system("PAUSE"); //如果是C++作业就注释掉
	return 0;

}

int day(struct date *p_today)
{
	int day_feb=28;
	bool exist=true;
	int solve=0;

	//判断闰年，已完成
	if ((((*p_today).y%4==0)&&((*p_today).y%100!=0))||((*p_today).y%400==0))
	{
		day_feb=29;
	}

	//日期存在性 
	switch ((*p_today).m)
	{
		case 12:(((*p_today).d>=1)&&((*p_today).d<=31))?(exist=true):(exist=false);
			break;
		case 11:(((*p_today).d>=1)&&((*p_today).d<=30))?(exist=true):(exist=false);
			break;
		case 10:(((*p_today).d>=1)&&((*p_today).d<=31))?(exist=true):(exist=false);
			break;
		case 9:(((*p_today).d>=1)&&((*p_today).d<=30))?(exist=true):(exist=false);
			break;
		case 8:(((*p_today).d>=1)&&((*p_today).d<=31))?(exist=true):(exist=false);
			break;
		case 7:(((*p_today).d>=1)&&((*p_today).d<=31))?(exist=true):(exist=false);
			break;
		case 6:(((*p_today).d>=1)&&((*p_today).d<=30))?(exist=true):(exist=false);
			break;
		case 5:(((*p_today).d>=1)&&((*p_today).d<=31))?(exist=true):(exist=false);
			break;
		case 4:(((*p_today).d>=1)&&((*p_today).d<=30))?(exist=true):(exist=false);
			break;
		case 3:(((*p_today).d>=1)&&((*p_today).d<=31))?(exist=true):(exist=false);
			break;
		case 2:(((*p_today).d>=1)&&((*p_today).d<=day_feb))?(exist=true):(exist=false);
			break;
		case 1:(((*p_today).d>=1)&&((*p_today).d<=31))?(exist=true):(exist=false);
			break;
		default:exist=false;	
	}
	
	//运算 
	if (exist)
	{
		switch ((*p_today).m)
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
		solve=solve+(*p_today).d;
	}

	return solve;
}

