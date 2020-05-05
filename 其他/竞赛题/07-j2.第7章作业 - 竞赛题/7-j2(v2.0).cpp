#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;

struct STUDENT
{
	string num;
	string name;
	string sch;
	bool flag;
};
bool exchange(STUDENT *s,int n);

int main()
{
	int need,nd,S=1023,total,counter,space;
	STUDENT *p1,*p2,*ned,*start1,*start2;
	string use;
	ifstream fin1;
	ifstream fin2;
	ofstream fout;
	
	srand(time(0));
	
	fin1.open("student.txt",ios::in);
	if (fin1==NULL)
	{
		cout << "Fail to open the primary file!! Please check the path." << endl;
		return -1;
	}
	cout << "Loading the primary file......" << endl;
	fin1 >> need >> total;
	
	fin2.open("ImportantSetting.dat",ios::in);
	if (fin2==NULL)
	{
		cout << "Fail to open the important setting file!! Please check the path." << endl;
		return -1;
	}
	cout << "Loading the setting file......" << endl;
	
	for (counter=1;counter<=S;counter++)
	fin2 >> use;
	fin2 >> nd; 
	fin2 >> use;
	
	start1=(STUDENT *)calloc(total,sizeof(STUDENT));
	start2=(STUDENT *)calloc(need,sizeof(STUDENT));
	ned=(STUDENT *)calloc(nd,sizeof(STUDENT));
	p1=start1;
	p2=start2;
	
	for (counter=1;counter<=total;counter++,p1++)
	{
		fin1 >> p1->num >> p1->name >> p1->sch;
		p1->flag=false;
	}
	fin1.close();
	
	for (counter=1,p1=ned;counter<=nd+1;counter++)
	{
		if (counter==6)
		{
			fin2 >> use;
		}
		else
		{
			fin2 >> p1->num >> p1->name >> p1->sch;
			p1++;
		}
	}
	fin2.close();
	
	cout << "Loading successed." << endl << endl;
	cout << "Solving the problem......" << endl;
	
	do
	{
		for (p1=start1,counter=1;counter<=total;counter++,p1++)
		{
			p1->flag=false;
		}
		for (counter=1,p1=ned,p2=start2;counter<=nd;counter++,p1++,p2++)
		{
			*p2=*p1;
			p1->flag=true;
			p2->flag=true;
		}
		for (p1=start1,counter=1;counter<=need-nd;)
		{
			p1=start1+rand()%total;
			if (p1->flag)
			{
				continue;
			}
			else
			{
				*p2=*p1;
				p1->flag=true;
				p2->flag=true;
				p2++;
				counter++;
			}
		}
	}while(exchange(start2,need));
	
	cout << "Solving successed." << endl << endl; 
	
	fout.open("result.txt",ios::out);
	if (fout==NULL)
	{
		cout << "Fail to found the object file!! Please check the path." << endl;
		return -1;
	}
	cout << "Saving the object file......" << endl;
	
	for (counter=1,p2=start2;counter<=need;counter++,p2++)
	{
		fout << p2->num << "\t";
		for (space=9-(p2->name).size();space>=1;space--)
		{
			fout << " ";
		}
		fout << p2->name << "\t" << p2->sch << endl;
	}
	fout.close();
	
	cout << "Object file has been founded." << endl << endl;

	free(start1);
	free(start2);
	free(ned);
	
	system("PAUSE"); //如果是C++作业就注释掉
	return 0;
}

bool exchange(STUDENT *s,int n)
{
	int i,j;
	STUDENT temp;
	
	for (i=0;i<=n-2;i++)
	{
		for (j=i+1;j<=n-1;j++)
		{
			if ( s[i].num > s[j].num)
			{
				temp.num  = s[i].num;
				temp.name = s[i].name;
				temp.sch  = s[i].sch;
				temp.flag = s[i].flag;
				
				s[i].num  = s[j].num;
				s[i].name = s[j].name;
				s[i].sch  = s[j].sch;
				s[i].flag = s[j].flag;
				
				s[j].num  = temp.num;
				s[j].name = temp.name;
				s[j].sch  = temp.sch;
				s[j].flag = temp.flag;
			}
			else if (s[i].num==s[j].num)
			{
				return true;
			}
		}
	}
	return false;
}
