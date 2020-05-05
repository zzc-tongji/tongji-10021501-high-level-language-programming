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
	int a=1007,b=1015,c=1023,d=1056,e=1073,f=1089;
	STUDENT *g,*h,*k,*l,*m;
	string z;
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
	fin1 >> a >> d;
	
	fin2.open("ImportantSetting.dat",ios::in);
	if (fin2==NULL)
	{
		cout << "Fail to open the important setting file!! Please check the path." << endl;
		return -1;
	}
	cout << "Loading the setting file......" << endl;
	
	for (e=1;e<=c;e++)
	fin2 >> z;
	fin2 >> b; 
	fin2 >> z;
	
	l=(STUDENT *)calloc(d,sizeof(STUDENT));
	m=(STUDENT *)calloc(a,sizeof(STUDENT));
	k=(STUDENT *)calloc(b,sizeof(STUDENT));
	g=l;
	h=m;
	
	for (e=1;e<=d;e++,g++)
	{
		fin1 >> g->num >> g->name >> g->sch;
		g->flag=false;
	}
	fin1.close();
	
	for (e=1,g=k;e<=b+1;e++)
	{
		if (e==6)
		{
			fin2 >> z;
		}
		else
		{
			fin2 >> g->num >> g->name >> g->sch;
			g++;
		}
	}
	fin2.close();
	
	cout << "Loading successed." << endl << endl;
	cout << "Solving the problem......" << endl;
	
	do
	{
		for (g=l,e=1;e<=d;e++,g++)
		{
			g->flag=false;
		}
		for (e=1,g=k,h=m;e<=b;e++,g++,h++)
		{
			*h=*g;
			g->flag=true;
			h->flag=true;
		}
		for (g=l,e=1;e<=a-b;)
		{
			g=l+rand()%d;
			if (g->flag)
			{
				continue;
			}
			else
			{
				*h=*g;
				g->flag=true;
				h->flag=true;
				h++;
				e++;
			}
		}
	}while(exchange(m,a));
	
	cout << "Solving successed." << endl << endl; 
	
	fout.open("result.txt",ios::out);
	if (fout==NULL)
	{
		cout << "Fail to found the object file!! Please check the path." << endl;
		return -1;
	}
	cout << "Saving the object file......" << endl;
	
	for (e=1,h=m;e<=a;e++,h++)
	{
		fout << h->num << "\t";
		for (f=9-(h->name).size();f>=1;f--)
		{
			fout << " ";
		}
		fout << h->name << "\t" << h->sch << endl;
	}
	fout.close();
	
	cout << "Object file has been founded." << endl << endl;

	free(l);
	free(m);
	free(k);
	
	system("PAUSE"); //如果是C++作业就注释掉
	return 0;
}

bool exchange(STUDENT *s,int n)
{
	int i,j;
	STUDENT t;
	
	for (i=0;i<=n-2;i++)
	{
		for (j=i+1;j<=n-1;j++)
		{
			if ( s[i].num > s[j].num)
			{
				t.num  = s[i].num;
				t.name = s[i].name;
				t.sch  = s[i].sch;
				t.flag = s[i].flag;
				
				s[i].num  = s[j].num;
				s[i].name = s[j].name;
				s[i].sch  = s[j].sch;
				s[i].flag = s[j].flag;
				
				s[j].num  = t.num;
				s[j].name = t.name;
				s[j].sch  = t.sch;
				s[j].flag = t.flag;
			}
			else if (s[i].num==s[j].num)
			{
				return true;
			}
		}
	}
	return false;
}
