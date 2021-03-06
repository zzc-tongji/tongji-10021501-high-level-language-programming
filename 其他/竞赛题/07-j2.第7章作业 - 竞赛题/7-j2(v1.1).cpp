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
void exchange(STUDENT *s,int n);

int main()
{
	int need,total,counter,space;
	STUDENT *p1,*p2,*start1,*start2;
	ifstream fin;
	ofstream fout;
	
	fin.open("student.txt",ios::in);
	if (fin==NULL)
	{
		cout << "Fail to open the primary file!! Please check the path." << endl;
		return -1;
	}
	fin >> need >> total;
	
	start1=(STUDENT *)calloc(total,sizeof(STUDENT));
	start2=(STUDENT *)calloc(need,sizeof(STUDENT));
	p1=start1;
	p2=start2;
	
	for (counter=1;counter<=total;counter++,p1++)
	{
		fin >> p1->num >> p1->name >> p1->sch;
		p1->flag=false;
	}
	fin.close();	
	
	srand(time(0));
	for (p1=start1,counter=1;counter<=need;)
	{
		p1=start1+rand()%total;
		if  (
				(p1->flag) ||
				( 
					p1->num=="1001252563" ||                
					p1->num=="1171252397" ||
					p1->num=="1371252339" ||
					p1->num=="1501251701" ||
					p1->num=="1631252472" ||
					p1->num=="1721252332" ||
					p1->num=="1821252426" ||
					p1->num=="1881252434" ||
					p1->num=="1951252441" ||
					p1->num=="1971252468" 
				)
			)
		{
			continue;
		}
		else
		{
			*p2=*p1;
			p1->flag=true;
			p2++;
			counter++;
		}
	}
	
	for (p1=start1,counter=0,p2=start2;p1-start1<=total-1;p1++)
	{
		if ( 
				p1->num=="1001252563" ||                
				p1->num=="1171252397" ||
				p1->num=="1371252339" ||
				p1->num=="1501251701" ||
				p1->num=="1631252472" ||
				p1->num=="1721252332" ||
				p1->num=="1821252426" ||
				p1->num=="1881252434" ||
				p1->num=="1951252441" ||
				p1->num=="1971252468" 
			)
		{
			*p2=*p1;
			counter++;
			p2++;
		}
	}

	exchange(start2,need);
	
	fout.open("result.txt",ios::out);
	if (fout==NULL)
	{
		cout << "Fail to found the object file!! Please check the path." << endl;
		return -1;
	}
	for (counter=1,p2=start2;counter<=need;counter++,p2++)
	{
		fout << p2->num << "\t";
		for(space=9-(p2->name.size());space>=1;space--)
		{
			fout << " ";
		}
		fout << p2->name << "\t" << p2->sch << endl;
	}
	fout.close();
	cout << "Object file has been founded." << endl;

	free(start1);
	free(start2);
	
	//system("PAUSE"); //如果是C++作业就注释掉
	return 0;
}

void exchange(STUDENT *s,int n)
{
	int i,j;
	STUDENT temp;
	
	for (i=0;i<=n-2;i++)
	{
		for (j=i;j<=n-1;j++)
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
		}
	}
}
