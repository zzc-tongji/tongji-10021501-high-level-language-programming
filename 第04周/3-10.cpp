#include <iostream>
using namespace std;

int main()
{
    double x,y;
    cout << "x=";
    cin >> x;
    y=(x<1)?x:((x>=10)?(3*x-11):(2*x-1));  //鍒嗘鍑芥暟锛歽={x(x<1)2x-1(1<=x<10)3x-11(x>=10)}
    cout << "y=" << y << endl;

    return (0);
}
