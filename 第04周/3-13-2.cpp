#include <iostream>

using namespace std;

int main()
{
    
    double x=0,y=0;
    cout << "请输入利润额（正数）：";
    cin >> x;
    
	bool flag=true;
	if (x<0)
	{
		flag=false;
	}

    int i=0;
    if ((x>=0)&&(x<=100000)) i=1;
    else if ((x>100000)&&(x<=200000)) i=2;
         else if ((x>200000)&&(x<=400000)) i=3;
              else if ((x>400000)&&(x<=600000)) i=4;
                   else  if ((x>600000)&&(x<=1000000)) i=5;
                         else i=6;

    switch (i)
    {
           case 6:y=0.1*100000+0.075*100000+0.05*200000+0.03*200000+0.015*400000+0.01*(x-1000000);
                break;
           case 5:y=0.1*100000+0.075*100000+0.05*200000+0.03*200000+0.015*(x-600000);
                break;
           case 4:y=0.1*100000+0.075*100000+0.05*200000+0.03*(x-400000);
                break;
           case 3:y=0.1*100000+0.075*100000+0.05*(x-200000);
                break;
           case 2:y=0.1*100000+0.075*(x-100000);
                break;
           case 1:y=0.1*x;
                break;
    }
    
    if (flag)    
    {
		cout << "提成金额为：" << y << endl; 
    }
	else
	{
		cout << "输入数据不合法！" << endl;
	}
    
    return(0);
}
