#include <iostream>
using namespace std;

int main()
{
    void sort(int,int,int);
    int x,y,z;
    cout << "input a,b,c" << endl;
    cin >> x >> y >>z;
    sort(x,y,z);
    return 0;
}

void sort(int x,int y,int z)
{
    int temp;
    if (x>y) {temp=x;x=y;y=temp;}
    if (z<x) cout << z << "<" << x << "<" << y;
    else if(z<y) cout << x << "<" << z << "<" << y;
         else cout << x << "<" << y << "<" << z;
    cout << endl;
}

/*功能：将输入的3个数从小到大排列*/
