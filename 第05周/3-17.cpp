#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a=0,n=0;
    cout << "请输入a和n：" << endl;
    cin >> a >> n;
    
    double i=0,b=0;
    for (i=1;i<=n;i++)
    {
        b=b+(pow(10,i)-1);
    }
    
    cout << "所求的值为：" << (b/9*a) << endl;

    return(0);
}
