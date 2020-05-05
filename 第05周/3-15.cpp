#include <iostream>

using namespace std;

int main()
{
    int m=0,n=0;
    cout << "请输入两个正整数：";
    cin >> m >> n;
    
    int x=0;
    if (m<n)
    {
       x=m;
       m=n;
       n=x;
    }
    
    int m1=m,n1=n,q=1;
    for (;q!=0;)
    {
        q=m1%n1;
        m1=n1;
        n1=q;
    } 
    
    cout << "最大公约数：" << m1 << endl;
    cout << "最小公倍数：" << (m*n/m1) << endl; 
    
    return(0);
}
