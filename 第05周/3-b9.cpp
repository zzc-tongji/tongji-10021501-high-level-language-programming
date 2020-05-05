#include <iostream>
#include <cmath>
using namespace std;

int main()
{//while(1){
	int x;
	cin >> x;
	
	double EXP=1+x;
	double x_power=x;
	double x_factoral=1;
	int counter1;

	//system("PAUSE");

	for(counter1=2;x_power/x_factoral>=0.000001;counter1++)
	{
		x_power=x*x_power;
		x_factoral=counter1*x_factoral;
		EXP=x_power/x_factoral+EXP;
		
		/*
		cout << "counter1= " << counter1 << endl;
		cout << "x_power= " << x_power << endl;
		cout << "x_factoral= " << x_factoral << endl;
		cout << "EXP= " << EXP << endl;
		cout << "judge= " << x_power/x_factoral << endl;
		*/
		
		//system("PAUSE");
	}

	cout << "EXP= " << EXP << endl;
	//cout << "标准值= " << pow(2.718281,x) << endl;
//}

	return 0;
}
