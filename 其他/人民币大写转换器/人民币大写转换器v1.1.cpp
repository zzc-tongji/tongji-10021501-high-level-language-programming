#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double i;

int main()
{
	double x;
	double x_integer;
	double x_decimal;
	double x_decimal_int__stored_double;
	double decimal_changed;

	long int x_decimal_int__stored_int;


	long int b10e002; //百分位
	long int b10e001; //十分位
	long int b10e00; //个位
	long int b10e01; //十位
	long int b10e02; //百位
	long int b10e03; //千位
	long int b10e04; //万位
	long int b10e05; //十万位
	long int b10e06; //百万位
	long int b10e07; //千万位
	long int b10e08; //亿位
	long int b10e09; //十亿位
	
	cout << "********************人民币大写转换器v1.1********************" << endl;
	cout << "请确保您输入的数值小于10亿（不含）且小数位数不超过2位（含）" << endl;
	cout << "请输入需要转换的数值（元）" << endl;
	cin >> x;
	
	//整数部分提取
	b10e09=long int( x/pow(10,9) );
	b10e08=long int( (x-b10e09*pow(10,9))/pow(10,8) );
	b10e07=long int( (x-b10e09*pow(10,9)-b10e08*pow(10,8))/pow(10,7) );
	b10e06=long int( (x-b10e09*pow(10,9)-b10e08*pow(10,8)-b10e07*pow(10,7))/pow(10,6) );
	b10e05=long int( (x-b10e09*pow(10,9)-b10e08*pow(10,8)-b10e07*pow(10,7)-b10e06*pow(10,6))/pow(10,5) );
	b10e04=long int( (x-b10e09*pow(10,9)-b10e08*pow(10,8)-b10e07*pow(10,7)-b10e06*pow(10,6)-b10e05*pow(10,5))/pow(10,4) );
	b10e03=long int( (x-b10e09*pow(10,9)-b10e08*pow(10,8)-b10e07*pow(10,7)-b10e06*pow(10,6)-b10e05*pow(10,5)-b10e04*pow(10,4))/pow(10,3) );
	b10e02=long int( (x-b10e09*pow(10,9)-b10e08*pow(10,8)-b10e07*pow(10,7)-b10e06*pow(10,6)-b10e05*pow(10,5)-b10e04*pow(10,4)-b10e03*pow(10,3))/pow(10,2) );
	b10e01=long int( (x-b10e09*pow(10,9)-b10e08*pow(10,8)-b10e07*pow(10,7)-b10e06*pow(10,6)-b10e05*pow(10,5)-b10e04*pow(10,4)-b10e03*pow(10,3)-b10e02*pow(10,2))/pow(10,1) );
	b10e00=long int( (x-b10e09*pow(10,9)-b10e08*pow(10,8)-b10e07*pow(10,7)-b10e06*pow(10,6)-b10e05*pow(10,5)-b10e04*pow(10,4)-b10e03*pow(10,3)-b10e02*pow(10,2)-b10e01*pow(10,1))/pow(10,0) );

	//小数部分整体提取，表示为2位整数的形式，存在double型变量中
	x_integer=b10e09*pow(10,9)+b10e08*pow(10,8)+b10e07*pow(10,7)+b10e06*pow(10,6)+b10e05*pow(10,5)+b10e04*pow(10,4)+b10e03*pow(10,3)+b10e02*pow(10,2)+b10e01*pow(10,1)+b10e00*pow(10,0);
	x_decimal=x-x_integer;
	x_decimal_int__stored_double=100*x_decimal;

	//数字处理
	decimal_changed=x_decimal_int__stored_double+0.5;

	//处理完的数字存在long int型变量中
	x_decimal_int__stored_int=long int(decimal_changed);
	
	//小数部分提取
	b10e001=x_decimal_int__stored_int/10;
	b10e002=x_decimal_int__stored_int%10;
	
	/* 测试用
	cout << b10e09 << b10e08 << b10e07 << b10e06 << b10e05  << b10e04 << b10e03 << b10e02 << b10e01 << b10e00 << "." << b10e001 << b10e002 << endl; //正确
	cout << endl; 
	*/

	long int b10eA=0,b10eB=0; //补充百亿位和千亿位，使亿级符合输入格式

	long int b3,b2,b1,b0;
	long int jiao,fen;

	//亿级处理
	
	b3=b10eB;
	b2=b10eA;
	b1=b10e09;
	b0=b10e08;

	if ((b3)&&(b2)&&(b1)&&(b0)) //不含零，1111，完成
	{
		switch (b3) //千
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "仟";

		switch (b2) //百
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "佰";
		
		switch (b1) //十
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "拾";

		switch (b0) //一
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
	}
	
	else if ((!b3)&&(b2)&&(b1)&&(b0)) //含1个零，0111，完成
	{
		//千
		
		switch (b2) //百
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "佰";
		
		switch (b1) //十
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "拾";

		switch (b0) //一
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
	}

	else if ((b3)&&(!b2)&&(b1)&&(b0)) //含1个零，1011，完成
	{
		switch (b3) //千
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "仟";

		cout << "零"; //百
		
		switch (b1) //十
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "拾";

		switch (b0) //一
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
	}
	
	else if ((b3)&&(b2)&&(!b1)&&(b0)) //含1个零，1101，完成
	{
		switch (b3) //千
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "仟";

		switch (b2) //百
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "佰";
		
		cout << "零"; //十

		switch (b0) //一
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
	}
	
	else if ((b3)&&(b2)&&(b1)&&(!b0)) //含1个零，1110，完成
	{
		switch (b3) //千
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "仟";

		switch (b2) //百
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "佰";
		
		switch (b1) //十
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "拾";

		//一
	}
	
	else if ((!b3)&&(!b2)&&(b1)&&(b0)) //含2个零，0011，完成
	{
		//千
		
		//百
		
		switch (b1) //十
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "拾";

		switch (b0) //一
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
	}

	else if ((!b3)&&(b2)&&(!b1)&&(b0)) //含2个零，0101，完成
	{
		//千

		switch (b2) //百
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "佰";
		
		cout << "零"; //十

		switch (b0) //一
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
	}
	
	else if ((!b3)&&(b2)&&(b1)&&(!b0)) //含2个零，0110，完成
	{
		//千

		switch (b2) //百
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "佰";
		
		switch (b1) //十
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "拾";

		//一
	}
	
	else if ((b3)&&(!b2)&&(!b1)&&(b0)) //含2个零，1001，完成
	{
		switch (b3) //千
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "仟";

		cout << "零"; //百
		
		
		//十

		switch (b0) //一
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
	}
	
	else if ((b3)&&(!b2)&&(b1)&&(!b0)) //含2个零，1010，完成
	{
		switch (b3) //千
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "仟";

		cout << "零"; //百
		
		switch (b1) //十
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "拾";

		//一
		
	}
	
	else if ((b3)&&(b2)&&(!b1)&&(!b0)) //含2个零，1100，完成
	{
		switch (b3) //千
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "仟";

		switch (b2) //百
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "佰";
		
		//十
		
		//一
	}
	
	else if ((b3)&&(!b2)&&(!b1)&&(!b0)) //含3个零，1000，完成
	{
		switch (b3) //千
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "仟";

		//百
		
		//十
		
		//一
	}
	
	else if ((!b3)&&(b2)&&(!b1)&&(!b0)) //含3个零，0100，完成
	{
		//千

		switch (b2) //百
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "佰";
		
		//十

		//一
	}
	
	else if ((!b3)&&(!b2)&&(b1)&&(!b0)) //含3个零，0010，完成
	{
		//千

		//百
		
		switch (b1) //十
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "拾";

		//一
	}

	else if ((!b3)&&(!b2)&&(!b1)&&(b0)) //含3个零，0001，完成
	{
		//千
		
		//百
		
		//十

		switch (b0) //一
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
	}
	
	else //含4个零，0000，完成
	{
		//千
		
		//百
		
		//十

		//一
	}
	
	//“亿”字输出判断
	
	if (b10e09+b10e08!=0)
	{
		cout << "亿";
	}

	//亿级与万级之间的补零判断

	if ((b10e09+b10e08!=0)&&(b10e07==0)&&((b10e07)||(b10e06)||(b10e05)||(b10e04)||(b10e03)||(b10e02)||(b10e01)||(b10e00)))
	{
		cout << "零";
	}

	//万级处理

	b3=b10e07;
	b2=b10e06;
	b1=b10e05;
	b0=b10e04;

	if ((b3)&&(b2)&&(b1)&&(b0)) //不含零，1111，完成
	{
		switch (b3) //千
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "仟";

		switch (b2) //百
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "佰";
		
		switch (b1) //十
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "拾";

		switch (b0) //一
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
	}
	
	else if ((!b3)&&(b2)&&(b1)&&(b0)) //含1个零，0111，完成
	{
		//千
		
		switch (b2) //百
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "佰";
		
		switch (b1) //十
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "拾";

		switch (b0) //一
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
	}

	else if ((b3)&&(!b2)&&(b1)&&(b0)) //含1个零，1011，完成
	{
		switch (b3) //千
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "仟";

		cout << "零"; //百
		
		switch (b1) //十
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "拾";

		switch (b0) //一
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
	}
	
	else if ((b3)&&(b2)&&(!b1)&&(b0)) //含1个零，1101，完成
	{
		switch (b3) //千
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "仟";

		switch (b2) //百
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "佰";
		
		cout << "零"; //十

		switch (b0) //一
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
	}
	
	else if ((b3)&&(b2)&&(b1)&&(!b0)) //含1个零，1110，完成
	{
		switch (b3) //千
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "仟";

		switch (b2) //百
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "佰";
		
		switch (b1) //十
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "拾";

		//一
	}
	
	else if ((!b3)&&(!b2)&&(b1)&&(b0)) //含2个零，0011，完成
	{
		//千
		
		//百
		
		switch (b1) //十
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "拾";

		switch (b0) //一
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
	}

	else if ((!b3)&&(b2)&&(!b1)&&(b0)) //含2个零，0101，完成
	{
		//千

		switch (b2) //百
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "佰";
		
		cout << "零"; //十

		switch (b0) //一
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
	}
	
	else if ((!b3)&&(b2)&&(b1)&&(!b0)) //含2个零，0110，完成
	{
		//千

		switch (b2) //百
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "佰";
		
		switch (b1) //十
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "拾";

		//一
	}
	
	else if ((b3)&&(!b2)&&(!b1)&&(b0)) //含2个零，1001，完成
	{
		switch (b3) //千
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "仟";

		cout << "零"; //百
		
		
		//十

		switch (b0) //一
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
	}
	
	else if ((b3)&&(!b2)&&(b1)&&(!b0)) //含2个零，1010，完成
	{
		switch (b3) //千
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "仟";

		cout << "零"; //百
		
		switch (b1) //十
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "拾";

		//一
		
	}
	
	else if ((b3)&&(b2)&&(!b1)&&(!b0)) //含2个零，1100，完成
	{
		switch (b3) //千
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "仟";

		switch (b2) //百
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "佰";
		
		//十
		
		//一
	}
	
	else if ((b3)&&(!b2)&&(!b1)&&(!b0)) //含3个零，1000，完成
	{
		switch (b3) //千
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "仟";

		//百
		
		//十
		
		//一
	}
	
	else if ((!b3)&&(b2)&&(!b1)&&(!b0)) //含3个零，0100，完成
	{
		//千

		switch (b2) //百
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "佰";
		
		//十

		//一
	}
	
	else if ((!b3)&&(!b2)&&(b1)&&(!b0)) //含3个零，0010，完成
	{
		//千

		//百
		
		switch (b1) //十
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "拾";

		//一
	}

	else if ((!b3)&&(!b2)&&(!b1)&&(b0)) //含3个零，0001，完成
	{
		//千
		
		//百
		
		//十

		switch (b0) //一
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
	}
	
	else //含4个零，0000，完成
	{
		//千
		
		//百
		
		//十

		//一
	}

	//“万”字输出判断
	
	if (b10e07+b10e06+b10e05+b10e04!=0)
	{
		cout << "万";
	}

	//万级与一级之间的补零判断

	if ((b10e07+b10e06+b10e05+b10e04!=0)&&(b10e03==0)&&((b10e03)||(b10e02)||(b10e01)||(b10e00)))
	{
		cout << "零";
	}

	//一级处理

	b3=b10e03;
	b2=b10e02;
	b1=b10e01;
	b0=b10e00;

	if ((b3)&&(b2)&&(b1)&&(b0)) //不含零，1111，完成
	{
		switch (b3) //千
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "仟";

		switch (b2) //百
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "佰";
		
		switch (b1) //十
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "拾";

		switch (b0) //一
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
	}
	
	else if ((!b3)&&(b2)&&(b1)&&(b0)) //含1个零，0111，完成
	{
		//千
		
		switch (b2) //百
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "佰";
		
		switch (b1) //十
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "拾";

		switch (b0) //一
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
	}

	else if ((b3)&&(!b2)&&(b1)&&(b0)) //含1个零，1011，完成
	{
		switch (b3) //千
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "仟";

		cout << "零"; //百
		
		switch (b1) //十
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "拾";

		switch (b0) //一
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
	}
	
	else if ((b3)&&(b2)&&(!b1)&&(b0)) //含1个零，1101，完成
	{
		switch (b3) //千
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "仟";

		switch (b2) //百
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "佰";
		
		cout << "零"; //十

		switch (b0) //一
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
	}
	
	else if ((b3)&&(b2)&&(b1)&&(!b0)) //含1个零，1110，完成
	{
		switch (b3) //千
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "仟";

		switch (b2) //百
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "佰";
		
		switch (b1) //十
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "拾";

		//一
	}
	
	else if ((!b3)&&(!b2)&&(b1)&&(b0)) //含2个零，0011，完成
	{
		//千
		
		//百
		
		switch (b1) //十
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "拾";

		switch (b0) //一
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
	}

	else if ((!b3)&&(b2)&&(!b1)&&(b0)) //含2个零，0101，完成
	{
		//千

		switch (b2) //百
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "佰";
		
		cout << "零"; //十

		switch (b0) //一
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
	}
	
	else if ((!b3)&&(b2)&&(b1)&&(!b0)) //含2个零，0110，完成
	{
		//千

		switch (b2) //百
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "佰";
		
		switch (b1) //十
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "拾";

		//一
	}
	
	else if ((b3)&&(!b2)&&(!b1)&&(b0)) //含2个零，1001，完成
	{
		switch (b3) //千
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "仟";

		cout << "零"; //百
		
		
		//十

		switch (b0) //一
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
	}
	
	else if ((b3)&&(!b2)&&(b1)&&(!b0)) //含2个零，1010，完成
	{
		switch (b3) //千
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "仟";

		cout << "零"; //百
		
		switch (b1) //十
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "拾";

		//一
		
	}
	
	else if ((b3)&&(b2)&&(!b1)&&(!b0)) //含2个零，1100，完成
	{
		switch (b3) //千
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "仟";

		switch (b2) //百
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "佰";
		
		//十
		
		//一
	}
	
	else if ((b3)&&(!b2)&&(!b1)&&(!b0)) //含3个零，1000，完成
	{
		switch (b3) //千
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "仟";

		//百
		
		//十
		
		//一
	}
	
	else if ((!b3)&&(b2)&&(!b1)&&(!b0)) //含3个零，0100，完成
	{
		//千

		switch (b2) //百
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "佰";
		
		//十

		//一
	}
	
	else if ((!b3)&&(!b2)&&(b1)&&(!b0)) //含3个零，0010，完成
	{
		//千

		//百
		
		switch (b1) //十
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "拾";

		//一
	}

	else if ((!b3)&&(!b2)&&(!b1)&&(b0)) //含3个零，0001，完成
	{
		//千
		
		//百
		
		//十

		switch (b0) //一
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
	}
	
	else //含4个零，0000，完成
	{
		//千
		
		//百
		
		//十

		//一
	}
	
	//“圆”字输出判断
	
	if (b10e09+b10e08+b10e07+b10e06+b10e05+b10e04+b10e03+b10e02+b10e01+b10e00!=0)
	{
		cout << "圆";
	}

	//角分位处理

	jiao=b10e001;
	fen=b10e002;

	if ((jiao)&&(fen)) //不含零，11，完成
	{
		switch (jiao) //角
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "角";

		switch (fen) //分
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "分" << endl;
	}
	
	else if ((jiao)&&(!fen)) //含1个零，10，完成
	{
		switch (jiao) //角
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "角";

		cout << endl; //分
	}
	
	else if ((!jiao)&&(fen)) //含1个零，01
	{
		if (b10e09+b10e08+b10e07+b10e06+b10e05+b10e04+b10e03+b10e02+b10e01+b10e00==0)
		{;}
		else
		{
			cout << "零"; //角
		}

		switch (fen) //分
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "分" << endl;;
	}
	
	else //含2个零，00，完成
	{
		if (b10e09+b10e08+b10e07+b10e06+b10e05+b10e04+b10e03+b10e02+b10e01+b10e00+b10e001+b10e002==0)
		{
			cout << "零圆整" << endl;
		}
		else
		{
			cout << "整" << endl;
		}

		//角

		//分
	}

	cout << "************************************************************" << endl;

	return 0;
}
