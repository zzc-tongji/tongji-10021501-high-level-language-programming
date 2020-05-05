#include <iostream>
using namespace std;

void display(int (*p)[4]);
double average_course(int (*p)[4],int x);
double average_student(int (*p)[4],int x);
void no_pass_2(int (*p)[4]);
void find_up(int x);

int a[5][4]={
			//0,    1,  2,  3,  4,   //学生1-4
			/*1,*/ 96, 77, 88, 68,   //课程编号1
			/*2,*/ 94, 85, 85, 77,   //课程编号2
			/*3,*/ 90, 59, 99, 54,   //课程编号3
			/*4,*/ 92, 92, 80, 20,   //课程编号4
			/*5,*/ 87, 90, 77, 15    //课程编号5
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

void display(int (*p)[4])
{
	int i,j;

	cout << "全部数据如下：" << endl;
	for (i=0;i<=4;i++)
	{
		for (j=0;j<=3;j++)
		{
			cout << *(*(p+i)+j) << " ";
		}
		cout << endl;
	}
	cout << endl;
}

double average_course(int (*p)[4],int x)
{
	double sum=0;
	int counter;

	for (counter=0;counter<=3;counter++)
	{
		sum=sum+*(*(p+x-1)+counter);
	}

	return (sum/4.0);
}

double average_student(int (*p)[4],int x)
{
	double sum=0;
	int counter;

	for (counter=0;counter<=4;counter++)
	{
		sum=sum+*(*(p+counter)+x-1);
	}

	return (sum/5.0);
}

void no_pass_2(int (*p)[4])
{
	int i,j,counter=0;

	for (j=1;j<=4;j++)
	{
		for (i=1;i<=5;i++)
		{
			if (*(*(p+i-1)+j-1)<60)
			{
				counter++;
			}
			if (counter==2)
			{
				cout << "第" << j << "位学生有两门以上不及格！" << "平均成绩" << average_student(a,j) << endl;
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
