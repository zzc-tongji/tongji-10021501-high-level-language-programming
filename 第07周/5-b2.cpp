#include <iostream>
#include <string>
using namespace std;

char name[50][11];
char number[50][11];
char b[11];
int n;

void input();
void search();

int main()
{

	cout << "请输入班级学生人数：" << endl;
	cin >> n;
	
	input();
	search();

	return 0;
}

void input()
{
	cout << "请按照“姓名 学号”的格式依次输入学生信息，每个人一行：" << endl;
	int i;
	for (i=0;i<=n-1;i++)
	{
		cin >> name[i] >> number[i];
	}
}

void search()
{
	int i;
	cout << "请输入要查找的学生姓名：" << endl;
	cin >> b;

	for (i=0;i<=n-1;i++)
	{
		if (strcmp(name[i],b)==0)
		{
			cout << "***找到该学生***" << endl;
			cout << name[i] << " " << number[i] << endl;
			return;
		}
	}
	cout << "***找不到该学生!!***" << endl;
}
