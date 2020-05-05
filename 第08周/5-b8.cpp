#include <iostream>
#include <fstream>
using namespace std;

short fangzhen[9][9]={0};
short fangzhen_zhuanzhi[9][9]={0};
short fangzhen_fenkuai[9][9]={0};

bool judge(short p[]);
void zhuanzhi(short p[]);
void fenkuai();

int main()
{
	short i,j;
	ifstream input;
	
	//打开文件
	input.open("shudu.txt",ios::in);
	if (input==NULL)
	{
		cout << "打开文件失败!!" << endl;
		return -1;
	}
	for (i=0;i<=8;i++)
	{
		for (j=0;j<=8;j++)
		{
			input >> fangzhen[i][j];
		}
	}
	input.close();


	/*测试用

	//输出原方阵
	for (i=0;i<=8;i++)
	{
		for (j=0;j<=8;j++)
		{
			cout << fangzhen[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	//输出转置方正
	zhuanzhi(fangzhen[0]);
	for (i=0;i<=8;i++)
	{
		for (j=0;j<=8;j++)
		{
			cout << fangzhen_zhuanzhi[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	//输出九宫格提取方阵
	fenkuai();
	for (i=0;i<=8;i++)
	{
		for (j=0;j<=8;j++)
		{
			cout << fangzhen_fenkuai[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	*/

	cout << "方阵为：" << endl;

	//输出原方阵
	for (i=0;i<=8;i++)
	{
		for (j=0;j<=8;j++)
		{
			cout << fangzhen[i][j] << " ";
		}
		cout << endl;
	}

	//按行判断
	for (i=0;i<=8;i++)
	{
		if (judge(fangzhen[i])==false)
		{
			goto END;
		}
	}

	//按列判断
	zhuanzhi(fangzhen[0]);
	for (i=0;i<=8;i++)
	{
		if (judge(fangzhen_zhuanzhi[i])==false)
		{
			goto END;
		}
	}

	//按九宫格判断
	fenkuai();
	for (i=0;i<=8;i++)
	{
		if (judge(fangzhen_fenkuai[i])==false)
		{
			goto END;
		}
	}

	cout << endl << "该方阵满足数独的解。" << endl << endl;
	return 0;

END:
	cout << endl << "该方阵不满足数独的解!!" << endl << endl; 
	return 0;
}

bool judge(short p[]) //判断0-9是否都出现过（在连续的9个short变量中）
{
	short counter,sum=0;
	for (counter=0;counter<=8;counter++)
	{
		sum=sum+p[counter];
	}
	return (sum==45?true:false);
}

void zhuanzhi(short p[]) //转置，结果输出至fangzhen_zhuanzhi[9][9]
{
	short i,j,counter=0;
	for(i=0;i<=8;i++)
	{
		for(j=0;j<=8;j++)
		{
			fangzhen_zhuanzhi[j][i]=p[counter];
			counter++;
		}
	}
}

void fenkuai()  //我实在想不出这里如何用循环设计，所以只好手工赋值了。
{

	//   (0,0)  (0,3)  (0,6)

	//   (3,0)  (3,3)  (3,6)

	//   (6,0)  (6,3)  (6,6)


	/****************************************/
	//子块(0,0)
	fangzhen_fenkuai[0][0]=fangzhen[0][0];
	fangzhen_fenkuai[0][1]=fangzhen[0][1];
	fangzhen_fenkuai[0][2]=fangzhen[0][2];
	fangzhen_fenkuai[0][3]=fangzhen[1][0];
	fangzhen_fenkuai[0][4]=fangzhen[1][1];
	fangzhen_fenkuai[0][5]=fangzhen[1][2];
	fangzhen_fenkuai[0][6]=fangzhen[2][0];
	fangzhen_fenkuai[0][7]=fangzhen[2][1];
	fangzhen_fenkuai[0][8]=fangzhen[2][2];
	//子块(0,3)
	fangzhen_fenkuai[1][0]=fangzhen[0][3];
	fangzhen_fenkuai[1][1]=fangzhen[0][4];
	fangzhen_fenkuai[1][2]=fangzhen[0][5];
	fangzhen_fenkuai[1][3]=fangzhen[1][3];
	fangzhen_fenkuai[1][4]=fangzhen[1][4];
	fangzhen_fenkuai[1][5]=fangzhen[1][5];
	fangzhen_fenkuai[1][6]=fangzhen[2][3];
	fangzhen_fenkuai[1][7]=fangzhen[2][4];
	fangzhen_fenkuai[1][8]=fangzhen[2][5];
	//子块(0,6)
	fangzhen_fenkuai[2][0]=fangzhen[0][6];
	fangzhen_fenkuai[2][1]=fangzhen[0][7];
	fangzhen_fenkuai[2][2]=fangzhen[0][8];
	fangzhen_fenkuai[2][3]=fangzhen[1][6];
	fangzhen_fenkuai[2][4]=fangzhen[1][7];
	fangzhen_fenkuai[2][5]=fangzhen[1][8];
	fangzhen_fenkuai[2][6]=fangzhen[2][6];
	fangzhen_fenkuai[2][7]=fangzhen[2][7];
	fangzhen_fenkuai[2][8]=fangzhen[2][8];
	/****************************************/

	/****************************************/
	//子块(3,0)
	fangzhen_fenkuai[3][0]=fangzhen[3][0];
	fangzhen_fenkuai[3][1]=fangzhen[3][1];
	fangzhen_fenkuai[3][2]=fangzhen[3][2];
	fangzhen_fenkuai[3][3]=fangzhen[4][0];
	fangzhen_fenkuai[3][4]=fangzhen[4][1];
	fangzhen_fenkuai[3][5]=fangzhen[4][2];
	fangzhen_fenkuai[3][6]=fangzhen[5][0];
	fangzhen_fenkuai[3][7]=fangzhen[5][1];
	fangzhen_fenkuai[3][8]=fangzhen[5][2];
	//子块(3,3)
	fangzhen_fenkuai[4][0]=fangzhen[3][3];
	fangzhen_fenkuai[4][1]=fangzhen[3][4];
	fangzhen_fenkuai[4][2]=fangzhen[3][5];
	fangzhen_fenkuai[4][3]=fangzhen[4][3];
	fangzhen_fenkuai[4][4]=fangzhen[4][4];
	fangzhen_fenkuai[4][5]=fangzhen[4][5];
	fangzhen_fenkuai[4][6]=fangzhen[5][3];
	fangzhen_fenkuai[4][7]=fangzhen[5][4];
	fangzhen_fenkuai[4][8]=fangzhen[5][5];
	//子块(3,6)
	fangzhen_fenkuai[5][0]=fangzhen[3][6];
	fangzhen_fenkuai[5][1]=fangzhen[3][7];
	fangzhen_fenkuai[5][2]=fangzhen[3][8];
	fangzhen_fenkuai[5][3]=fangzhen[4][6];
	fangzhen_fenkuai[5][4]=fangzhen[4][7];
	fangzhen_fenkuai[5][5]=fangzhen[4][8];
	fangzhen_fenkuai[5][6]=fangzhen[5][6];
	fangzhen_fenkuai[5][7]=fangzhen[5][7];
	fangzhen_fenkuai[5][8]=fangzhen[5][8];
	/****************************************/

	/****************************************/
	//子块(6,0)
	fangzhen_fenkuai[6][0]=fangzhen[6][0];
	fangzhen_fenkuai[6][1]=fangzhen[6][1];
	fangzhen_fenkuai[6][2]=fangzhen[6][2];
	fangzhen_fenkuai[6][3]=fangzhen[7][0];
	fangzhen_fenkuai[6][4]=fangzhen[7][1];
	fangzhen_fenkuai[6][5]=fangzhen[7][2];
	fangzhen_fenkuai[6][6]=fangzhen[8][0];
	fangzhen_fenkuai[6][7]=fangzhen[8][1];
	fangzhen_fenkuai[6][8]=fangzhen[8][2];
	//子块(6,3)
	fangzhen_fenkuai[7][0]=fangzhen[6][3];
	fangzhen_fenkuai[7][1]=fangzhen[6][4];
	fangzhen_fenkuai[7][2]=fangzhen[6][5];
	fangzhen_fenkuai[7][3]=fangzhen[7][3];
	fangzhen_fenkuai[7][4]=fangzhen[7][4];
	fangzhen_fenkuai[7][5]=fangzhen[7][5];
	fangzhen_fenkuai[7][6]=fangzhen[8][3];
	fangzhen_fenkuai[7][7]=fangzhen[8][4];
	fangzhen_fenkuai[7][8]=fangzhen[8][5];
	//子块(6,6)
	fangzhen_fenkuai[8][0]=fangzhen[6][6];
	fangzhen_fenkuai[8][1]=fangzhen[6][7];
	fangzhen_fenkuai[8][2]=fangzhen[6][8];
	fangzhen_fenkuai[8][3]=fangzhen[7][6];
	fangzhen_fenkuai[8][4]=fangzhen[7][7];
	fangzhen_fenkuai[8][5]=fangzhen[7][8];
	fangzhen_fenkuai[8][6]=fangzhen[8][6];
	fangzhen_fenkuai[8][7]=fangzhen[8][7];
	fangzhen_fenkuai[8][8]=fangzhen[8][8];
	/****************************************/
}




