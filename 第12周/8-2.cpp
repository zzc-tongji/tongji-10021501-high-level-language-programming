#include <iostream>
using namespace std;

class Time
{
	private:
		int hour;
		int minute;
		int sec;
	public:
		void input()
		{
			cin >> hour;
			cin >> minute;
			cin >> sec;
		}
		void output()
		{
			cout << hour << ":" << minute << ":" << sec << endl;
		}
};

int main()
{
	Time tl;
	tl.input();
	tl.output();
	//system("PAUSE"); //濡傛灉鏄疌++浣滀笟灏辨敞閲婃帀
	return 0;
}
