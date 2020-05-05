#include <iostream>
#include <cstring>
using namespace std;

bool judge(char *p);

int main()
{
	char a[1000]={'\0'};
	cout << "请输入一个长度不超过1000的字符串：" << endl;
	gets(a);
	cout << (judge(a)?"yes":"no") << endl;
	//system("PAUSE"); //如果是C++作业就注释掉
	return 0;
}

bool judge(char *p)
{
	int p_chang=strlen(p);
	int counter;

	if ((p_chang==1)||(p_chang==0))
	{
		return true;
	}
	else
	{
		for(counter=0;counter<=(p_chang+1)/2;counter++)
		{
			if (*(p+counter)!=*(p+p_chang-1-counter))
			{
				return false;
			}
		}
	}
	return true;
}
