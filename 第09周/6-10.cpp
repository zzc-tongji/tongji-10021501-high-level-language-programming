#include <iostream>
#include <iomanip>
using namespace std;

void solve(int *p);
void display(int *p);
void compare(int *x1,int *x2);
void exchange(int *x1,int *x2);

int main()
{
	
	int a[5][5]={35,34,33,32,31,
				 30,29,28,27,26,
				 25,24,23,22,21,
				 20,19,18,17,16,
				 15,14,13,12,11};

	cout << "澶勭悊鍓嶏細" << endl;
	display(*a);

	solve(*a);

	cout << "澶勭悊鍚庯細" << endl;
	display(*a);

	return 0;
}

void solve(int *p)
{
	int counter,counter1;
	for (counter=0;counter<=24;counter++)
	{
		for (counter1=counter+1;counter1<=24;counter1++)
		{
			compare(p+counter,p+counter1);
		}
	}
	exchange(p+1,p+4);
	exchange(p+2,p+20);
	exchange(p+24,p+12);
	exchange(p+3,p+24);
}

void display(int *p)
{
	int counter;
	for (counter=0;counter<=24;counter++)
	{
		cout << setw(2) << *(p+counter) << " ";
		if ((counter+1)%5==0) 
		{
			cout << endl;
		}
	}
	cout << endl;
}

void compare(int *x1,int *x2)
{
	if (*x1>*x2)
	{
		exchange(x1,x2);
	}
}

void exchange(int *x1,int *x2)
{
	int *temp;
	int temp_value;
	temp=&temp_value;

	*temp=*x1;
	*x1=*x2;
	*x2=*temp;
}
