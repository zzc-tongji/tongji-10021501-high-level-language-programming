#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double x1,y1,x2,y2,x3,y3;
	cout << "请输入第1个点横坐标x1与纵坐标y1，中间用空格隔开：" << endl;
	cin >> x1 >> y1;
	cout << "请输入第2个点横坐标x2与纵坐标y2，中间用空格隔开：" << endl;
	cin >> x2 >> y2;
	cout << "请输入第3个点横坐标x3与纵坐标y3，中间用空格隔开：" << endl;
	cin >> x3 >> y3;

	double p12,p23,p31;
	p12=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    p23=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	p31=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
	
	if ((p12+p23>p31)&&(p23+p31>p12)&&(p31+p12>p23)&&(p12>0)&&(p23>0)&&(p31>0))
    {
        double q=0,s=0;
        q=(p12+p23+p31)/2;
        s=sqrt(q*(q-p12)*(q-p23)*(q-p31)); 
		cout << "此三角形的面积为：" << s << endl;
    }
    else
    {
        cout << "此三边不能构成三角形" << endl;
    }

	return 0;
}
