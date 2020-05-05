#include <iostream>
#include <iomanip>   //格式化输出必须包含此头文件
using namespace std;

int main()
{
	double a=123.456789012345;
	int    b=123456;
	int    i;

	for (i=0; i<2; i++, a=-a) {
		cout << "======================" << endl;
		cout << "=" << (a>=0 ? "正":"负") << "浮点数的格式化输出=" << endl;
		cout << "======================" << endl;

		cout << "C++缺省输出" << endl;
		cout << a << endl;
		printf("======================\n");
		printf("=%s浮点数的格式化输出=\n",(a>=0 ? "正":"负"));
		printf("======================\n");
		printf("C++缺省输出\n");
		printf("%.3f\n",a);
		getchar();//到此处输出按下0,10次回车的结果(完成)
	
		cout << "9位有效数字" << endl;
		cout << setprecision(9) << a << endl;
		printf("9位有效数字\n");
		printf("%.6f\n",a);
		getchar();//到此处输出按下1,11次回车的结果(完成)

		cout << "小数点后6位" << endl;
		cout << setiosflags(ios::fixed) << setprecision(6) << a << endl;
		printf("小数点后6位\n");
		printf("%.6f\n",a);
		getchar();//到此处输出按下2,12次回车的结果(完成)

		cout << "小数点后8位" << endl;
		cout << setiosflags(ios::fixed) << setprecision(8) << a << endl;
		printf("小数点后8位\n");
		printf("%.8f\n",a);
		getchar();//到此处输出按下3,13次回车的结果(完成)

		cout << "总宽度20，小数点后6位，右对齐" << endl;
		cout << setw(20) << setiosflags(ios::fixed) << setprecision(6) << a << endl;
		printf("总宽度20，小数点后6位，右对齐\n");
		printf("%20.6f\n",a);
		getchar();//到此处输出按下4,14次回车的结果(完成)

		cout << "总宽度20，小数点后8位，左对齐" << endl;
		cout << setw(20) << setiosflags(ios::fixed) << setprecision(8) << setiosflags(ios::left) << a << '*' << endl; //左对齐,最后加*是为了看清楚几个空格
		printf("总宽度20，小数点后8位，左对齐\n");
		printf("%-20.8f*\n",a);
		getchar();//到此处输出按下5,15次回车的结果(完成)

		cout << resetiosflags(ios::fixed) << resetiosflags(ios::left) << setprecision(6); //此句用于消除ios::fixed、ios::left的设置并恢复6位小数

		cout << "科学计数法-小数点后6位" << endl;
		cout << setiosflags(ios::scientific) << a << endl;
		printf("科学计数法-小数点后6位\n");
		printf("%.6e\n",a);
		getchar();//到此处输出按下6,16次回车的结果(完成)

		cout << "科学计数法-小数点后4位" << endl;
		cout << setiosflags(ios::scientific) << setprecision(4) << a << endl;
		printf("科学计数法-小数点后4位\n");
		printf("%.4e\n",a);
		getchar();//到此处输出按下7,17次回车的结果(完成)

		cout << "科学计数法-总宽度20，小数点后6位，右对齐" << endl;
		cout << setw(20) << setiosflags(ios::scientific) << setprecision(6) << a << endl;
		printf("科学计数法-总宽度20，小数点后6位，右对齐\n");
		printf("%20.6e\n",a);
		getchar();//到此处输出按下8,18次回车的结果(完成)

		cout << "科学计数法-总宽度20，小数点后4位，左对齐" << endl;
		cout << setw(20) << setiosflags(ios::scientific) << setprecision(4) << setiosflags(ios::left) << a << '*' << endl; //左对齐,最后加*是为了看清楚几个空格
		printf("科学计数法-总宽度20，小数点后4位，左对齐\n");
		printf("%-20.4e*\n",a);
		getchar();//到此处输出按下9,19次回车的结果(完成)

		cout << resetiosflags(ios::scientific) << resetiosflags(ios::left) << setprecision(6); //此句用于消除ios::fixed、ios::left的设置并恢复6位小数

		cout << endl << endl;
		}

	for (i=0; i<2; i++, b=-b) {
		cout << "======================" << endl;
		cout << "=" << (b>=0 ? "正":"负") << "整数的格式化输出=" << endl;
		cout << "======================" << endl;

		cout << "缺省输出" << endl;
		cout << b << endl;
		printf("======================\n");
		printf("=%s整数的格式化输出=\n",(b>=0 ? "正":"负"));
		printf("======================\n");
		printf("缺省输出\n");
		printf("%d\n",b);
		getchar();//到此处输出按下20,31次回车的结果(完成)
    
		cout << "缺省输出-总宽度20，右对齐" << endl;
		cout << setw(20) << b << endl;
		printf("缺省输出-总宽度20，右对齐\n");
		printf("%20d\n",b);
		getchar();//到此处输出按下21,32次回车的结果(完成)

		cout << "缺省输出-总宽度20，左对齐" << endl;
		cout << setw(20) << setiosflags(ios::left) << b << '*' << endl; //左对齐,最后加*是为了看清楚几个空格
		printf("缺省输出-总宽度20，左对齐\n");
		printf("%-20d*\n",b);
		getchar();//到此处输出按下22,33次回车的结果(完成)

		cout << resetiosflags(ios::left); //消除左对齐的设置

		cout << "八进制输出" << endl;
		cout << oct << b << endl;
		printf("八进制输出\n");
		printf("%o\n",b);
		getchar();//到此处输出按下23,34次回车的结果(完成)
    
		cout << "八进制-总宽度20，右对齐" << endl;
		cout << setw(20) << b << endl;
		printf("八进制-总宽度20，右对齐\n");
		printf("%20o\n",b);
		getchar();//到此处输出按下24,35次回车的结果(完成)

		cout << "八进制-总宽度20，左对齐" << endl;
		cout << setw(20) << setiosflags(ios::left) << b << '*' << endl; //左对齐,最后加*是为了看清楚几个空格
		printf("八进制-总宽度20，左对齐\n");
		printf("%-20o*\n",b);
		getchar();//到此处输出按下25,36次回车的结果(完成)

		cout << resetiosflags(ios::left); //消除左对齐的设置

		cout << "十六进制输出(a-f)" << endl;
		cout << hex << b << endl;
		printf("十六进制输出(a-f)\n");
		printf("%x\n",b);
		getchar();//到此处输出按下26,37次回车的结果(完成)
    
		cout << "十六进制(a-f)-总宽度20，右对齐" << endl;
		cout << setw(20) << b << endl;
		printf("十六进制(a-f)-总宽度20，右对齐\n");
		printf("%20x\n",b);
		getchar();//到此处输出按下27,38次回车的结果(完成)

		cout << "十六进制输出(A-F)" << endl;
		cout << setiosflags(ios::uppercase) << b << endl;
		printf("十六进制输出(A-F)\n");
		printf("%X\n",b);
		getchar();//到此处输出按下28,39次回车的结果(完成)
    
		cout << "十六进制-总宽度20，左对齐" << endl;
		cout << setw(20) << setiosflags(ios::left) << b << '*' << endl; //左对齐,最后加*是为了看清楚几个空格
		printf("十六进制-总宽度20，左对齐\n");
		printf("%-20X*\n",b);
		getchar();//到此处输出按下29,40次回车的结果(完成)

		cout << resetiosflags(ios::uppercase) << resetiosflags(ios::left); //消除大写及左对齐的影响

	    cout << dec;     //恢复10进制
		cout << "缺省-带符号位" << endl;
		cout << setiosflags(ios::showpos) << b << endl;
		printf("缺省-带符号位\n");
		printf("%+d\n",b);
		getchar();//到此处输出按下30,41次回车的结果(完成)

		cout << endl << endl;
		}
		
    return 0;
}
