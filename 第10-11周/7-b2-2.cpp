#include <iostream>
#include <fstream>
using namespace std;

struct student 
{ 
	int no; 
	char name[8]; 
	int score; 
	struct student *next; 
};

int main()
{
	int counter;
	student *p;
	student *q;
	student *head;
	ifstream fin;
	
	//鐢宠
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
		p=new student;
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
		fin >> (*p).no >> (*p).name >> (*p).score;
		(*p).next=NULL;
		if ((*p).no==9999999)
		{
			break;
		}
	}
	fin.close();

	//杈撳嚭
	for (p=head;p!=(*q).next;)
	{
		cout << (*p).no << " " << (*p).name << " " << (*p).score << endl;
		p=(*p).next;
	}

	//閲婃斁
	for(;p;)
	{
		q=(*p).next;
		delete p;
		p=q;
	}

	//system("PAUSE"); //濡傛灉鏄疌++浣滀笟灏辨敞閲婃帀
	return 0;
}
