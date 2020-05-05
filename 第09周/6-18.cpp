#include <iostream>
using namespace std;

int main()
{
	char m[]={"January\0February\0March\0April\0May\0June\0July\0August\0September\0October\0November\0December\0invalid"};

	int x;
	cout << "璇疯緭鍏ユ湀浠斤細" << endl;
	cin >> x;

	switch (x)
	{
		case 1:
			cout << m << endl;
			break;
		case 2:
			cout << m+8 << endl;
			break;
		case 3:
			cout << m+17 << endl;
			break;
		case 4:
			cout << m+23 << endl;
			break;
		case 5:
			cout << m+29 << endl;
			break;
		case 6:
			cout << m+33 << endl;
			break;
		case 7:
			cout << m+38 << endl;
			break;
		case 8:
			cout << m+43 << endl;
			break;
		case 9:
			cout << m+50 << endl;
			break;
		case 10:
			cout << m+60 << endl;
			break;
		case 11:
			cout << m+68 << endl;
			break;
		case 12:
			cout << m+77 << endl;
			break;
		default:
			cout << m+86 << endl;
	}

	//system("PAUSE"); //濡傛灉鏄疌++浣滀笟灏辨敞閲婃帀
	return 0;
}
