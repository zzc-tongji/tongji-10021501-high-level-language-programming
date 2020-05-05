#include <iostream>
#include <string.h>
#include <conio.h>		//getch()函数要包含此头文件
#include <stdlib.h>
#include <windows.h>
#include <time.h>
using std::cin;
using std::cout;
using std::endl;
using std::ios;

class TString {
	private:
		char *content;
		int   len;
	public:
		TString(char *str=NULL);	/* 定义构造函数 */
		~TString();					/* 定义析构函数 */
		int length();				/* 定义length()函数 */
		// /* 根据需要定义所需的成员函数、友元函数等 */
		// TString(const TString &s);
		// TString& operator=(const TString &s);
		// TString& operator=(char *s);
		// friend TString operator+(const TString &s1,const TString &s2);
		// friend bool operator==(const TString &s1,const TString &s2);
		// friend bool operator< (const TString &s1,const TString &s2);
		// friend bool operator> (const TString &s1,const TString &s2);
		// friend bool operator<=(const TString &s1,const TString &s2);
		// friend bool operator>=(const TString &s1,const TString &s2);
		// friend istream& operator>>(istream &input,TString &s);
		// friend ostream& operator<<(ostream &output,const TString &s);
		// friend TStringLen(TString &s);
		TString& operator+=(char *s);
		friend bool operator!=(const TString &s1,const TString &s2);
		friend int tj_strcmp_new(const char *s1, const char *s2);		
};

TString::TString(char *str)		//不允许再带缺省值
{
	// 首先考虑str为NULL或str为空串的情况
	if (str==NULL || str[0]==0) {
		content = NULL;
		len     = 0;
		}
	else {
		len     = strlen(str);
		content = new char[len+1];
		if (content)
			strcpy(content, str); //含'\0'拷贝
		else {
			/* 申请不到空间的情况 */
			content = NULL;
			len     = 0;
			}
		}
}

TString::~TString()
{
	if (content)
		delete content;
}

int TString::length()
{
	std::ios::sync_with_stdio(false);
	return len;
}

/*
TString::TString(const TString &s)
{
	if (s.content) 
	{
		len     = s.len;
		content = new char[len+1];
		if (content)
		{
			strcpy(content, s.content);
		}
		else //申请不到空间的情况
		{
			len = 0;
		}
	}
	else //s为空串
	{
		content = NULL;
		len     = 0;
	}
}

TString& TString::operator=(const TString &s)
{
	if (s.content)
	{
		if (content)
		{
			delete content;
		}
		len = s.len;
		content = new char[len+1];
		if (content)
		{
			strcpy(content,s.content);
		}
		else //申请不到空间的情况
		{
			len = 0;
		}
	}
	else //s为空串
	{
		content = NULL;
		len     = 0;
	}
	return *this;
}

TString& TString::operator=(char *s)
{
	if (s && s[0])
	{
		if (content)
		{
			delete content;
		}
		len = strlen(s);
		content = new char[len+1];
		if (content)
		{
			strcpy(content,s);
		}
		else //申请不到空间的情况
		{
			len=0;
		}
	}
	else //s为空串
	{
		content = NULL;
		len     = 0;
	}
	return *this;
}

TString operator+(const TString &s1,const TString &s2)
{
	TString temp;
	if (s1.content && s2.content)
	{
		temp.len     = s1.len + s2.len;
		temp.content = new char[temp.len+1];
		if (temp.content)
		{
			strcpy(temp.content,s1.content);
			strcat(temp.content,s2.content);
		}
		else
		{
			temp.len = 0;
		}
		return temp;
	}
	else if (s1.content!=NULL && s2.content==NULL) //s2为空串
	{
		return s1;
	}
	else if (s1.content==NULL && s2.content!=NULL) //s1为空串
	{
		return s2;
	}
	else //s1和s2均为空串
	{
		return temp;
	}
}

bool operator==(const TString &s1,const TString &s2)
{
	if (tj_strcmp_new(s1.content,s2.content)==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator< (const TString &s1,const TString &s2)
{
	if (tj_strcmp_new(s1.content,s2.content)<0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator> (const TString &s1,const TString &s2)
{
	if (tj_strcmp_new(s1.content,s2.content)>0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator<=(const TString &s1,const TString &s2)
{
	if (tj_strcmp_new(s1.content,s2.content)<=0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator>=(const TString &s1,const TString &s2)
{
	if (tj_strcmp_new(s1.content,s2.content)>=0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

istream& operator>>(istream &input,TString &s)
{
	char temp[4096]="\0";
	input >> temp;
	s.len = strlen(temp);
	s.content = new char[s.len+1];
	strcpy(s.content,temp);
	return input;
}
	
ostream& operator<<(ostream &output,const TString &s)
{
	if (s.content)
	{
		output << s.content;
	}
	else
	{
		output << "<NULL>";
	}
	return output;
}

TStringLen(TString &s)
{
	return s.len;
}
*/

TString& TString::operator+=(char *s)
{
	char *temp=NULL;
	
	if (s && s[0])
	{
		temp = content;
		len += strlen(s);
		content = new char[len+1];
		content[0] = '\0';
		if (content)
		{
			if (temp)
			{
				strcpy(content,temp);
			}
			strcat(content,s);
		}
		else //申请不到空间的情况
		{
			len=0;
		}
		if (temp)
		{
			delete temp;
		}
	}
	else //s为空串
	{
		content = NULL;
		len     = 0;
	}
	return *this;
}

bool operator!=(const TString &s1,const TString &s2)
{
	if (tj_strcmp_new(s1.content,s2.content))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int tj_strcmp_new(const char *s1, const char *s2)
{
	char *read1;
	char *read2;
	read1=(char *)s1;
	read2=(char *)s2;

	if (read1!=NULL && read2!=NULL)
	{
		for (;*read1==*read2;)
		{
			if (*read1=='\0')
			{
				break;
			}
			read1++;
			read2++;
		}
		return(*read1-*read2);
	}
	else if	(read1==NULL && read2!=NULL)
	{
		return(-*read2);
	}
	else if (read1!=NULL && read2==NULL)
	{
		return(*read1);
	}
	else
	{
		return 0;
	}
}

/* main函数不允许有任何改动 */
int main()
{
	if (1) {
		const int MAX_BYTES = 100*1024*1024;
		TString s1;

		int     total, len, i;
		char    temp[65536];
		long    t_start, t_end;
		char   *crc_str;

		cout << "内存累加申请性能测试，以内存耗尽或申请满100MB字节为结束条件，按任意键开始" << endl;
		getch();

		crc_str = new char[MAX_BYTES+65536]; //申请（100MB+64KB）空间
		*crc_str = 0; //置为空串

		t_start = GetTickCount(); //取当前系统时间，单位毫秒
		srand(time(0));
		total = 0;
		while(1) {
			len = 32768 + rand()%32768;

			cout << "s1已有长度：" << s1.length()/(1024.0*1024) << " MB字节，本次增加 " << len << " 字节" << endl;
			for(i=0; i<len; i++)
				temp[i] = ' '+rand()%95;	//数组用随机字符填充
			temp[len] = 0;
			total += len;
			s1 += temp;
			strcat(crc_str, temp);
			if (s1.length()==0 || s1.length() > MAX_BYTES)	//满100MB或内存耗尽则结束
				break;
			}
		t_end = GetTickCount();   //取当前系统时间

		cout << "time=" << (t_end - t_start)/1000.0 << endl; 
		if (s1.length()==0)
			cout << "内存分配到达 " << total/(1024.0*1024) << " MB字节后，内存耗尽" << endl;
		else
			cout << "内存分配到达满100MB，测试结束" << endl;

		if (s1!=crc_str)
			cout << "s1累加验证出错，请检查程序的实现部分" << endl;
		else
			cout << "    本次测试耗时 " << (t_end - t_start)/1000.0 << "秒" << endl;

		delete crc_str;

//		cout << endl << "任意键继续..." << endl;
//		getch();
		cout << endl;
		}

	system("pause");

	return 0;
}
