/* 学号 班级 姓名 */
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
		printf("xxxx\n");
		getchar();

		cout << "9位有效数字" << endl;
		cout << setprecision(9) << a << endl;
		printf("xxxx\n");
		getchar();

		cout << "小数点后6位" << endl;
		cout << setiosflags(ios::fixed) << setprecision(6) << a << endl;
		printf("xxxx\n");
		getchar();

		cout << "小数点后8位" << endl;
		cout << setiosflags(ios::fixed) << setprecision(8) << a << endl;
		printf("xxxx\n");
		getchar();

		cout << "总宽度20，小数点后6位，右对齐" << endl;
		cout << setw(20) << setiosflags(ios::fixed) << setprecision(6) << a << endl;
		printf("xxxx\n");
		getchar();

		cout << "总宽度20，小数点后8位，左对齐" << endl;
		cout << setw(20) << setiosflags(ios::fixed) << setprecision(8) << setiosflags(ios::left) << a << '*' << endl; //左对齐,最后加*是为了看清楚几个空格
		printf("xxxx\n");
		getchar();

		cout << resetiosflags(ios::fixed) << resetiosflags(ios::left) << setprecision(6); //此句用于消除ios::fixed、ios::left的设置并恢复6位小数

		cout << "科学计数法-小数点后6位" << endl;
		cout << setiosflags(ios::scientific) << a << endl;
		printf("xxxx\n");
		getchar();

		cout << "科学计数法-小数点后4位" << endl;
		cout << setiosflags(ios::scientific) << setprecision(4) << a << endl;
		printf("xxxx\n");
		getchar();

		cout << "科学计数法-总宽度20，小数点后6位，右对齐" << endl;
		cout << setw(20) << setiosflags(ios::scientific) << setprecision(6) << a << endl;
		printf("xxxx\n");
		getchar();

		cout << "科学计数法-总宽度20，小数点后4位，左对齐" << endl;
		cout << setw(20) << setiosflags(ios::scientific) << setprecision(4) << setiosflags(ios::left) << a << '*' << endl; //左对齐,最后加*是为了看清楚几个空格
		printf("xxxx\n");
		getchar();

		cout << resetiosflags(ios::scientific) << resetiosflags(ios::left) << setprecision(6); //此句用于消除ios::fixed、ios::left的设置并恢复6位小数

		cout << endl << endl;
		}

	for (i=0; i<2; i++, b=-b) {
		cout << "======================" << endl;
		cout << "=" << (b>=0 ? "正":"负") << "整数的格式化输出=" << endl;
		cout << "======================" << endl;

		cout << "缺省输出" << endl;
		cout << b << endl;
		printf("xxxx\n");
		getchar();
    
		cout << "缺省输出-总宽度20，右对齐" << endl;
		cout << setw(20) << b << endl;
		printf("xxxx\n");
		getchar();

		cout << "缺省输出-总宽度20，左对齐" << endl;
		cout << setw(20) << setiosflags(ios::left) << b << '*' << endl; //左对齐,最后加*是为了看清楚几个空格
		printf("xxxx\n");
		getchar();

		cout << resetiosflags(ios::left); //消除左对齐的设置

		cout << "八进制输出" << endl;
		cout << oct << b << endl;
		printf("xxxx\n");
		getchar();
    
		cout << "八进制-总宽度20，右对齐" << endl;
		cout << setw(20) << b << endl;
		printf("xxxx\n");
		getchar();

		cout << "八进制-总宽度20，左对齐" << endl;
		cout << setw(20) << setiosflags(ios::left) << b << '*' << endl; //左对齐,最后加*是为了看清楚几个空格
		printf("xxxx\n");
		getchar();

		cout << resetiosflags(ios::left); //消除左对齐的设置

		cout << "十六进制输出(a-f)" << endl;
		cout << hex << b << endl;
		printf("xxxx\n");
		getchar();
    
		cout << "十六进制(a-f)-总宽度20，右对齐" << endl;
		cout << setw(20) << b << endl;
		printf("xxxx\n");
		getchar();

		cout << "十六进制输出(A-F)" << endl;
		cout << setiosflags(ios::uppercase) << b << endl;
		printf("xxxx\n");
		getchar();
    
		cout << "十六进制-总宽度20，左对齐" << endl;
		cout << setw(20) << setiosflags(ios::left) << b << '*' << endl; //左对齐,最后加*是为了看清楚几个空格
		printf("xxxx\n");
		getchar();

		cout << resetiosflags(ios::uppercase) << resetiosflags(ios::left); //消除大写及左对齐的影响

	    cout << dec;     //恢复10进制
		cout << "缺省-带符号位" << endl;
		cout << setiosflags(ios::showpos) << b << endl;
		printf("xxxx\n");
		getchar();

		cout << endl << endl;
		}

    return 0;
}
