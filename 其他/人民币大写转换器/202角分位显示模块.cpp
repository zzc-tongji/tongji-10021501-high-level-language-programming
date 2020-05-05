#include <iostream>
using namespace std;

int main()
{while(1){
	long int jiao,fen;
	cin >> jiao >> fen;

	if ((jiao)&&(fen)) //不含零，11，完成
	{
		switch (jiao) //角
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "角";

		switch (fen) //分
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "分";
	}
	
	else if ((jiao)&&(!fen)) //含1个零，10，完成
	{
		switch (jiao) //角
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "角";

		//分
	}
	
	else if ((!jiao)&&(fen)) //含1个零，01
	{
		cout << "零"; //角
		
		switch (fen) //分
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
			default:;
		}
		cout << "分";
	}
	
	else //含2个零，00，完成
	{
		cout << "整" << endl;

		//角

		//分
	}

cout << endl;}
	return 0;
}
