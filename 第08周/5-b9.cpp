#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
using namespace std;

char chistr[]="零\0壹\0贰\0叁\0肆\0伍\0陆\0柒\0捌\0玖";
char chistr_other[]="拾\0佰\0仟\0万\0亿\0圆\0角\0分\0整\0零圆整";
char result[256]={'\0'};
int location=0;   //输出位置
bool flag1=false; //用于角分位处理函数，为true当且仅当整数部位全部为0
bool flag2=false; //用于角分位处理函数，为true当且仅当所有数位全部为0

void handle_4_bit(long int b3,long int b2,long int b1,long int b0); //四位处理函数
void handle_jiaofen_bit(long int jiao,long int fen);				//角分位处理函数
void output_prepare(long int x,int location);						//数字输出准备函数
void output_prepare_other(long int x,int location);					//其他字符输出准备函数
void move_location(int m);


int main()
{
	/*测试用 
	while(1){
	*/
	
	double x;
	double x_integer;
	double x_decimal;
	double x_decimal_int__stored_double;
	double decimal_changed;
	long int x_decimal_int__stored_int;
	long int b10e002; //百分位
	long int b10e001; //十分位
	long int b10e00;  //个位
	long int b10e01;  //十位
	long int b10e02;  //百位
	long int b10e03;  //千位
	long int b10e04;  //万位
	long int b10e05;  //十万位
	long int b10e06;  //百万位
	long int b10e07;  //千万位
	long int b10e08;  //亿位
	long int b10e09;  //十亿位
	
	cout << "********************人民币大写转换器v1.3********************" << endl;
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
	//补充百亿位和千亿位，使亿级符合输入格式
	long int b10eA=0,b10eB=0; 

	/*************************************************************************************************************************/
	//亿级处理
	handle_4_bit(b10eB,b10eA,b10e09,b10e08);
	//“亿”字输出判断
	if (b10e09+b10e08!=0)
	{
		output_prepare_other(5,location);
	}
	//亿级与万级之间的补零判断
	if ((b10e09+b10e08!=0)&&(b10e07==0)&&((b10e07)||(b10e06)||(b10e05)||(b10e04)||(b10e03)||(b10e02)||(b10e01)||(b10e00)))
	{
		output_prepare(0,location);
	}
	//万级处理
	handle_4_bit(b10e07,b10e06,b10e05,b10e04);
	//“万”字输出判断
	if (b10e07+b10e06+b10e05+b10e04!=0)
	{
		output_prepare_other(4,location);
	}
	//万级与一级之间的补零判断
	if ((b10e07+b10e06+b10e05+b10e04!=0)&&(b10e03==0)&&((b10e03)||(b10e02)||(b10e01)||(b10e00)))
	{
		output_prepare(0,location);
	}
	//一级处理
	handle_4_bit(b10e03,b10e02,b10e01,b10e00);
	//“圆”字输出判断
	if (b10e09+b10e08+b10e07+b10e06+b10e05+b10e04+b10e03+b10e02+b10e01+b10e00!=0)
	{
		output_prepare_other(6,location);
	}
	//角分位处理函数_标志位处理
	flag1=((b10e09+b10e08+b10e07+b10e06+b10e05+b10e04+b10e03+b10e02+b10e01+b10e00==0)?true:false);
	flag2=((b10e09+b10e08+b10e07+b10e06+b10e05+b10e04+b10e03+b10e02+b10e01+b10e00+b10e001+b10e002==0)?true:false);
	//角分位处理
	handle_jiaofen_bit(b10e001,b10e002);
	/*************************************************************************************************************************/

	//输出
	cout << result << endl;
	cout << "************************************************************" << endl;

	/*测试用
	cout << endl;
	int i;
	for (i=0;i<=255;i++)
	{
		result[i]='\0';
	}
	location=0;
	}
	*/

	return 0;
}


void handle_4_bit(long int b3,long int b2,long int b1,long int b0) //四位处理函数
{
	if ((b3)&&(b2)&&(b1)&&(b0)) //不含零，1111，完成
	{
		output_prepare(b3,location);
		output_prepare_other(3,location); //千
		output_prepare(b2,location);
		output_prepare_other(2,location); //百
		output_prepare(b1,location);
		output_prepare_other(1,location); //十
		output_prepare(b0,location); //一
	}	
	else if ((!b3)&&(b2)&&(b1)&&(b0)) //含1个零，0111，完成
	{
		//千
		output_prepare(b2,location);
		output_prepare_other(2,location); //百
		output_prepare(b1,location);
		output_prepare_other(1,location); //十
		output_prepare(b0,location); //一
	}
	else if ((b3)&&(!b2)&&(b1)&&(b0)) //含1个零，1011，完成
	{
		output_prepare(b3,location);
		output_prepare_other(3,location); //千
		output_prepare(0,location); //百
		output_prepare(b1,location);
		output_prepare_other(1,location); //十
		output_prepare(b0,location); //一
	}
	else if ((b3)&&(b2)&&(!b1)&&(b0)) //含1个零，1101，完成
	{
		output_prepare(b3,location);	
		output_prepare_other(3,location); //千
		output_prepare(b2,location);
		output_prepare_other(2,location); //百
		output_prepare(0,location); //十
		output_prepare(b0,location); //一
	}
	else if ((b3)&&(b2)&&(b1)&&(!b0)) //含1个零，1110，完成
	{
		output_prepare(b3,location);
		output_prepare_other(3,location); //千
		output_prepare(b2,location);
		output_prepare_other(2,location); //百
		output_prepare(b1,location);
		output_prepare_other(1,location); //十
		//一
	}
	else if ((!b3)&&(!b2)&&(b1)&&(b0)) //含2个零，0011，完成
	{
		//千	
		//百
		output_prepare(b1,location);
		output_prepare_other(1,location); //十
		output_prepare(b0,location); //一
		
	}
	else if ((!b3)&&(b2)&&(!b1)&&(b0)) //含2个零，0101，完成
	{
		//千
		output_prepare(b2,location);
		output_prepare_other(2,location); //百
		output_prepare(0,location); //十
		output_prepare(b0,location); //一
	}
	else if ((!b3)&&(b2)&&(b1)&&(!b0)) //含2个零，0110，完成
	{
		//千
		output_prepare(b2,location);
		output_prepare_other(2,location); //百
		output_prepare(b1,location);
		output_prepare_other(1,location); //十
		//一
	}
	else if ((b3)&&(!b2)&&(!b1)&&(b0)) //含2个零，1001，完成
	{
		output_prepare(b3,location);
		output_prepare_other(3,location); //千
		output_prepare(0,location); //百
		//十
		output_prepare(b0,location); //一	
	}
	else if ((b3)&&(!b2)&&(b1)&&(!b0)) //含2个零，1010，完成
	{
		output_prepare(b3,location);	
		output_prepare_other(3,location); //千
		output_prepare(0,location); //百
		output_prepare(b1,location);
		output_prepare_other(1,location); //十
		//一	
	}
	else if ((b3)&&(b2)&&(!b1)&&(!b0)) //含2个零，1100，完成
	{
		output_prepare(b3,location);
		output_prepare_other(3,location); //千
		output_prepare(b2,location);
		output_prepare_other(2,location); //百
		//十
		//一
	}
	else if ((b3)&&(!b2)&&(!b1)&&(!b0)) //含3个零，1000，完成
	{
		output_prepare(b3,location);
		output_prepare_other(3,location); //千
		//百
		//十
		//一
	}
	else if ((!b3)&&(b2)&&(!b1)&&(!b0)) //含3个零，0100，完成
	{
		//千
		output_prepare(b2,location);
		output_prepare_other(2,location); //百
		//十
		//一
	}
	else if ((!b3)&&(!b2)&&(b1)&&(!b0)) //含3个零，0010，完成
	{
		//千
		//百
		output_prepare(b1,location);
		output_prepare_other(1,location); //十
		//一
	}
	else if ((!b3)&&(!b2)&&(!b1)&&(b0)) //含3个零，0001，完成
	{
		//千
		//百
		//十
		output_prepare(b0,location); //一
		
	}
	else //含4个零，0000，完成
	{
		//千
		//百
		//十
		//一
	}
}


void handle_jiaofen_bit(long int jiao,long int fen)
{
	if ((jiao)&&(fen)) //不含零，11，完成
	{
		output_prepare(jiao,location);
		output_prepare_other(7,location); //角
		output_prepare(fen,location);
		output_prepare_other(8,location); //分
	}
	else if ((jiao)&&(!fen)) //含1个零，10，完成
	{
		output_prepare(jiao,location);
		output_prepare_other(7,location); //角
		//分
	}
	else if ((!jiao)&&(fen)) //含1个零，01
	{
		if (!flag1)
		{
			output_prepare(0,location); //角
		}
		output_prepare(fen,location);
		output_prepare_other(8,location); //分
	}
	else //含2个零，00，完成
	{
		if (flag2)
		{
			output_prepare_other(10,location);
		}
		else
		{
			output_prepare_other(9,location);
		}
		//角
		//分
	}
}


void output_prepare(long int x,int location)
{
		switch (x) //char chistr[]="零\0壹\0贰\0叁\0肆\0伍\0陆\0柒\0捌\0玖";
		{
			case 0:
				strncpy(&result[location],chistr,2);
				move_location(1);
				break;
			case 1:
				strncpy(&result[location],&chistr[3],2);
				move_location(1);
				break;
			case 2:
				strncpy(&result[location],&chistr[6],2);
				move_location(1);
				break;
			case 3:
				strncpy(&result[location],&chistr[9],2);
				move_location(1);
				break;
			case 4:
				strncpy(&result[location],&chistr[12],2);
				move_location(1);
				break;
			case 5:
				strncpy(&result[location],&chistr[15],2);
				move_location(1);
				break;
			case 6:
				strncpy(&result[location],&chistr[18],2);
				move_location(1);
				break;
			case 7:
				strncpy(&result[location],&chistr[21],2);
				move_location(1);
				break;
			case 8:
				strncpy(&result[location],&chistr[24],2);
				move_location(1);
				break;
			case 9:
				strncpy(&result[location],&chistr[27],2);
				move_location(1);
				break;
			default:;
		}
}


void output_prepare_other(long int x,int location)
{
		switch (x)  //char chistr_other[]="拾\0佰\0仟\0万\0亿\0圆\0角\0分\0整\0零圆整";
		{
			case 1: //拾
				strncpy(&result[location],chistr_other,2);
				move_location(1);
				break;
			case 2: //佰
				strncpy(&result[location],&chistr_other[3],2);
				move_location(1);
				break;
			case 3: //仟
				strncpy(&result[location],&chistr_other[6],2);
				move_location(1);
				break;
			case 4: //万
				strncpy(&result[location],&chistr_other[9],2);
				move_location(1);
				break;
			case 5: //亿
				strncpy(&result[location],&chistr_other[12],2);
				move_location(1);
				break;
			case 6: //圆
				strncpy(&result[location],&chistr_other[15],2);
				move_location(1);
				break;
			case 7: //角
				strncpy(&result[location],&chistr_other[18],2);
				move_location(1);
				break;
			case 8: //分
				strncpy(&result[location],&chistr_other[21],2);
				move_location(1);
				break;
			case 9: //整
				strncpy(&result[location],&chistr_other[24],2);
				move_location(1);
				break;
			case 10: //零圆整
				strncpy(&result[location],&chistr_other[27],6);
				move_location(3);
				break;
			default:;
		}
}


void move_location(int m)
{
	location=location+2*m;
}
