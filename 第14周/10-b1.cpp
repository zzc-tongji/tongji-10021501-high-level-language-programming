#include <iostream>
#include <conio.h>
//using namespace std;

class Date {
	private:
		int year;
		int month;
		int day;
	public:
	/* 根据需要定义所需的成员函数、友元函数等 */
		void check(int y,int m,int d,char function);
		int is_leap_year(int y);
		Date();
		Date(int y,int m,int d);
		Date(int x);
		void set(int y=0,int m=0,int d=0);
		void get(int &y,int &m,int &d);
		void show();
		operator int();
};

/* 定义的成员函数、友元函数的实现部分 */
void Date::check(int y,int m,int d,char function)
{
	bool d_flag=true;

	if (function=='D') //用于构造函数，传入操作前的值
	{ //cout << "D" << endl;
		if (y<1900 || y>2099)
		{
			y=2000;
		}

		if (m<1 || m>12)
		{
			m=1;
		}

		switch (m)
		{
			case 1:
				if (d<1 || d>31) d_flag=false;
				break;
			case 2:
				if (d<1 || d>28+Date::is_leap_year(y)) d_flag=false;
				break;
			case 3:
				if (d<1 || d>31) d_flag=false;
				break;
			case 4:
				if (d<1 || d>30) d_flag=false;
				break;
			case 5:
				if (d<1 || d>31) d_flag=false;
				break;
			case 6:
				if (d<1 || d>30) d_flag=false;
				break;
			case 7:
				if (d<1 || d>31) d_flag=false;
				break;
			case 8:
				if (d<1 || d>31) d_flag=false;
				break;
			case 9:
				if (d<1 || d>30) d_flag=false;
				break;
			case 10:
				if (d<1 || d>31) d_flag=false;
				break;
			case 11:
				if (d<1 || d>30) d_flag=false;
				break;
			case 12:
				if (d<1 || d>31) d_flag=false;
				break;
			default:;
		}

		if (!d_flag)
		{
			d=1;
		}
	}

	else if (function=='s') //用于Date::set函数，传入操作前的值
	{ //cout << "s" << endl;
		if (y==0)
		{
			y=year;
		}
		else if (y<1900 || y>2099)
		{
			y=2000;
		}

		if (m==0)
		{
			m=month;
		}
		else if (m<1 || m>12)
		{
			m=1;
		}

		switch (m)
		{
			case 1:
				if (d<1 || d>31) d_flag=false;
				break;
			case 2:
				if (d<1 || d>28+Date::is_leap_year(y)) d_flag=false;
				break;
			case 3:
				if (d<1 || d>31) d_flag=false;
				break;
			case 4:
				if (d<1 || d>30) d_flag=false;
				break;
			case 5:
				if (d<1 || d>31) d_flag=false;
				break;
			case 6:
				if (d<1 || d>30) d_flag=false;
				break;
			case 7:
				if (d<1 || d>31) d_flag=false;
				break;
			case 8:
				if (d<1 || d>31) d_flag=false;
				break;
			case 9:
				if (d<1 || d>30) d_flag=false;
				break;
			case 10:
				if (d<1 || d>31) d_flag=false;
				break;
			case 11:
				if (d<1 || d>30) d_flag=false;
				break;
			case 12:
				if (d<1 || d>31) d_flag=false;
				break;
			default:;
		}

		if (!d_flag && d!=0)
		{
			d=1;
		}
		else if (d==0)
		{
			d=day;
		}
	}

	else ;

	year=y;
	month=m;
	day=d;
}

int Date::is_leap_year(int y)
{
	return ((y%4==0) && (y%100!=0)) || (y%400==0);
}

Date::Date()
{
	year=2000;
	month=1;
	day=1;
}

Date::Date(int y,int m,int d)
{
	Date::check(y,m,d,'D');
}

Date::Date(int x)
{
	if (x<=1)
	{
		Date::set(1900,1,1);
	}
	else if (x>=73049)
	{
		Date::set(2099,12,31);
	}
	else
	{
		Date::set(1900,1,1);
		for (x-=1;x>0;x--)
		{
			day++;
			switch (month)
			{
				case 1:
					if (day>31)
					{
						day=1;
						month++;
					}
					break;
				case 2:
					if (day>28+Date::is_leap_year(year))
					{
						day=1;
						month++;
					}
					break;
				case 3:
					if (day>31)
					{
						day=1;
						month++;
					}
					break;
				case 4:
					if (day>30)
					{
						day=1;
						month++;
					}
					break;
				case 5:
					if (day>31)
					{
						day=1;
						month++;
					}
					break;
				case 6:
					if (day>30)
					{
						day=1;
						month++;
					}
					break;
				case 7:
					if (day>31)
					{
						day=1;
						month++;
					}
					break;
				case 8:
					if (day>31)
					{
						day=1;
						month++;
					}
					break;
				case 9:
					if (day>30)
					{
						day=1;
						month++;
					}
					break;
				case 10:
					if (day>31)
					{
						day=1;
						month++;
					}
					break;
				case 11:
					if (day>30)
					{
						day=1;
						month++;
					}
					break;
				case 12:
					if (day>31)
					{
						day=1;
						month++;
					}
					break;
				default:;
			}
			//年进位，月归一
			if (month>12)
			{
				month=1;
				year++;
			}
		}
	}
}

void Date::set(int y,int m,int d)
{
	Date::check(y,m,d,'s');
}

void Date::get(int &y,int &m,int &d)
{
	y=year;
	m=month;
	d=day;
}

void Date::show()
{
	cout << year << "." << month << "." << day << endl;
}

Date::operator int()
{
	int this_year=0;
	int year_before=0;
	int y;

	switch (month)
	{
		case 12:this_year +=  30;
		case 11:this_year +=  31;
		case 10:this_year +=  30;
		case  9:this_year +=  31;
		case  8:this_year +=  31;
		case  7:this_year +=  30;
		case  6:this_year +=  31;
		case  5:this_year +=  30;
		case  4:this_year +=  31;
		case  3:this_year += (28+Date::is_leap_year(year));
		case  2:this_year +=  31;
		case  1:this_year +=   0;
			break;
		default:;
	}
	this_year += day;

	for (y=1900;y<year;y++)
	{
		if (Date::is_leap_year(y))
		{
			year_before += 366;
		}
		else
		{
			year_before += 365;
		}
	}

	return (this_year+year_before);
}

istream& operator>>(istream &in,Date &date);
ostream& operator<<(ostream &out,Date &date);
Date operator++(Date &date);
Date operator++(Date &date,int);
Date operator--(Date &date);
Date operator--(Date &date,int);
bool operator>(Date &date1,Date &date2);
bool operator>=(Date &date1,Date &date2);
bool operator<(Date &date1,Date &date2);
bool operator<=(Date &date1,Date &date2);
bool operator==(Date &date1,Date &date2);
bool operator!=(Date &date1,Date &date2);

/* ----main函数不准动---- */
int main()
{
	if (1) {
		Date d1;             //2000.1.1
		Date d2(2013,5,29);  //2013.5.29

		cout << "测试初始化，完全正确的赋值" << endl;

		cout << "d1应该是2000.1.1， 实际为：";
		d1.show();
		cout << "d2应该是2013.5.29，实际为：";
		d2.show();

		cout << "任意键继续..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		Date d1(1870,3,15);  //2000.3.15
		Date d2(2112,3,4);   //2000.3.4
		Date d3(2005,13,15); //2005.1.15
		Date d4(2008,5,32);  //2008.5.1

		cout << "测试初始化，年、月、日非法" << endl;

		cout << "d1应该是2000.3.15，实际为：";
		d1.show();
		cout << "d2应该是2000.3.4， 实际为：";
		d2.show();
		cout << "d3应该是2005.1.15，实际为：";
		d3.show();
		cout << "d4应该是2008.5.1， 实际为：";
		d4.show();

		cout << "任意键继续..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
	    Date d1(2011,2,29);   //2011.2.1
	    Date d2(2012,2,29);   //2012.2.29

		cout << "测试初始化，闰年" << endl;

		cout << "d1应该是2011.2.1， 实际为：";
		d1.show();
		cout << "d2应该是2012.2.29，实际为：";
		d2.show();

		cout << "任意键继续..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		Date d1, d2, d3; //都是2000.1.1

		cout << "测试set，带缺省值" << endl;
		d1.set(2013,5,29);	//2013.5.29
		d2.set(2013,5);		//2013.5.1
		d3.set(2013);		//2013.1.1

		cout << "d1应该是2013.5.29，实际为：";
		d1.show();
		cout << "d2应该是2013.5.1， 实际为：";
		d2.show();
		cout << "d3应该是2013.1.1， 实际为：";
		d3.show();

		cout << "任意键继续..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		Date d1(2013,5,29);
		Date d2(2013,5,29);
		Date d3(2013,5,29);

		cout << "测试set，部分不变" << endl;

		d1.set(2007,0,0);   //2007.5.29
		d2.set(0, 3, 18);   //2013.3.18
		d3.set(0, 0, 18);   //2013.5.18

		cout << "d1应该是2007.5.29，实际为：";
		d1.show();
		cout << "d2应该是2013.3.18，实际为：";
		d2.show();
		cout << "d3应该是2013.5.18，实际为：";
		d3.show();

		cout << "任意键继续..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		Date d1(2013,5,29);
		Date d2(2007,5,29);
		Date d3(2013,5,29);
		Date d4(2013,5,29);

		cout << "测试set，年、月、日非法" << endl;

		d1.set(2112,1,0);     //2000.1.29
		d2.set(0, 2, 29);     //2007.2.1
		d3.set(2011, 5, 32);  //2011.5.1
		d4.set(2011, 13, 12); //2011.1.12

		cout << "d1应该是2000.1.29，实际为：";
		d1.show();
		cout << "d2应该是2007.2.1， 实际为：";
		d2.show();
		cout << "d3应该是2011.5.1， 实际为：";
		d3.show();
		cout << "d4应该是2011.1.12，实际为：";
		d4.show();

		cout << "任意键继续..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		Date d1(2013,5,29);
		int y,m,d;

		cout << "测试get" << endl;
		d1.get(y, m, d);

		cout << "应该y=2013,m=5,d=29，实际为：";
		cout << "y=" << y << ",m=" << m << ",d=" << d << endl;

		cout << "任意键继续..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		Date d1(2013,5,29);
		Date d2;

		cout << "测试cout" << endl;
		cout << "d1应该是2013.5.29，实际为："<< d1 << endl;
		cout << "d2应该是2000.1.1， 实际为："<< d2 << endl;

		cout << "任意键继续..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		Date d1;

		cout << "测试cin/cout" << endl;

		cout << "请输入2013 5 29" << endl;
		cin  >> d1;
		cout << "d1应该是2013.5.29，实际为："<< d1 << endl;

		cout << "请输入2012 2 29" << endl;
		cin  >> d1;
		cout << "d1应该是2012.2.29，实际为："<< d1 << endl;

		cout << "请输入2011 2 29" << endl;
		cin  >> d1;
		cout << "d1应该是2011.2.1，实际为："<< d1 << endl;

		cout << "请输入1899 4 10" << endl;
		cin  >> d1;
		cout << "d1应该是2000.4.10，实际为："<< d1 << endl;

		cout << "请输入2012 13 10" << endl;
		cin  >> d1;
		cout << "d1应该是2012.1.10，实际为："<< d1 << endl;

		cout << "请输入2012 4 31" << endl;
		cin  >> d1;
		cout << "d1应该是2012.4.1，实际为："<< d1 << endl;

		cout << "请输入2112 15 34" << endl;
		cin  >> d1;
		cout << "d1应该是2000.1.1，实际为："<< d1 << endl;

		cout << "任意键继续..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		Date d1(1);          //1900.1.1
		Date d2(73049);      //2099.12.31
		Date d3(-100);       //1900.1.1
		Date d4(80000);      //2099.12.31

		cout << "转换构造函数测试，包括合法及非法值" << endl;

		cout << "d1应该是1900.1.1，  实际为：";
		d1.show();
		cout << "d2应该是2099.12.31，实际为：";
		d2.show();
		cout << "d3应该是1900.1.1，  实际为：";
		d3.show();
		cout << "d4应该是2099.12.31，实际为：";
		d4.show();

		d1 = 30000;
		cout << "d1应该是1982.2.19， 实际为：";
		d1.show();

		d2 = 41422;
		cout << "d2应该是2013.5.29， 实际为：";
		d2.show();

		cout << "任意键继续..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		Date d1(1900,1,1);
		Date d2(2099,12,31);
		Date d3(1982,2,19);
		Date d4(2013,5,29);

		cout << "类型转换函数测试，包括合法及非法值" << endl;

		cout << "d1应该是1，     实际为：" << int(d1) << endl;
		cout << "d2应该是73049， 实际为：" << int(d2) << endl;
		cout << "d3应该是30000， 实际为：" << int(d3) << endl;
		cout << "d4应该是41422， 实际为：" << int(d4) << endl;

		cout << "任意键继续..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		Date d1(2013, 5, 1);
		Date d2;

		cout << "测试+/- n" << endl;

		d2 = d1+38;
		cout << "d2应该是2013.6.8，  实际为："<< d2 << endl;

		d2 = 38+d1;
		cout << "d2应该是2013.6.8，  实际为："<< d2 << endl;

		d2 = d1-7;
		cout << "d2应该是2013.4.24， 实际为："<< d2 << endl;

		d1.set(2012,2,28);
		d2 = d1+3;
		cout << "d2应该是2012.3.2，  实际为："<< d2 << endl;

		d1.set(2011,2,28);
		d2 = d1+3;
		cout << "d2应该是2011.3.3，  实际为："<< d2 << endl;

		d1.set(2010,12,28);
		d2 = d1+5;
		cout << "d2应该是2011.1.2，  实际为："<< d2 << endl;

		d1.set(2011,1,1);
		d2 = d1-5;
		cout << "d2应该是2010.12.27，实际为："<< d2 << endl;

		d1.set(2009,12,31);
		d2 = d1+366;
		cout << "d2应该是2011.1.1，  实际为："<< d2 << endl;

		d1.set(2009,1,1);
		d2 = d1-367;
		cout << "d2应该是2007.12.31，实际为："<< d2 << endl;

		d1.set(1900,1,2);
		d2 = d1-10;
		cout << "d2应该是1900.1.1，  实际为："<< d2 << endl;

		d1.set(2099,12,30);
		d2 = d1+5;
		cout << "d2应该是2099.12.31，实际为："<< d2 << endl;

		cout << "任意键继续..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		Date d1(2012,5,1);
		Date d2(2012,3,11);

		cout << "测试-date" << endl;
		cout << "日期差值应为51， 实际为：" << d1-d2 << endl;

		d2.set(2012, 5, 23);
		cout << "日期差值应为-22，实际为：" << d1-d2 << endl;

		d1.set(2012, 3, 2);
		d2.set(2012, 2, 27);
		cout << "日期差值应为4，  实际为：" << d1-d2 << endl;

		d1.set(2011, 3, 2);
		d2.set(2011, 2, 27);
		cout << "日期差值应为3，  实际为：" << d1-d2 << endl;

		d1.set(2011, 1, 2);
		d2.set(2010, 12, 27);
		cout << "日期差值应为6，  实际为：" << d1-d2 << endl;

		d1.set(2011, 1, 1);
		d2.set(2009, 12, 31);
		cout << "日期差值应为366，实际为：" << d1-d2 << endl;

		d1.set(2009, 1, 1);
		d2.set(2007, 12, 31);
		cout << "日期差值应为367，实际为：" << d1-d2 << endl;

		cout << "任意键继续..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		Date d1, d2;

		cout << "测试++/--" << endl;

		d1.set(2012,5,1);
		d2 = d1++;
		cout << "d1应该是2012.5.2，  实际为：" << d1 << endl;
		cout << "d2应该是2012.5.1，  实际为：" << d2 << endl;

		d1.set(2012,5,1);
		d2 = ++d1;
		cout << "d1应该是2012.5.2，  实际为：" << d1 << endl;
		cout << "d2应该是2012.5.2，  实际为：" << d2 << endl;

		d1.set(2012,5,1);
		d2 = d1--;
		cout << "d1应该是2012.4.30， 实际为：" << d1 << endl;
		cout << "d2应该是2012.5.1，  实际为：" << d2 << endl;

		d1.set(2012,5,1);
		d2 = --d1;
		cout << "d1应该是2012.4.30， 实际为：" << d1 << endl;
		cout << "d2应该是2012.4.30， 实际为：" << d2 << endl;

		d1.set(2008,12,31);
		d2 = d1++;
		cout << "d1应该是2009.1.1，  实际为：" << d1 << endl;
		cout << "d2应该是2008.12.31，实际为：" << d2 << endl;

		d1.set(2011,1,1);
		d2 = d1--;
		cout << "d1应该是2010.12.31，实际为：" << d1 << endl;
		cout << "d2应该是2011.1.1，  实际为：" << d2 << endl;

		d1.set(2012,2,28);
		d2 = d1++;
		cout << "d1应该是2012.2.29， 实际为：" << d1 << endl;
		cout << "d2应该是2012.2.28， 实际为：" << d2 << endl;

		d1.set(2011,2,28);
		d2 = d1++;
		cout << "d1应该是2011.3.1，  实际为：" << d1 << endl;
		cout << "d2应该是2011.2.28， 实际为：" << d2 << endl;

		d1.set(2012,3,1);
		d2 = d1--;
		cout << "d1应该是2012.2.29， 实际为：" << d1 << endl;
		cout << "d2应该是2012.3.1，  实际为：" << d2 << endl;

		d1.set(2011,3,1);
		d2 = d1--;
		cout << "d1应该是2011.2.28， 实际为：" << d1 << endl;
		cout << "d2应该是2011.3.1，  实际为：" << d2 << endl;

		d1.set(2099,12,31);
		d2 = d1++;
		cout << "d1应该是2099.12.31，实际为：" << d1 << endl;
		cout << "d2应该是2099.12.31，实际为：" << d2 << endl;

		d1.set(1900,1,1);
		d2 = d1--;
		cout << "d1应该是1900.1.1，  实际为：" << d1 << endl;
		cout << "d2应该是1900.1.1，  实际为：" << d2 << endl;

		cout << "任意键继续..." << endl;
		getch();
		cout << endl;
		}


	if (1) {
		/* 测试比较运算符 */
		Date d1(2013,5,29);
		Date d2(2013,5,29);
		Date d3(2013,4,27);

		cout << "测试比较运算符" << endl;

		cout << "比较结果应为0，实际为：" << (d1 >  d2) << endl;
		cout << "比较结果应为1，实际为：" << (d1 >= d2) << endl;
		cout << "比较结果应为0，实际为：" << (d1 <  d2) << endl;
		cout << "比较结果应为1，实际为：" << (d1 <= d2) << endl;
		cout << "比较结果应为1，实际为：" << (d1 == d2) << endl;
		cout << "比较结果应为0，实际为：" << (d1 != d2) << endl;

		cout << "比较结果应为1，实际为：" << (d1 >  d3) << endl;
		cout << "比较结果应为1，实际为：" << (d1 >= d3) << endl;
		cout << "比较结果应为0，实际为：" << (d1 <  d3) << endl;
		cout << "比较结果应为0，实际为：" << (d1 <= d3) << endl;
		cout << "比较结果应为0，实际为：" << (d1 == d3) << endl;
		cout << "比较结果应为1，实际为：" << (d1 != d3) << endl;

		cout << "任意键继续..." << endl;
		getch();
		cout << endl;
		}

	return 0;
}

istream& operator>>(istream &in,Date &date)
{
	int y,m,d;
	in >> y >> m >> d;
	date.set(y,m,d);
	return in;
}

ostream& operator<<(ostream &out,Date &date)
{
	int y,m,d;
	date.get(y,m,d);
	out << y << "." << m << "." << d;
	return out;
}

Date operator++(Date &date)
{
	int a;

	a=int(date);
	a+=1;
	date=Date(a);

	return date;
}

Date operator++(Date &date,int)
{
	int a;
	Date temp;

	temp=date;
	a=int(date);
	a+=1;
	date=Date(a);

	return temp;
}

Date operator--(Date &date)
{
	int a;

	a=int(date);
	a-=1;
	date=Date(a);

	return date;
}

Date operator--(Date &date,int)
{
	int a;
	Date temp;

	temp=date;
	a=int(date);
	a-=1;
	date=Date(a);

	return temp;
}

bool operator>(Date &date1,Date &date2)
{
	if (int(date1)>int(date2)) return true;
	else return false;
}

bool operator>=(Date &date1,Date &date2)
{
	if (int(date1)>=int(date2)) return true;
	else return false;
}

bool operator<(Date &date1,Date &date2)
{
	if (int(date1)<int(date2)) return true;
	else return false;
}

bool operator<=(Date &date1,Date &date2)
{
	if (int(date1)<=int(date2)) return true;
	else return false;
}

bool operator==(Date &date1,Date &date2)
{
	if (int(date1)==int(date2)) return true;
	else return false;
}

bool operator!=(Date &date1,Date &date2)
{
	if (int(date1)!=int(date2)) return true;
	else return false;
}
