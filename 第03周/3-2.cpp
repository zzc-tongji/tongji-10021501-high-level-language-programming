#include <iostream>
#include <iomanip>
using namespace std;

const double pi=3.14159265358979;

int main()
{
	double r=1.5;
	double h=3;
	
	double Circle_C=0;
	double Circle_A=0;
	double Sphere_SA=0;
	double Sphere_V=0;
	double Cylindrical_V=0;
	
	Circle_C=2*r*pi;
	Circle_A=pi*r*r;
	Sphere_SA=4*pi*r*r;
	Sphere_V=4.0/3.0*pi*r*r*r;
	Cylindrical_V=pi*r*r*h;

	cout << "圆半径=" << r << "，圆柱高=" << h << endl;
	cout << "*****计算结果*****" << endl;
	cout << setiosflags(ios::fixed) << setprecision(2);
	cout << "圆周长=     " << Circle_C << endl;
	cout << "圆面积=     " << Circle_A << endl;
	cout << "圆球表面积= " << Sphere_SA << endl;
	cout << "圆球体积=   " << Sphere_V << endl;
	cout << "圆柱体积=   " << Cylindrical_V << endl;

	return 0;
}
