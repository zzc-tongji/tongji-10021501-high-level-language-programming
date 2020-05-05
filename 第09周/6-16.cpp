#include <iostream>
#include <cmath>
using namespace std;

int draw_int(char *p);

int main()
{
	char str[101]={'\0'};
	int a[10]={0};
	int num_location[10]={0}; //数字起始位在str字符数组中的位置
	int counter,counter1;

	cout << "请输入一串不超过100个的字符：" << endl;
	gets(str);

	//操作num_location[10]，正确;
	if ((*str>=48)&&(*str<=57))
	{
		*num_location=0;
		counter1=1;
	}
	else
	{
		counter1=0;
	}
	for (counter=1;*(str+counter)!='\0';counter++)
	{
		if (((*(str+counter)>=48)&&(*(str+counter)<=57))&&((*(str+counter-1)<48)||(*(str+counter-1)>57)))
		{
			*(num_location+counter1)=counter;
			counter1++;
		}
	}

	cout << "该字符串中含有" << counter1 << "个数字，提取结果如下" << endl;

	for (counter=0;counter<=counter1-1;counter++)
	{
		*(a+counter)=draw_int(str+*(num_location+counter));
		cout << *(a+counter) << " ";
	}

	cout << endl;
	
	//system("PAUSE"); //如果是C++作业就注释掉
	return 0;
}

int draw_int(char *p)
{
	char temp[11]={'\0'};
	int counter,e10;
	int result=0;

	for (counter=0;(*(p+counter)>=48)&&(*(p+counter)<=57);) //正确
	{
		*(temp+counter)=*(p+counter);
		counter++;
	}

	e10=counter-1;

	for (counter=0;e10>=0;counter++,e10--) //正确
	{
		result=result+((int)(*(temp+counter)-48))*pow(10,e10);
	}

	return result;
}
