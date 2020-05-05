#include <iostream>
using namespace std;

int main()
{
	double x0=0,x1=1,half;
	double f_x0,f_x1,f_half;
	bool sign_fx_0=0,sign_fx_1=0,sign_f_half=0;
	double solve;

	for (;x1-x0>=0.000001;)
	{
		f_x0=2*(x0*x0*x0)-9*(x0*x0)+12*(x0)-3;
		f_x1=2*(x1*x1*x1)-9*(x1*x1)+12*(x1)-3;
		
		half=(x0+x1)/2;
		f_half=2*(half*half*half)-9*(half*half)+12*(half)-3;

		if (f_half==0)
		{
			solve=f_half;
			break;
		}

		(f_x0>0)?(sign_fx_0=1):(sign_fx_0=0);
		(f_x1>0)?(sign_fx_1=1):(sign_fx_1=0);
		(f_half>0)?(sign_f_half=1):(sign_f_half=0);

		if (sign_fx_0!=sign_f_half)
		{
			x1=half;
		}
		else
		{
			x0=half;
		}
		
		solve=half;	
	}
	
	cout << "方程2x^3-9x^2+12x-3=0在[0,1]上的根为 " << solve << endl;
	//cout << "标准值= 0.322349" << endl;

	return 0;
}
