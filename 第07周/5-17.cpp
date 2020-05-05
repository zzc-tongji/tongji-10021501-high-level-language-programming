#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	char name[10][30]={'\0'};
	char number[10][30]={'\0'};
	double score[10]={'\0'};
	int i;

	cout << "请依次输入10名学生的成绩信息，每人一行。" << endl;
	cout << "成绩信息中的 姓名 学号 成绩 之间用空格隔开，姓名的长度不超过29个字符。" << endl;
	for (i=0;i<=9;i++)
	{
		cin >> name[i] >> number[i] >> score[i];
	}

	cout << "不及格学生：姓名 学号 成绩" << endl;
	for (i=0;i<=9;i++)
	{
		if (score[i]<60)
		{
			cout << name[i] << " " << number[i] << " " << setw(2) << score[i] << endl;
		}
	}
	
	return 0;
}
