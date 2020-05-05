#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

unsigned int zhuanhuan(char *p);

int main()
{
	char a[33]={'\0'}; //0-48 1-49
	cout << "请输入一个32位以内的二进制数:" << endl;
	gets(a);
	cout << "对应的十进制数为：" << endl;
	cout << zhuanhuan(a) << endl;

	//system("PAUSE"); //如果是C++作业就注释掉
	return 0;
}

unsigned int zhuanhuan(char *p)
{
	int counter;
	int e2=strlen(p)-1;
	int result=0;

	for (counter=0;e2>=0;counter++,e2--)
	{
		result=result+(((int)*(p+counter))-48)*pow(2,e2);
	}
	return result;
}
