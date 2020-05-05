#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <cstring>
#include <string>
using namespace std;

void display_first();
int check(char *t);
void solve(char *t,struct KFC *p,struct SPECIAL *q);
void test(struct KFC *p);
void test(struct SPECIAL *p);
void display_result(struct KFC *p,struct SPECIAL *q);

struct KFC
{
	char  no;
	char *name;
	float price;
	int num;
	int num_0;
};
struct SPECIAL
{
	char *item;
	char *prompt;
	float price;
	int num;
};

int main()
{
	while(1)
	{
		struct KFC n_menu[]=
		{
			{'\0' , NULL ,                0, 0, 0}, //64
			{'A', "香辣鸡腿堡",        15.0, 0, 0},
			{'B', "劲脆鸡腿堡",        15.0, 0, 0},
			{'C', "新奥尔良烤鸡腿堡" , 15.5, 0, 0},
			{'D', "老北京鸡肉卷" ,     14.0, 0, 0},
			{'E', "川香嫩牛卷",        15.0, 0, 0},
			{'F', "吮指原味鸡",         9.0, 0, 0},
			{'G', "新奥尔良烤翅" ,      9.5, 0, 0},
			{'H', "香辣鸡翅",           8.5, 0, 0},
			{'I', "劲脆鸡米花",        10.0, 0, 0},
			{'J', "上校鸡块",           8.0, 0, 0},
			{'K', "薯条(小)",           7.0, 0, 0},
			{'L', "薯条(中)",           8.5, 0, 0},
			{'M', "薯条(大)",          10.0, 0, 0},
			{'N', "芙蓉鲜蔬汤",         6.0, 0, 0},
			{'O', "香甜粟米棒",         6.5, 0, 0},
			{'P', "土豆泥",             4.5, 0, 0},
			{'Q', "脆皮甜筒",           3.0, 0, 0},
			{'R', "百事可乐(小)",       6.0, 0, 0},
			{'S', "百事可乐(中)",       7.5, 0, 0},
			{'T', "百事可乐(大)",       9.0, 0, 0},
			{'U', "九珍",               9.5, 0, 0},
			{'V', "雪顶爱尔兰咖啡",    10.0, 0, 0},
			{'\0' , NULL ,                0, 0, 0}, //W
			{'\0' , NULL ,                0, 0, 0}, //X
			{'\0' , NULL ,                0, 0, 0}, //Y
			{'\0' , NULL ,                0, 0, 0}  //Z
		};
		struct SPECIAL s_menu[]=
		{
			{NULL, NULL, 0, 0},                        //0
			{"AKR", "香辣汉堡超值套餐",      25.0, 0}, //1 A1 K1 R1
			{"FFFFFGGHHTTTO", "超值全家桶",  84.0, 0}, //2 F5 G2 H2 T3 O1
			{"QQ", "脆皮甜筒第 2 件半价",     4.5, 0}, //3 Q2
			{"LLL", "中薯买 2 送 1",         17.0, 0}, //4 L2
			{NULL, NULL, 0, 0}                         //5
		};
		string input_pre;
		char* input;
		
		display_first();
		cin >> input_pre;
		input=(char *)input_pre.c_str();
		
		if (check(input)==0)
		{
			cout << "点餐结束，按任意键退出程序。" << endl;
			getch();
			//system("PAUSE"); //如果是C++作业就注释掉
			return 0;
		}
		else if (check(input)==-1)
		{
			cout << "输入错误，按任意键继续。" << endl;
			getch();
			system("cls");
			continue;
		}
		
		strupr(input);
		solve(input,n_menu,s_menu);
		
		display_result(n_menu,s_menu);
		cout << "点单完成，按任意键继续。" << endl;
		getch();
		system("cls");
	}
}

void display_first()
{
	cout << "A 香辣鸡腿堡          15     |   B 劲脆鸡腿堡          15 " << endl;
	cout << "C 新奥尔良烤鸡腿堡    15.5   |   D 老北京鸡肉卷        14 " << endl;
	cout << "E 川香嫩牛卷          15     |   F 吮指原味鸡          9  " << endl;
	cout << "G 新奥尔良烤翅        9.5    |   H 香辣鸡翅            8.5" << endl;
	cout << "I 劲脆鸡米花          10     |   J 上校鸡块            8  " << endl;
	cout << "K 薯条(小)            7      |   L 薯条(中)            8.5" << endl;
	cout << "M 薯条(大)            10     |   N 芙蓉鲜蔬汤          6  " << endl;
	cout << "O 香甜粟米棒          6.5    |   P 土豆泥              4.5" << endl;
	cout << "Q 脆皮甜筒            3      |   R 百事可乐(小)        6  " << endl;
	cout << "S 百事可乐(中)        7.5    |   T 百事可乐(大)        9  " << endl;
	cout << "U 九珍                9.5    |   V 雪顶爱尔兰咖啡      10 " << endl;
	cout << endl;
	cout << "【优惠信息】：" << endl;
	cout << "香辣汉堡超值套餐=香辣鸡腿堡+薯条(小)+百事可乐(小)=25" << endl;
	cout << "超值全家桶=吮指原味鸡*5+新奥尔良烤翅*2+香辣鸡翅*2+香甜粟米棒+百事可乐(大)*3=84" << endl;
	cout << "脆皮甜筒第2件半价=脆皮甜筒*2=4.5" << endl;
	cout << "中薯买2送1=薯条(中)*3=17" << endl;
	cout << endl;
	cout << "【输入规则说明】：" << endl;
	cout << "AKR=香辣鸡腿堡+薯条(小)+百事可乐(小) / ahaah=香辣鸡腿堡*3+香辣鸡翅*2" << endl;
	cout << "字母不分大小写，不限顺序，单独输入0则退出程序" << endl;
	cout << endl;
	cout << "请点单:";
}

int check(char *t)
{
	if ((*t)=='0') return 0;
	for (;(*t)!='\0';t++)
	{
		if ((*t)<'A' || ((*t)>'V' && (*t)<'a') || ((*t)>'v'))
		{
			return -1;
		}
	}
	return 1;
}

void solve(char *t,struct KFC *p,struct SPECIAL *q)
{	
	for (;*t!='\0';t++)
		{
			p[*t-64].num++;
			p[*t-64].num_0++;
		}
		//1 AKR
		while  (p['A'-64].num>=1 &&
				p['K'-64].num>=1 &&
				p['R'-64].num>=1)
		{
			q[1].num++;
			p['A'-64].num-=1;
			p['K'-64].num-=1;
			p['R'-64].num-=1;
		}
		//2 FFFFFGGHHTTTO
		while  (p['F'-64].num>=5 &&
				p['G'-64].num>=2 &&
				p['H'-64].num>=2 &&
				p['T'-64].num>=3 &&
				p['O'-64].num>=1)
		{
			q[2].num++;
			p['F'-64].num-=5;
			p['G'-64].num-=2;
			p['H'-64].num-=2;
			p['T'-64].num-=3;
			p['O'-64].num-=1;
		}
		//3 QQ
		while (p['Q'-64].num>=2)
		{
			q[3].num++;
			p['Q'-64].num-=2;
		}
		//4 LLL
		while (p['L'-64].num>=3)
		{
			q[4].num++;
			p['L'-64].num-=3;
		}
}

void test(struct KFC *p)
{
	for (p++;p->no!='\0';p++)
	{
		cout << p->no << " " << p->num << " " << p->num_0 << endl;
	}
}

void test(struct SPECIAL *p)
{
	for (p++;p->item!=NULL;p++)
	{
		cout << p->item << " " << p->num << endl;
	}
}

void display_result(struct KFC *p,struct SPECIAL *q)
{
	float Price=0;
	bool flag=false;

	cout << "您的点餐=";
	p++;
	for (;p->name!=NULL;p++)
	{
		Price += p->num * p->price;
		if (p->num_0==0)
		{
			continue;
		}
		else
		{
			if (flag) cout << "+";
			cout << p->name << "*" << p->num_0;
			flag=true;
		}
	}
	q++;
	for (;q->prompt!=NULL;q++)
	{
		Price += q->num * q->price;
	}
	cout << endl << "共计：" << Price << "元" << endl;
}
