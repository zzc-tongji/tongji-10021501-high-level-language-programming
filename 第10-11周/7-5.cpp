//#include <cstdlib>
#include <iostream>
#include <iomanip>
//#include <fstream>
#include <string>
using namespace std;

struct student
	{
		int num;
		string name;
		int score1;
		int score2;
		int score3;
	};

void input(student *p);
//void input_file(student *p); //test
//void output(student *p); //test
student* average(student *p);
void output_max(student *p);

int main()
{
	student stu[11];
	(*stu).score1=0;
	(*stu).score2=0;
	(*stu).score3=0;

	student *p_stu;
	p_stu=stu;

	input(p_stu);
	output_max(average(p_stu));

	//system("PAUSE"); //如果是C++作业就注释掉
	return 0;
}

void input(student *p)
{
	int counter;
	p++;
	for (counter=1;counter<=10;counter++)
	{
		cout << "请输入第" << setw(2) << setfill('0') << counter << "个学生的学号、姓名和三门课的成绩：";
		cin >> p->num >> p->name >> p->score1 >> p->score2 >> p->score3;
		p++;
	}
	cout << endl;
}

/*
void input_file(student *p)
{
	ifstream fin;
	fin.open("stu.txt",ios::in);
	if (fin==NULL)
	{
		cout << "打开文件失败" << endl;
		exit(-1);
	}

	int counter;

	p++;
	for (counter=1;counter<=10;counter++)
	{
		fin >> p->num >> p->name >> p->score1 >> p->score2 >> p->score3;
		p++;
	}

	fin.close();
}
*/

/*
void output(student *p)
{
	int counter;
	p++;
	for (counter=1;counter<=10;counter++)
	{
		cout << p->num << " " << p->name << " " << p->score1 << " " << p->score2 << " " << p->score3 << endl;
		p++;
	}
}
*/

student* average(student *p)
{
	int counter;
	student* max;
	max=p;

	p++;
	for (counter=1;counter<=10;counter++)
	{
		cout << "第" << setw(2) << setfill('0') << counter << "个学生的三门课平均成绩：";
		cout << setiosflags(ios::fixed) << setprecision(2) << ((*p).score1+(*p).score2+(*p).score3)/3.0 << endl;
		if ( ((*p).score1+(*p).score2+(*p).score3)/3.0 > ((*max).score1+(*max).score2+(*max).score3)/3.0 )
		{
			max=p;
		}
		p++;
	}
	cout << endl;

	return max;
}

void output_max(student *p)
{
	cout << "平均分最高的同学是：" << endl;
	cout << p->num << " " << p->name << " " << p->score1 << " " << p->score2 << " " << p->score3 << " ";
	cout << "平均成绩" << ((*p).score1+(*p).score2+(*p).score3)/3.0 << endl << endl;
}

