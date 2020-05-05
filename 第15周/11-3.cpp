#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

class Student
{
	public:
	
	protected:
		int num;
		string name;
		char sex;
};

class Student1:protected Student
{
	public:
		void get_value1();
		void display1();
	private:
		int age;
		string addr;
};

void Student1::get_value1()
{
	cin >> num >> name >> sex;
	cin >> age >> addr;
}

void Student1::display1()
{
	cout << "num:" << num << endl;
	cout << "name:" << name << endl;
	cout << "sex:" << sex << endl;
	cout << "age:" << age << endl;
	cout << "addr:" << addr << endl;
}

int main()
{
	Student1 stud;
	
	stud.get_value1();
	stud.display1();

	//system("PAUSE"); //濡傛灉鏄疌++浣滀笟灏辨敞閲婃帀
	return 0;
}
