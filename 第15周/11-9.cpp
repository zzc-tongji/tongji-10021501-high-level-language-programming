#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

class Teacher
{
	public:
		void display();
	protected:
		string name;
		int age;
		string sex;
		string addr;
		string tel;
		string title;
};

class Cadre
{
	public:
	
	protected:
		string name;
		int age;
		string sex;
		string addr;
		string tel;
		int wages;
};

class Teacher_Cadre:public Teacher,public Cadre
{
	public:
		Teacher_Cadre(string na="ShenJian",int ag=43,string se="male",string ad="Shanghai",string te="13912345678",string ti="jiangshi",int wa=100000);
		void set();
		void show();
};

void Teacher::display()
{
	cout << "name:" << name << endl;
	cout << "age:" << age << endl;
	cout << "sex:" << sex << endl;
	cout << "addr:" << addr << endl;
	cout << "tel:" << tel << endl;
	cout << "title:" << title << endl;
}

Teacher_Cadre::Teacher_Cadre(string na,int ag,string se,string ad,string te,string ti,int wa)
{
	Teacher::name=na;
	Teacher::age=ag;
	Teacher::sex=se;
	Teacher::addr=ad;
	Teacher::tel=te;
	title=ti;
	wages=wa;
}
void Teacher_Cadre::set()
{
	cin >> Teacher::name;
	cin >> Teacher::age;
	cin >> Teacher::sex;
	cin >> Teacher::addr;
	cin >> title;
	cin >> wages;
}

void Teacher_Cadre::show()
{
	display();
	cout << "wages:" << Cadre::wages << endl;
}

/*
int main()
{
	Teacher_Cadre teac;
	
	teac.show();
	
	system("PAUSE"); //濡傛灉鏄疌++浣滀笟灏辨敞閲婃帀
	return 0;
}
*/
