#include <iostream.h>
#include <iomanip.h>
#include <string.h>
#include <conio.h>		//getch()函数要包含此头文件
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define PART_LENTH 4	//在此处修改：链表中每小段中存放PART_LENTH个字符（建议是4的倍数）
//using namespace std;

struct HEAD
{
	char *pointer;	//总串的头指针
	bool flag;		//写入权限标志
};

HEAD head={NULL,true};
char *temp_1=NULL;
int temp_2=0;

class TString {
	private:
		char *content;
		int   len;
	public:
		TString(char *str=NULL);	/* 定义构造函数 */
		~TString();					/* 定义析构函数 */
		int length();				/* 定义length()函数 */
	/* 根据需要定义所需的成员函数、友元函数等 */
/*
		TString(const TString &s);
		TString& operator=(const TString &s);
		TString& operator=(char *s);
		friend TString operator+(const TString &s1,const TString &s2);
		friend bool operator==(const TString &s1,const TString &s2);
		friend bool operator< (const TString &s1,const TString &s2);
		friend bool operator> (const TString &s1,const TString &s2);
		friend bool operator<=(const TString &s1,const TString &s2);
		friend bool operator>=(const TString &s1,const TString &s2);
		friend istream& operator>>(istream &input,TString &s);
		friend ostream& operator<<(ostream &output,const TString &s);
		friend bool operator!=(const TString &s1,const TString &s2);
		friend int tj_strcmp_new(const char *s1, const char *s2);
		friend TStringLen(TString &s);
*/
		TString& operator+=(char *s);
		friend char *strcpy_new(char *s1, const char *s2);				//拷贝C字符串，串尾部不加\0（函数功能测试无误）;
		friend bool operator!=(const TString &s1,const TString &s2);

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
		content = (char *)(char *)calloc(len+1,sizeof(char));
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
	{
		free(content);
	}
	else
	{
		char *n1;
		char *n2;
		int counter;
		bool flag;

		counter=0;
		n1=::head.pointer;
		flag=true;

		while(flag)
		{
			n2=n1;
			if (*(int *)n2)
			{
				n2 += ( sizeof(int) + PART_LENTH + sizeof(int) );
				n2 = * (char **) n2;
				if (n2==NULL) flag=false;
				counter += PART_LENTH;
			}
			else
			{
				for (n2+=sizeof(int);*n2='\0';n2++)
				{
					counter++;
				}
				n2 += sizeof(int);
				n2 = * (char **) n2;
				if (n2==NULL) flag=false;
			}
			delete n1;
			n1=n2;
		}
		cout << "成功释放所有空间！" << endl;
	}
}

int TString::length()
{
	return len;
}

/*
TString::TString(const TString &s)
{
	if (s.content)
	{
		len     = s.len;
		content = (char *)calloc(len+1,sizeof(char));
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
			free(content);
		}
		len = s.len;
		content = (char *)calloc(len+1,sizeof(char));
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
			free(content);
		}
		len = strlen(s);
		content = (char *)calloc(len+1,sizeof(char));
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
		temp.content = (char *)calloc(temp.len+1,sizeof(char));
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
	s.content = (char *)calloc(s.len+1,sizeof(char));
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

TStringLen(TString &s)
{
	return s.len;
}
*/

/*	//参考
TString& TString::operator+=(char *s)
{
	char *temp=NULL;

	if (s && s[0])
	{
		temp = content;
		len += strlen(s);
		content = (char *)calloc(len+1,sizeof(char));
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
			free(temp);
		}
	}
	else //s为空串
	{
		content = NULL;
		len     = 0;
	}
	return *this;
}
*/

TString& TString::operator+=(char *s)
{
	/* content = NULL 失效 */

	char *read      = s;			//字符读入头，初始化指向串s
	int total_lenth = strlen(s);	//C字符串s的串长
	/*	PART_LENTH									//拆分后的小段长度	*/
	int part_quality   = total_lenth / PART_LENTH;	//拆分后的小段数量
	int part_remainder = total_lenth % PART_LENTH;	//剩余的小段长度

	char *n1,*n2,*head_part;
	int counter;

	if (s && s[0])
	{
		//申请
		for (counter=0;counter<part_quality;counter++)
		{
			/* 空间申请段 */
			if (counter>0)
			{
				n2=n1;	//本节位置备份
			}
			n1 = new char[ sizeof(int) + PART_LENTH + sizeof(int) + sizeof(char *) ];	//新开一节空间
			if (n1==NULL)
			{
				cout << "内存不足，程序结束" << endl;
				exit(-1);
			}
			if (counter==0)
			{
				head_part=n1;
			}
			else
			{
				* (char **) (n2+sizeof(int)+PART_LENTH)=n1;	//连接这两节
			}

			/* 数据操作端 */
			* (int *)   n1 = -1;												//该小段不是末端，标志位4字节置为-1
			strncpy( n1 + sizeof(int),read,PART_LENTH);							//字符串内容填充（每次拷贝的字符串不含\0,所以需要另行定义分割位！）
			* (int *) ( n1 + sizeof(int) + PART_LENTH ) = 0;					//为保证串内容安全增加分割位，分割位4字节置为0
			* (char **) ( n1 + sizeof(int) + PART_LENTH + sizeof(int) ) = NULL;	//指针位4字节置为NULL
			read += PART_LENTH;		//读入头移位
			len  += PART_LENTH; 	//（对象）串长增加
		}

		/* 第一次运行+=时运行（::head.pointer仅可以写入一次） */
		if (::head.flag)
		{
			::head.pointer = head_part;
			::head.flag = false;
		}

		/* 非第一次运行+=时运行 */
		if (::temp_1)
		{
			* (char **) ( ::temp_1 + sizeof(int) + ::temp_2 + sizeof(int) ) = head_part;
		}

		/* 空间申请段 */
		n2=n1;																			//本节位置备份
		n1 = new char[ sizeof(int) + part_remainder + sizeof(int) + sizeof(char *) ];	//新开一节空间
		* (char **) (n2+sizeof(int)+part_remainder)=n1;									//连接这两节
		/* 数据操作端 */
		* (int *)   n1 = 0;														//该小段是末端，标志位4字节置为0
		strcpy_new( n1 + sizeof(int),read );									//字符串内容填充（每次拷贝的字符串不含\0,所以需要另行定义分割位！）
		* (int *) ( n1 + sizeof(int) + part_remainder ) = 0;					//为保证串内容安全增加分割位，分割位4字节置为0
		* (char **) ( n1 + sizeof(int) + part_remainder + sizeof(int) ) = NULL;	//指针位4字节置为NULL

		/* 传出末端参数，供下次调用+=函数使用 */
		::temp_1 = n1;
		::temp_2 = part_remainder;
		// cout/*  << hex << setiosflags(ios::uppercase)  */<< (int)::temp_1 << endl;
		// cout << dec << ::temp_2 << endl;
	}
	else //s为空串
	{}
	return *this;
}

char *strcpy_new(char *s1, const char *s2)
{
	char *read=(char *)s2;
	char *write=s1;

	for (;;)
	{
		*write=*read;
		read++;
		write++;
		if (*read=='\0')
		{
			//*write=*read;
			break;
		}
	}

    return s1;
}

bool operator!=(const TString &s1,const TString &s2)
{
	return false;
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
