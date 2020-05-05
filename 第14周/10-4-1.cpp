#include <iostream>
#include <iomanip>
using namespace std;

class matrix {
    private:
        int value[2][3];
    public:
        matrix(int (*p)[3]);  //构造函数，用数组初始化矩阵
        void display();       //输出该矩阵
        matrix operator+(matrix &b);
        /* ----根据需要添加其它成员函数的定义---- */
		matrix();

    };

/* ----给出类成员函数的体外实现---- */
matrix::matrix(int (*p)[3])
{
	int i,j;
	for (i=0;i<=1;i++)
	{
		for (j=0;j<=2;j++)
		{
			value[i][j]=p[i][j];
		}
	}
}

void matrix::display()
{
	int i,j;
	for (i=0;i<=1;i++)
	{
		for (j=0;j<=2;j++)
		{
			cout << setw(4) << value[i][j];
		}
		cout << endl;
	}
}

matrix matrix::operator+(matrix &b)
{
	int i,j;
	matrix c;
	for (i=0;i<=1;i++)
	{
		for (j=0;j<=2;j++)
		{
			c.value[i][j]=value[i][j]+b.value[i][j];
		}
	}
	return c;
}

matrix::matrix(){}

/* ----main函数不准动---- */
int main()
{
    int a[2][3] = {{1,2,3},{4,5,6}};
    int b[2][3] = {{1,2,3},{4,5,6}};
    matrix m1(a), m2(b), m3;

    cout << "初始矩阵m1的值：" << endl;
    m1.display();
    cout << "初始矩阵m2的值：" << endl;
    m2.display();
    m3 = m1 + m2;
    cout << "相加后矩阵m3的值：" << endl;
    m3.display();

    return 0;
}
