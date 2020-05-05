#include <iostream>
using namespace std;

class Time
{
	public:  //鍘燂細
		void set_time(void);
		void show_time(void);
	private: //鍘燂細
		int hour;
		int minute;
		int sec;
};
Time t;

int main()
{
	t.set_time();
	//鍘燂細cin >> t.hour;
	//鍘燂細cin >> t.minute;
	//鍘燂細cin >> t.second;
	t.show_time();
	return 0;
}

void Time::set_time(void) //鍘燂細int set_time(void)
{
	cin >> t.hour;
	cin >> t.minute;
	cin >> t.sec;
}

void Time::show_time(void) //鍘燂細int show_time(void)
{
	cout << t.hour << ":" << t.minute << ":" << t.sec << endl;
}
