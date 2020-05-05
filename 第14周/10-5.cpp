#include <iostream>
#include <iomanip.h>     //视情况可按需修改
//using namespace std;   //视情况可按需修改

class matrix {
    private:
        int value[2][3];
    public:
        matrix operator+(matrix &b);
        /* ----根据需要添加其它成员函数的定义---- */
		matrix();
		matrix(int (*p)[3]);
		friend istream& operator>>(istream &out,matrix &m);
		friend ostream& operator<<(ostream &out,matrix &m);
    };
	
istream& operator>>(istream &in,matrix &m)
{
	int i,j;
	for (i=0;i<=1;i++)
	{
		for (j=0;j<=2;j++)
		{
			in >> m.value[i][j];
		}
	}
	return in;
}

ostream& operator<<(ostream &out,matrix &m)
{
	int i,j;
	for (i=0;i<=1;i++)
	{
		for (j=0;j<=2;j++)
		{
			out << setw(4) << m.value[i][j];
		}
		out << endl;
	}
	return out;
}

/* ----给出类成员函数的体外实现---- */
matrix::matrix(){}

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

/* ----main函数不准动---- */
int main()
{
    matrix m1, m2, m3;

    cout << "请输入矩阵m1的值(共2行3列，按先行后列的顺序输入)" << endl;
    cin >> m1;
    cout << "请输入矩阵m2的值(共2行3列，按先行后列的顺序输入)" << endl;
    cin >> m2;
	
    cout << "初始矩阵m1的值：" << endl;
    cout << m1 << endl;
    cout << "初始矩阵m2的值：" << endl;
    cout << m2 << endl;
    cout << "相加后矩阵m3的值：" << endl;
    cout << (m3=m1+m2) << endl;

    return 0;
}
