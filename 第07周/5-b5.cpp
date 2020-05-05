#include <iostream>
using namespace std;

int day_feb(int y);
bool exist(int y,int m,int d);
int caculate(int y,int m,int d);

int main()
{
	int a[3]={0};
	int jieguo=0;
	cin >> a[0] >> a[1] >> a[2];

	if (jieguo=caculate(a[0],a[1],a[2]))
	{
		cout << jieguo << endl;
	}
	else
	{
		cout << "杈撳叆閿欒" << endl;
	}
	
	return 0;

}

int day_feb(int y)
{
	if (((y%4==0)&&(y%100!=0))||(y%400==0))
	{
		return 29;
	}
	else
	{
		return 28;
	}
}

bool exist(int y,int m,int d)
{	bool judge=false;
	switch (m)
	{
		case 12:((d>=1)&&(d<=31))?(judge=true):(judge=false);
			break;
		case 11:((d>=1)&&(d<=30))?(judge=true):(judge=false);
			break;
		case 10:((d>=1)&&(d<=31))?(judge=true):(judge=false);
			break;
		case 9:((d>=1)&&(d<=30))?(judge=true):(judge=false);
			break;
		case 8:((d>=1)&&(d<=31))?(judge=true):(judge=false);
			break;
		case 7:((d>=1)&&(d<=31))?(judge=true):(judge=false);
			break;
		case 6:((d>=1)&&(d<=30))?(judge=true):(judge=false);
			break;
		case 5:((d>=1)&&(d<=31))?(judge=true):(judge=false);
			break;
		case 4:((d>=1)&&(d<=30))?(judge=true):(judge=false);
			break;
		case 3:((d>=1)&&(d<=31))?(judge=true):(judge=false);
			break;
		case 2:((d>=1)&&(d<=day_feb(m)))?(judge=true):(judge=false);
			break;
		case 1:((d>=1)&&(d<=31))?(judge=true):(judge=false);
			break;
		default:judge=false;	
	}
	return judge;
}

int caculate(int y,int m,int d)
{
	int solve=0;
	if (exist(y,m,d))
	{
		int a[13]={0,31,day_feb(y),31,30,31,30,31,31,30,31,30,31};
		int i;
		for (i=1;i<=m-1;i++)
		{
			solve=solve+a[i];
		}
		solve=solve+d;
		return solve;
	}
	else
	{
		return 0;
	}
}
