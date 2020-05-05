#include <cstdlib>
#include <cstring>
#include <conio.h>
#include <iostream>
#include <fstream>
using namespace std;

struct PLAYER
{
	char a1[16];	//01
	short a17;		//02
	short a19;		//03
	short a21;		//04
	short a23;		//05
	int a25;		//06
	int a29;		//07
	int a33;		//08
	int a37[2];		//预留
	char a45;		//09
	char a46;		//10
	char a47;		//11
	char a48;		//预留
	short a49;		//12
	short a51;		//13
	char a53;		//14
	char a54;		//15
	char a55;		//16
	char a56;		//17
	short a57;		//18
	char a59;		//19
	char a60;		//20
	char a61;		//21
	char a62;		//22
	char a63;		//23
	char a64;		//24
};

int main()
{
	PLAYER player;
	char *p;
	p=(char *)&player-1;
	short location;
	int no,value;
	bool nic=false;
	
	/* 数据读出和显示 */
	
	ifstream infile("game.dat",ios::binary);
	
	if (!infile)
	{
		cout << "找不到目标文件！" << endl;
		exit(-1);
	}
	
	for (location=1;location<=64;location++)
	{
		infile.read(p+location,64*sizeof(char));
	}
	
	cout << "********************当前玩家信息如下********************" << endl;
	cout << endl;
	cout << "01.          玩家的昵称，最多15个字符：	" << player.a1 << endl; 
	cout << "02.                   生命值(0-10000)：	" << (int)player.a17 << endl;
	cout << "03.                   力量值(0-10000)：	" << (int)player.a19 << endl;
	cout << "04.                      体质(0-8192)：	" << (int)player.a21 << endl;
	cout << "05.                      灵巧(0-1024)：	" << (int)player.a23 << endl;
	cout << "06.             金钱数量(0-100000000)：	" << player.a25 << endl;
	cout << "07.                 名声值(0-1000000)：	" << player.a29 << endl;
	cout << "08.                 魅力值(0-1000000)：	" << player.a33 << endl;
	//cout << "              ###预留值，暂不用###：	" << player.a37 << endl;
	cout << "09.                   移动速度(0-100)：	" << (int)player.a45 << endl;
	cout << "10.                   攻击速度(0-100)：	" << (int)player.a46 << endl;
	cout << "11.                   攻击范围(0-100)：	" << (int)player.a47 << endl;
	//cout << "              ###预留值，暂不用###：	" << (int)player.a48 << endl;
	cout << "12.                    攻击力(0-2000)：	" << player.a49 << endl;
	cout << "13.                    防御力(0-2000)：	" << player.a51 << endl;
	cout << "14.                     敏捷度(0-100)：	" << (int)player.a53 << endl;
	cout << "15.                       智力(0-100)：	" << (int)player.a54 << endl;
	cout << "16.                       经验(0-100)：	" << (int)player.a55 << endl;
	cout << "17.                       等级(0-100)：	" << (int)player.a56 << endl;
	cout << "18.                   魔法值(0-10000)：	" << player.a57 << endl;
	cout << "19. 使用魔法时每次消耗的魔法值(0-100)：	" << (int)player.a59 << endl;
	cout << "20.                 魔法伤害力(0-100)：	" << (int)player.a60 << endl;
	cout << "21.                     命中率(0-100)：	" << (int)player.a61 << endl;
	cout << "22.                 魔法防御力(0-100)：	" << (int)player.a62 << endl;
	cout << "23.                     暴击率(0-100)：	" << (int)player.a63 << endl;
	cout << "24.                       耐力(0-100)：	" << (int)player.a64 << endl;
	cout << endl;
	cout << "********************************************************" << endl;
	cout << endl;

	/* 修改参数值与数据写入 */
	
	cout << "请输入需要修改的值是数量：";
	cin >> location;
	
	cout << "请输入需要修改的属性编号和值，仿照下列格式：" << endl;
	cout << "13 999" << endl;
	cout << "17 67" << endl;
	cout << "22 86" << endl;
	cout << "另请注意，输入属性编号之后必须输入值，否则会出现严重后果！" << endl;
	
	while((location--)>0)
	{
		cin >> no;

		if (no!=1)
		{
			cin >> value;
			switch (no)
			{
				case 1:
					nic=true;
					break;
				case 2:
					if (value<0) 			player.a17=0;
					else if (value>10000) 	player.a17=10000;
					else 					player.a17=value;
					break;
				case 3:
					if (value<0) 			player.a19=0;
					else if (value>10000) 	player.a19=10000;
					else 					player.a19=value;
					break;
				case 4:
					if (value<0) 			player.a21=0;
					else if (value>8192) 	player.a21=8192;
					else 					player.a21=value;
					break;
				case 5:
					if (value<0) 			player.a23=0;
					else if (value>1024) 	player.a23=1024;
					else 					player.a23=value;
					break;
				case 6:
					if (value<0) 				player.a25=0;
					else if (value>100000000) 	player.a25=100000000;
					else 						player.a25=value;
					break;
				case 7:
					if (value<0) 				player.a29=0;
					else if (value>1000000) 	player.a29=1000000;
					else 						player.a29=value;
					break;
				case 8:
					if (value<0) 				player.a33=0;
					else if (value>1000000) 	player.a33=1000000;
					else 						player.a33=value;
					break;
				case 9:
					if (value<0) 			player.a45=0;
					else if (value>100) 	player.a45=100;
					else 					player.a45=value;
					break;
				case 10:
					if (value<0) 			player.a46=0;
					else if (value>100) 	player.a46=100;
					else 					player.a46=value;
					break;
				case 11:
					if (value<0) 			player.a47=0;
					else if (value>100) 	player.a47=100;
					else 					player.a47=value;
					break;
				case 12:
					if (value<0) 			player.a49=0;
					else if (value>2000) 	player.a49=2000;
					else 					player.a49=value;
					break;
				case 13:
					if (value<0) 			player.a51=0;
					else if (value>2000) 	player.a51=2000;
					else 					player.a51=value;
					break;
				case 14:
					if (value<0) 			player.a53=0;
					else if (value>100) 	player.a53=100;
					else 					player.a53=value;
					break;
				case 15:
					if (value<0) 			player.a54=0;
					else if (value>100) 	player.a54=100;
					else 					player.a54=value;
					break;
				case 16:
					if (value<0) 			player.a55=0;
					else if (value>100) 	player.a55=100;
					else 					player.a55=value;
					break;
				case 17:
					if (value<0) 			player.a56=0;
					else if (value>100) 	player.a56=100;
					else 					player.a56=value;
					break;
				case 18:
					if (value<0) 			player.a57=0;
					else if (value>10000) 	player.a57=10000;
					else 					player.a57=value;
					break;
				case 19:
					if (value<0) 			player.a59=0;
					else if (value>100) 	player.a59=100;
					else 					player.a59=value;
					break;
				case 20:
					if (value<0) 			player.a60=0;
					else if (value>100) 	player.a60=100;
					else 					player.a60=value;
					break;
				case 21:
					if (value<0) 			player.a61=0;
					else if (value>100) 	player.a61=100;
					else 					player.a61=value;
					break;
				case 22:
					if (value<0) 			player.a62=0;
					else if (value>100) 	player.a62=100;
					else 					player.a62=value;
					break;
				case 23:
					if (value<0) 			player.a63=0;
					else if (value>100) 	player.a63=100;
					else 					player.a63=value;
					break;
				case 24:
					if (value<0) 			player.a64=0;
					else if (value>100) 	player.a64=100;
					else 					player.a64=value;
					break;
				default:;
			}
		}
		else
		{
			char test[2048];
			cin >> test;
			strncpy(player.a1,test,15);
			player.a1[15]='\0';
		}
	}
	
	cout << endl;
	cout << "******************修改后的玩家信息如下******************" << endl;
	cout << endl;
	cout << "01.          玩家的昵称，最多15个字符：	" << player.a1 << endl; 
	cout << "02.                   生命值(0-10000)：	" << (int)player.a17 << endl;
	cout << "03.                   力量值(0-10000)：	" << (int)player.a19 << endl;
	cout << "04.                      体质(0-8192)：	" << (int)player.a21 << endl;
	cout << "05.                      灵巧(0-1024)：	" << (int)player.a23 << endl;
	cout << "06.             金钱数量(0-100000000)：	" << player.a25 << endl;
	cout << "07.                 名声值(0-1000000)：	" << player.a29 << endl;
	cout << "08.                 魅力值(0-1000000)：	" << player.a33 << endl;
	//cout << "              ###预留值，暂不用###：	" << player.a37 << endl;
	cout << "09.                   移动速度(0-100)：	" << (int)player.a45 << endl;
	cout << "10.                   攻击速度(0-100)：	" << (int)player.a46 << endl;
	cout << "11.                   攻击范围(0-100)：	" << (int)player.a47 << endl;
	//cout << "              ###预留值，暂不用###：	" << (int)player.a48 << endl;
	cout << "12.                    攻击力(0-2000)：	" << player.a49 << endl;
	cout << "13.                    防御力(0-2000)：	" << player.a51 << endl;
	cout << "14.                     敏捷度(0-100)：	" << (int)player.a53 << endl;
	cout << "15.                       智力(0-100)：	" << (int)player.a54 << endl;
	cout << "16.                       经验(0-100)：	" << (int)player.a55 << endl;
	cout << "17.                       等级(0-100)：	" << (int)player.a56 << endl;
	cout << "18.                   魔法值(0-10000)：	" << player.a57 << endl;
	cout << "19. 使用魔法时每次消耗的魔法值(0-100)：	" << (int)player.a59 << endl;
	cout << "20.                 魔法伤害力(0-100)：	" << (int)player.a60 << endl;
	cout << "21.                     命中率(0-100)：	" << (int)player.a61 << endl;
	cout << "22.                 魔法防御力(0-100)：	" << (int)player.a62 << endl;
	cout << "23.                     暴击率(0-100)：	" << (int)player.a63 << endl;
	cout << "24.                       耐力(0-100)：	" << (int)player.a64 << endl;
	cout << endl;
	cout << "********************************************************" << endl;
	cout << endl;
	
	ofstream outfile("game.dat",ios::binary);
	
	if (!outfile)
	{
		cout << "无法写入！请将game.dat文件的属性设为非只读！" << endl;
		exit(-1);
	}
	
	outfile.write(p+1,64*sizeof(char));
	cout << "修改成功！" << endl;
	
	system("PAUSE");
	return 0;
}
