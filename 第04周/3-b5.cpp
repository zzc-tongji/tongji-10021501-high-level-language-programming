#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a=0,b=0,c=0;
    cout << "请依次输入三角形三条边的长度，用空格隔开：" << endl;
    cin >> a >> b >> c;
    
	if ((a+b>c)&&(b+c>a)&&(c+a>b)&&(a>0)&&(b>0)&&(c>0))
    {
        double p=0,s=0;
        p=(a+b+c)/2;
        s=sqrt(p*(p-a)*(p-b)*(p-c)); 
        cout << "此三角形的面积为：" << s << endl;
    }
    else
    {
        cout << "此三边不能构成三角形" << endl;
    }
    
    return 0;
}
