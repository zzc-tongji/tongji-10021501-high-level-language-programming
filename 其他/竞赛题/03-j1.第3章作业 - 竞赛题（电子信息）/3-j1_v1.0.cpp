 #include <iostream>  
 #include <iomanip>  
 #include <windows.h> //取系统时间  
 #include <time.h>  
 using namespace std;  
   
 int main()  
  {  
     LARGE_INTEGER tick, fc_begin, fc_end;  
     QueryPerformanceFrequency(&tick);//获得时钟频率  
     QueryPerformanceCounter(&fc_begin);//获得初始硬件定时器计数  
   
    int a2,a1,a0,a;
	int b2,b1,b0,b;
	int c2,c1,c0,c;
	int counter=0;
	for (a2=1;a2<=5;a2++)
	{
		for(a1=1;a1<=9;a1++)
		{
			if (a1==a2) continue;
			else ;
			
			for(a0=1;a0<=9;a0++)
			{
				if (a0==a2) continue;
				else if (a0==a1) continue;
				else ;
				
				for(b2=4;b2<=8;b2++)
				{
					if (b2==a2) continue;
					else if (b2==a1) continue;
					else if (b2==a0) continue;
					else ;
					
					for(b1=1;b1<=9;b1++)
					{
						if (b1==a2) continue;
						else if (b1==a1) continue;
						else if (b1==a0) continue;
						else if (b1==b2) continue;
						else ;
						
						for(b0=1;b0<=9;b0++)
						{
							if (b0==a2) continue;
							else if (b0==a1) continue;
							else if (b0==a0) continue;
							else if (b0==b2) continue;
							else if (b0==b1) continue;
							else ;
							
							a=100*a2+10*a1+a0;
							b=100*b2+10*b1+b0;
							if(a>b) continue;
							
							for(c2=7;c2<=9;c2++)
							{
								if (c2==a2) continue;
								else if (c2==a1) continue;
								else if (c2==a0) continue;
								else if (c2==b2) continue;
								else if (c2==b1) continue;
								else if (c2==b0) continue;
								else ;
								
								for(c1=1;c1<=9;c1++)
								{
									if (c1==a2) continue;
									else if (c1==a1) continue;
									else if (c1==a0) continue;
									else if (c1==b2) continue;
									else if (c1==b1) continue;
									else if (c1==b0) continue;
									else if (c1==c2) continue;
									else ;
									
									for(c0=1;c0<=9;c0++)
									{	
										if (c0==a2) continue;
										else if (c0==a1) continue;
										else if (c0==a0) continue;
										else if (c0==b2) continue;
										else if (c0==b1) continue;
										else if (c0==b0) continue;
										else if (c0==c2) continue;
										else if (c0==c1) continue;
										else ;
									
										a=100*a2+10*a1+a0;
										b=100*b2+10*b1+b0;
										c=100*c2+10*c1+c0;
											
										if (b<c)
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
	
	cout << "总数：" << counter << endl;  
   
     QueryPerformanceCounter(&fc_end);//获得终止硬件定时器计数  
   
     cout << setiosflags(ios::fixed) << setprecision(3);  
     cout << "时钟频率：" << double(tick.QuadPart)/1024/1024 << "GHz" << endl;  
     cout << setprecision(0);  
     cout << "时钟计数  ：" << double(fc_end.QuadPart - fc_begin.QuadPart) << endl;  
     cout << setprecision(6);  
     cout << double(fc_end.QuadPart - fc_begin.QuadPart)/tick.QuadPart << "秒" <<endl;  
   
     getchar();  
     return 0;  
 }
