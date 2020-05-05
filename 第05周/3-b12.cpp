#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	//int t_s,t_e;
	//t_s=GetTickCount();
	int a2,a1,a0,a;
	int b2,b1,b0,b;
	int c2,c1,c0,c;
	bool judge=true;
	int counter=0;
	for (a2=1;a2<=9;a2++)
	{
		for(a1=1;a1<=9;a1++)
		{
			for(a0=1;a0<=9;a0++)
			{
				for(b2=1;b2<=9;b2++)
				{
					for(b1=1;b1<=9;b1++)
					{
						for(b0=1;b0<=9;b0++)
						{
							for(c2=1;c2<=9;c2++)
							{
								for(c1=1;c1<=9;c1++)
								{
									for(c0=1;c0<=9;c0++)
									{
										if (a0==a1) judge=false;
										else if (a0==a2) judge=false;
										else if (a0==b0) judge=false;
										else if (a0==b1) judge=false;
										else if (a0==b2) judge=false;
										else if (a0==c0) judge=false;
										else if (a0==c1) judge=false;
										else if (a0==c2) judge=false;
										else if (a1==a2) judge=false;
										else if (a1==b0) judge=false;
										else if (a1==b1) judge=false;
										else if (a1==b2) judge=false;
										else if (a1==c0) judge=false;
										else if (a1==c1) judge=false;
										else if (a1==c2) judge=false;
										else if (a2==b0) judge=false;
										else if (a2==b1) judge=false;
										else if (a2==b2) judge=false;
										else if (a2==c0) judge=false;
										else if (a2==c1) judge=false;
										else if (a2==c2) judge=false;
										else if (b0==b1) judge=false;
										else if (b0==b2) judge=false;
										else if (b0==c0) judge=false;
										else if (b0==c1) judge=false;
										else if (b0==c2) judge=false;
										else if (b1==b2) judge=false;
										else if (b1==c0) judge=false;
										else if (b1==c1) judge=false;
										else if (b1==c2) judge=false;
										else if (b2==c0) judge=false;
										else if (b2==c1) judge=false;
										else if (b2==c2) judge=false;
										else if (c0==c1) judge=false;
										else if (c0==c2) judge=false;
										else if (c1==c2) judge=false;
										else judge=true;
										
										if (judge)
										{
											a=100*a2+10*a1+a0;
											b=100*b2+10*b1+b0;
											c=100*c2+10*c1+c0;
											
											if ((a<b)&&(b<c))
											{
												if (a+b+c==1953)
												{
													cout << a << "+" << b << "+" << c << "=1953" << endl;
													counter=counter+1;
												}
												else
												{
													;
												}
											}
											else
											{
												continue;
											}
										}			
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout << "总数：" << counter << endl; 
	//t_e=GetTickCount();
	//cout << (t_e-t_s) << "ms" << endl;
	return 0;
}
