#include <iostream>
using namespace std;

//从6-b4拷贝，所以多余的函数定义没有删除
void handle(int *in1,int *in2,int *out);			//解题函数
void read(int *receive,int *give,int start_num);	//读值函数
void display(int *p);								//显示函数，读到小于0终止
void arrange(int *p);								//排列函数
void exchange(int *x1,int *x2);						//换值函数
void no_repeat(int *p);								//去重算法（结合arrange函数和display函数使用）

int main()
{
	int a[20]={60,58,56,54,52,50,48,46,44,42,40,38,36,34,32,30,28,26,24,22};
	int b[20]={60,57,54,51,48,45,42,39,36,33,30,27,24,21,18,15,12,9,6,3};
	int c[40]={0};

	handle(a,b,c);

	//system("PAUSE"); //如果是C++作业就注释掉
	return 0;
}

void handle(int *input_1,int *input_2,int *output)
{
	read(output,input_1,0);
	read(output,input_2,20);
	arrange(output);
	//no_repeat(output);
	//arrange(output);
	display(output);
}

void read(int *receive,int *give,int start_num)
{
	int counter;
	for (counter=0;counter<=19;counter++)
	{
		*(receive+start_num+counter)=*(give+counter);
	}
}

void display(int *p)
{
	int counter;
	for (counter=0;counter<=39;counter++)
	{
		if (*(p+counter)<0) break;
		cout << *(p+counter) << endl;
	}
}

void arrange(int *p)
{
	int i,j;
	for (i=0;i<=39;i++)
	{
		for (j=i+1;j<=39;j++)
		{
			if (*(p+i)<*(p+j))
			{
				exchange(p+i,p+j);
			}
		}
	}
}

void exchange(int *x1,int *x2)
{
	int temp;
	temp=*x1;
	*x1=*x2;
	*x2=temp;
}

void no_repeat(int *p)
{
	int counter;
	for (counter=1;counter<=39;counter++)
	{
		if (*(p+counter)==*(p+counter-1))
		{
			*(p+counter-1)=-1;
		}
	}
}
