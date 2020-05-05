#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	int num;
	int factor;
	int sum=0;
	
	for (num=2;num<=1000;num++)
	{
		for (factor=1;factor<=0.5*num+1;factor++)
		{
			if (num%factor==0)
			{
				sum=sum+factor;
			}
		}
		if (num==sum)
		{
			cout << setw(3) << num << ", it's factors are ";
			for (factor=1;factor<=0.5*num+1;factor++)
			{
				if (num%factor==0)
				{
					cout << factor << ",";
				}
			}
			cout << endl; 	
		}
		sum=0;
	}
	
	return 0;
}
