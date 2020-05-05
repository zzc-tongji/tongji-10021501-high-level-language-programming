#include <iostream>
using namespace std;

class Cuboid
{
	public:
		void input();
		void solve();
		void output();
	private:
		double lenth;
		double width;
		double height;
		double volume;
};

void Cuboid::input()
{
	cout << "请依次输入长方体的长宽高：";
	cin >> lenth >> width >> height;
}

void Cuboid::solve()
{
	volume=lenth*width*height;
}

void Cuboid::output()
{
	cout << "该长方体的体积是：" << volume << endl;
}

int main()
{
	Cuboid x;
	x.input();
	x.solve();
	x.output();
	//system("PAUSE"); //如果是C++作业就注释掉
	return 0;
}
