#include <iostream>
using namespace std;

void display(int (*p)[5]);
double average_course(int (*p)[5],int x);
double average_student(int (*p)[5],int x);
void no_pass_2(int (*p)[5]);
void find_up(int x);

int a[4][5]={
				//0,    1,  2,  3,  4,  5,   //课程编号1-5
				/*1,*/ 96, 94, 90, 92, 87,   //学生1
				/*2,*/ 77, 85, 59, 92, 90,   //学生2
				/*3,*/ 88, 85, 99, 80, 77,   //学生3
				/*4,*/ 68, 77, 54, 20, 15    //学生4
			};

int main()
{
	display(a);
	cout << "统计结果：" << endl;
	cout << "第1门课的平均分为" << average_course(a,1) << endl;
	no_pass_2(a);
	find_up(90);
	find_up(85);
	return 0;
}

void display(int (*p)[5])
{
	int i,j;

	cout << "全部数据如下：" << endl;
	for (i=0;i<=3;i++)
	{
		for (j=0;j<=4;j++)
		{
			cout << *(*(p+i)+j) << " ";
		}
		cout << endl;
	}
	cout << endl;
}

double average_course(int (*p)[5],int x)
{
	double sum=0;
	int counter;

	for (counter=0;counter<=3;counter++)
	{
		sum=sum+*(*(p+counter)+x-1);
	}

	return (sum/4.0);
}

double average_student(int (*p)[5],int x)
{
	double sum=0;
	int counter;

	for (counter=0;counter<=4;counter++)
	{
		sum=sum+*(*(p+x-1)+counter);
	}

	return (sum/5.0);
}

void no_pass_2(int (*p)[5])
{
	int i,j,counter=0;

	for (i=1;i<=4;i++)
	{
		for (j=1;j<=5;j++)
		{
			if (*(*(p+i-1)+j-1)<60)
			{
				counter++;
			}
			if (counter==2)
			{
				cout << "第" << i << "位学生有两门以上不及格！" << "平均成绩" << average_student(a,i) << endl;
				break;
			}
		}
		counter=0;
	}
}

void find_up(int x)
{
	int i;
	for (i=1;i<=4;i++)
	{
		if (average_student(a,i)>=x)
		{
			cout << "第" << i << "位学生平均成绩为" << average_student(a,i) << "，满足条件--不低于" << x << endl;
		}
	}
}
