#include <iostream>
using namespace std;

struct tj_time {
	int tj_year;	//表示年份
	int tj_month;	//表示月(1-12)
	int tj_day;	//表示日(1-28/29/30/31)
	int tj_hour;	//表示小时(0-23)
	int tj_minute;	//表示分(0-59)
	int tj_second;	//表示秒(0-59)
};

static struct tj_time result={1970,1,1,8,0,0};
const int s_entr=60;
const int m_entr=60;
const int h_entr=24;
const int month_entr=13;

void entrance();
int is_leap_year(int year);

int main()
{
	while(1)
	{
		int second;
		cin >> second;
		result.tj_second=result.tj_second+second;

		entrance();

		cout << result.tj_year << "-" << result.tj_month << "-" << result.tj_day << " ";
		cout << result.tj_hour << ":" << result.tj_minute << ":" << result.tj_second << endl;

		cout << endl; 
		result.tj_year=1970;
		result.tj_month=1;
		result.tj_day=1;
		result.tj_hour=8;
		result.tj_minute=0;
		result.tj_second=0;
	}
	return 0;
}

void entrance()
{
	while (result.tj_second>=s_entr)
	{
		//分进位
		result.tj_second=result.tj_second-s_entr;
		result.tj_minute++;
		//时进位，分归零
		if (result.tj_minute>=m_entr)
		{
			result.tj_minute=0;
			result.tj_hour++;
			//日进位，时归零
			if (result.tj_hour>=h_entr)
			{
				result.tj_hour=0;
				result.tj_day++;
				//月进位，日归一
				switch (result.tj_month)
				{
					case 1:
						if (result.tj_day>=31+1)
						{
							result.tj_day=1;
							result.tj_month++;
						}
						break;
					case 2:
						if (result.tj_day>=28+is_leap_year(result.tj_year)+1)
						{
							result.tj_day=1;
							result.tj_month++;
						}
						break;
					case 3:
						if (result.tj_day>=31+1)
						{
							result.tj_day=1;
							result.tj_month++;
						}
						break;
					case 4:
						if (result.tj_day>=30+1)
						{
							result.tj_day=1;
							result.tj_month++;
						}
						break;
					case 5:
						if (result.tj_day>=31+1)
						{
							result.tj_day=1;
							result.tj_month++;
						}
						break;
					case 6:
						if (result.tj_day>=30+1)
						{
							result.tj_day=1;
							result.tj_month++;
						}
						break;
					case 7:
						if (result.tj_day>=31+1)
						{
							result.tj_day=1;
							result.tj_month++;
						}
						break;
					case 8:
						if (result.tj_day>=31+1)
						{
							result.tj_day=1;
							result.tj_month++;
						}
						break;
					case 9:
						if (result.tj_day>=30+1)
						{
							result.tj_day=1;
							result.tj_month++;
						}
						break;
					case 10:
						if (result.tj_day>=31+1)
						{
							result.tj_day=1;
							result.tj_month++;
						}
						break;
					case 11:
						if (result.tj_day>=30+1)
						{
							result.tj_day=1;
							result.tj_month++;
						}
						break;
					case 12:
						if (result.tj_day>=31+1)
						{
							result.tj_day=1;
							result.tj_month++;
						}
						break;
					default:;
				}
				//年进位，月归一
				if (result.tj_month>=month_entr)
				{
					result.tj_month=1;
					result.tj_year++;
				}
			}
		}
	}
}

int is_leap_year(int year)
{
	return ((year%4==0) && (year%100!=0)) || (year%400==0);
}
