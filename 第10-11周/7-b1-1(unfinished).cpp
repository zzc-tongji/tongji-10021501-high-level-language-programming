#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct student
{
	int num;
	string name;
	int score;
	int sort;
	student *next;
};

/*排序来不及做了，只做了内存空间申请和撤销，以及测试*/

int main()
{
	int total;
	int counter;
	student *head;
	student *p;
	student *q;
	student *dizhi[1000]={NULL};
	ifstream fin;

	//申请
	fin.open("student.txt",ios::in);
	if (fin==NULL)
	{
		cout << "打开文件失败" << endl;
		return -1;
	}
	fin >> total;
	total--;
	for (counter=0;counter<=total;counter++)
	{
		if (counter>0)
		{
			q=p;
		}
		p=(student *)calloc(1,sizeof(student));
		if (p==NULL)
		{
			cout << "内存不足" << endl;
			return -1;
		}

		if (counter==0)
		{
			head=p;
		}
		else
		{
			(*q).next=p;
		}
		fin >> (*p).num >> (*p).name >> (*p).score;
		(*p).next=NULL;
		dizhi[counter]=p;
	}
	fin.close();

	//测试
	for (p=head;p!=NULL;)
	{
		cout << p << " ";
		cout << (*p).num << " " << (*p).name << " " << (*p).score << " ";
		cout << (*p).next;
		cout << endl;
		p=(*p).next;
	}

	//释放
	for (p=head;p;)
	{
		q=(*p).next;
		free(p);
		p=q;
	}

	//system("PAUSE"); //如果是C++作业就注释掉
	return 0;
}
