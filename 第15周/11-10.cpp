#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

class Teacher
{
	public:
		Teacher(int nu,string na,char se);
		void set();
		void display();
	private:
		int num;
		string name;
		char sex;
};

class BirthDate
{
	public:
		BirthDate(int y,int m,int d);
		void set();
		void display();
	private:
		int year;
		int month;
		int day;
};

class Professor:public Teacher
{
	public:
		Professor(int nu=12345,string name="ShenJian",char se='m',int y=1960,int m=1,int d=1);
		void set();
		void set_birthday();
		void display();
	private:
		BirthDate birthday;
};

Teacher::Teacher(int nu,string na,char se)
{
	num=nu;
	name=na;
	sex=se;
}

void Teacher::set()
{
	cin >> num;
	cin >> name;
	cin >> sex;
}

void Teacher::display()
{
	cout << "num:" << num << endl;
	cout << "name:" << name << endl;
	cout << "sex:" << sex << endl;
}

BirthDate::BirthDate(int y,int m,int d)
{
	year=y;
	month=m;
	day=d;
}

void BirthDate::set()
{
	cin >> year;
	cin >> month;
	cin >> day;
}

void Professor::set_birthday()
{
	birthday.set();
}

void BirthDate::display()
{
	cout << "birthday:" << year << "." << month << "." << day << endl;
}

Professor::Professor(int nu,string na,char se,int y,int m,int d):Teacher(nu,na,se),birthday(y,m,d)
{}

void Professor::set()
{
	Teacher::set();
	birthday.set();
}

void Professor::display()
{
	Teacher::display();
	birthday.display();
}

int main()
{
	Professor prof1;
	
	prof1.display();
	prof1.set_birthday();
	prof1.display();
	
	//system("PAUSE"); //濡傛灉鏄疌++浣滀笟灏辨敞閲婃帀
	return 0;
}
