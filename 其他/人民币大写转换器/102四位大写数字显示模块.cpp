#include <iostream>
using namespace std;

int main()
{while(1){
	long int b3,b2,b1,b0;
	cin >> b3 >> b2 >> b1 >> b0;

	if ((b3)&&(b2)&&(b1)&&(b0)) //不含零，1111，完成
	{
		switch (b3) //千
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
		cout << "仟";

		switch (b2) //百
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
		cout << "佰";
		
		switch (b1) //十
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
		cout << "拾";

		switch (b0) //一
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
	}
	
	else if ((!b3)&&(b2)&&(b1)&&(b0)) //含1个零，0111，完成
	{
		//千
		
		switch (b2) //百
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
		cout << "佰";
		
		switch (b1) //十
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
		cout << "拾";

		switch (b0) //一
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
	}

	else if ((b3)&&(!b2)&&(b1)&&(b0)) //含1个零，1011，完成
	{
		switch (b3) //千
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
		cout << "仟";

		cout << "零"; //百
		
		switch (b1) //十
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
		cout << "拾";

		switch (b0) //一
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
	}
	
	else if ((b3)&&(b2)&&(!b1)&&(b0)) //含1个零，1101，完成
	{
		switch (b3) //千
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
		cout << "仟";

		switch (b2) //百
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
		cout << "佰";
		
		cout << "零"; //十

		switch (b0) //一
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
	}
	
	else if ((b3)&&(b2)&&(b1)&&(!b0)) //含1个零，1110，完成
	{
		switch (b3) //千
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
		cout << "仟";

		switch (b2) //百
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
		cout << "佰";
		
		switch (b1) //十
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
		cout << "拾";

		//一
	}
	
	else if ((!b3)&&(!b2)&&(b1)&&(b0)) //含2个零，0011，完成
	{
		//千
		
		//百
		
		switch (b1) //十
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
		cout << "拾";

		switch (b0) //一
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
	}

	else if ((!b3)&&(b2)&&(!b1)&&(b0)) //含2个零，0101，完成
	{
		//千

		switch (b2) //百
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
		cout << "佰";
		
		cout << "零"; //十

		switch (b0) //一
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
	}
	
	else if ((!b3)&&(b2)&&(b1)&&(!b0)) //含2个零，0110，完成
	{
		//千

		switch (b2) //百
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
		cout << "佰";
		
		switch (b1) //十
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
		cout << "拾";

		//一
	}
	
	else if ((b3)&&(!b2)&&(!b1)&&(b0)) //含2个零，1001，完成
	{
		switch (b3) //千
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
		cout << "仟";

		cout << "零"; //百
		
		
		//十

		switch (b0) //一
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
	}
	
	else if ((b3)&&(!b2)&&(b1)&&(!b0)) //含2个零，1010，完成
	{
		switch (b3) //千
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
		cout << "仟";

		cout << "零"; //百
		
		switch (b1) //十
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
		cout << "拾";

		//一
		
	}
	
	else if ((b3)&&(b2)&&(!b1)&&(!b0)) //含2个零，1100，完成
	{
		switch (b3) //千
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
		cout << "仟";

		switch (b2) //百
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
		cout << "佰";
		
		//十
		
		//一
	}
	
	else if ((b3)&&(!b2)&&(!b1)&&(!b0)) //含3个零，1000，完成
	{
		switch (b3) //千
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
		cout << "仟";

		//百
		
		//十
		
		//一
	}
	
	else if ((!b3)&&(b2)&&(!b1)&&(!b0)) //含3个零，0100，完成
	{
		//千

		switch (b2) //百
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
		cout << "佰";
		
		//十

		//一
	}
	
	else if ((!b3)&&(!b2)&&(b1)&&(!b0)) //含3个零，0010，完成
	{
		//千

		//百
		
		switch (b1) //十
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
		cout << "拾";

		//一
	}

	else if ((!b3)&&(!b2)&&(!b1)&&(b0)) //含3个零，0001，完成
	{
		//千
		
		//百
		
		//十

		switch (b0) //一
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
	}
	
	else //含4个零，0000，完成
	{
		//千
		
		//百
		
		//十

		//一
	}

cout << endl;}
	return 0;
}
