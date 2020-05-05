#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct student 
{ 
	int *no; 
	char *name; 
	int *score; 
	struct student *next; 
};

int main()
{
	int counter;
	student *p;
	student *q;
	student *head;
	char name_temp[9];
	char *temp;
	ifstream fin;
	
	//鐢宠1
	fin.open("list.txt",ios::in);
	if (fin==NULL)
	{
		cout << "鎵撳紑鏂囦欢澶辫触" << endl;
		return -1;
	}
	for (counter=0;;counter++)
	{
		if (counter>0)
		{
			q=p;
		}
		p=new(student);
		if (p==NULL)
		{
			cout << "鍐呭瓨涓嶈冻" << endl;
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
		
		//鐢宠2
		(*p).no=new int;
		fin >> *((*p).no);
		//鐢宠3
		for (temp=name_temp;temp<=name_temp+8;temp++)
		{
			*temp='\0';
		}
		fin >> name_temp;
		(*p).name=new char[strlen(name_temp)+1];
		strcpy((*p).name,name_temp);
		//鐢宠4
		(*p).score=new int;
		fin>> *((*p).score);

		(*p).next=NULL;
		if (*((*p).no)==9999999)
		{
			break;
		}
	}
	fin.close();

	//杈撳嚭
	for (p=head;p!=(*q).next;)
	{
		cout << *((*p).no) << " " << (*p).name << " " << *((*p).score) << endl;
		p=(*p).next;
	}

	//閲婃斁1
	for(p=head;p;)
	{
		//閲婃斁2-4
		delete (*p).no;
		delete [](*p).name;
		delete (*p).score;
		q=(*p).next;
		delete p;
		p=q;
	}

	//system("PAUSE"); //濡傛灉鏄疌++浣滀笟灏辨敞閲婃帀
	return 0;
}
