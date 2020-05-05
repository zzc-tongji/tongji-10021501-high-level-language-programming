#include <iostream>
#include <iomanip>
using namespace std;

int C(int m,int n); //组合数计算，m上n下

int main()
{
    int a[10][10]={0};
    int i,j,k;
    
	for (i=0;i<=9;i++)
    {
        for (j=0;j<=i;j++)
        {
            a[i][j]=C(j,i);
        }
    }

    cout << "杨辉三角：" << endl;
    for (i=0;i<=9;i++)
    {
		for (k=0;k<=18-2*i;k++)
		{
			cout << " ";
		}
        for (j=0;j<=i;j++)
        {
			
            cout << setw(4) << a[i][j];
        }
        cout << endl;	
    }

    return 0;
}

int C(int m,int n)
{
    if  (m!=0||n!=0)
    {
        int m_factorial=1,A_m_n=1,i;
        if  (m!=0)
        {
            for (i=1;i<=m;i++)
            {
                m_factorial=m_factorial*i;
            }
        }
        else
        {
            m_factorial=1;
        }
        for (i=n;i>=n-m+1;i--)
        {
            A_m_n=A_m_n*i;
        }
        return(A_m_n/m_factorial);
    }
    else
    {
        return(1);
    }
}
