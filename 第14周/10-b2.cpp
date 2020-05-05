#include <iostream>
#include <string.h>
#include <conio.h>		//getch()函数要包含此头文件
#include <stdlib.h>
#include <windows.h>
#include <time.h>
//using namespace std;

class TString {
	private:
		char *content;
		int   len;
	public:
		TString(char *str=NULL);	/* 定义构造函数 */
		~TString();			/* 定义析构函数 */
		int length();			/* 定义length()函数 */
	/* 根据需要定义所需的成员函数、友元函数等 */
		TString(const TString &s);
		TString& operator=(const TString &s);
		TString& operator=(char *s);
		friend TString operator+(const TString &s1,const TString &s2);
		friend bool operator==(const TString &s1,const TString &s2);
		friend bool operator!=(const TString &s1,const TString &s2);
		friend bool operator< (const TString &s1,const TString &s2);
		friend bool operator> (const TString &s1,const TString &s2);
		friend bool operator<=(const TString &s1,const TString &s2);
		friend bool operator>=(const TString &s1,const TString &s2);
		friend istream& operator>>(istream &input,TString &s);
		friend ostream& operator<<(ostream &output,const TString &s);
		friend int tj_strcmp_new(const char *s1, const char *s2);
		friend TStringLen(TString &s);
		
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
	return len;
}

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

/* ----main函数不准动---- */
int main()
{
	if (1) {
		TString s1;                  //s1为NULL
		TString s2("teststr2");      //s2为"teststr2"
		TString s3="teststr3";       //s3为"teststr3"
		TString s4=NULL;             //s4为NULL
		TString s5="";               //s5为NULL

		cout << "定义对象并初始化测试(NULL及字符串常量初始化)" << endl;

		cout << "s1应该是<NULL>，  实际输出：" << s1 << endl;
		cout << "s2应该是teststr2，实际输出：" << s2 << endl;
		cout << "s3应该是teststr3，实际输出：" << s3 << endl;
		cout << "s4应该是<NULL>，  实际输出：" << s4 << endl;
		cout << "s5应该是<NULL>，  实际输出：" << s5 << endl;

		cout << endl << "任意键继续..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		TString s0   = "teststr1";
		char *str1   = "teststr2";
		char  str2[] = "teststr3";
		char *str3   = NULL;
		char  str4[] = "";
		TString s1=s0, s2=str1, s3=str2, s4=str3, s5=str4;

		cout << "定义对象并初始化测试(TString对象及字符指针、字符数组)" << endl;

		cout << "s1应该是teststr1，实际输出：" << s1 << endl;
		cout << "s2应该是teststr2，实际输出：" << s2 << endl;
		cout << "s3应该是teststr3，实际输出：" << s3 << endl;
		cout << "s4应该是<NULL>，  实际输出：" << s4 << endl;
		cout << "s5应该是<NULL>，  实际输出：" << s5 << endl;
		
		cout << endl << "任意键继续..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		TString s1;
		
		cout << "重载cin测试" << endl;
		
		cout << "请在键盘上输入Hello" << endl;
		cin >> s1;
		cout << "s1应该是Hello，实际输出：" << s1 << endl;

		cout << "请在键盘上输入Hello 123" << endl;
		cin >> s1;
		cout << "s1应该是Hello，实际输出：" << s1 << endl;

		cout << endl << "任意键继续..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		TString s1("Hello"), s2;
		
		cout << "赋值操作测试" << endl;

		cout << "s1应该是Hello， 实际输出：" << s1 << endl;
		
		s2=s1;
		cout << "s2应该是Hello， 实际输出：" << s2 << endl;
		
		s1="Hi";
		cout << "s1应该是Hi，    实际输出：" << s1 << endl;
		
		s2="";
		cout << "s2应该是<NULL>，实际输出：" << s2 << endl;

		s1=NULL;
		cout << "s1应该是<NULL>，实际输出：" << s1 << endl;

		cout << endl << "任意键继续..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		TString s0, s1("tong"), s2("ji"), s3;

		cout << "连接(+)测试(两个TString类)"<< endl;
		
		s3 = s1+s2;
		cout << "s3应为tongji，实际输出：" << s3 << endl;
		
		s3 = s2+s1;
		cout << "s3应为jitong，实际输出：" << s3 << endl;

		s3 = s1+s0;
		cout << "s3应为tong，  实际输出：" << s3 << endl;

		s3 = s0+s2;
		cout << "s3应为ji，    实际输出：" << s3 << endl;

		cout << endl << "任意键继续..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		TString s1("tong"), s3;

		cout << "连接(+)测试(TString类和字符串常量)"<< endl;

		s3 = s1+"ji";
		cout << "s3应为tongji，实际输出：" << s3 << endl;
		
		s3 = "ji"+s1;
		cout << "s3应为jitong，实际输出：" << s3 << endl;

		s3 = s1+"";
		cout << "s3应为tong，  实际输出：" << s3 << endl;

		s3 = s1+NULL;
		cout << "s3应为tong，  实际输出：" << s3 << endl;

		s3 = ""+s1;
		cout << "s3应为tong，  实际输出：" << s3 << endl;

		s3 = NULL+s1;
		cout << "s3应为tong，  实际输出：" << s3 << endl;

		cout << endl << "任意键继续..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		TString s1("tong"), s3;
		char *str1="ji", *str2="", *str3=NULL;

		cout << "连接(+)测试(TString类和字符指针)"<< endl;

		s3 = s1+str1;
		cout << "s3应为tongji，实际输出：" << s3 << endl;
		
		s3 = str1+s1;
		cout << "s3应为jitong，实际输出：" << s3 << endl;

		s3 = s1+str2;
		cout << "s3应为tong，  实际输出：" << s3 << endl;

		s3 = str2+s1;
		cout << "s3应为tong，  实际输出：" << s3 << endl;

		s3 = s1+str3;
		cout << "s3应为tong，  实际输出：" << s3 << endl;

		s3 = str3+s1;
		cout << "s3应为tong，  实际输出：" << s3 << endl;

		cout << endl << "任意键继续..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		TString s1("tong"), s3;
		char str1[]="ji", str2[]="";

		cout << "连接(+)测试(TString类和字符数组)"<< endl;

		s3 = s1+str1;
		cout << "s3应为tongji，实际输出：" << s3 << endl;
		
		s3 = str1+s1;
		cout << "s3应为jitong，实际输出：" << s3 << endl;

		s3 = s1+str2;
		cout << "s3应为tong，  实际输出：" << s3 << endl;

		s3 = str2+s1;
		cout << "s3应为tong，  实际输出：" << s3 << endl;

		cout << endl << "任意键继续..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		TString s1="house", s2="horse", s3="house", s4="", s5=NULL;

		cout << "比较运算测试(两个TString类)" << endl;

		cout << "串1=" << s1 << " 串2=" << s2 << " > 结果应为1，实际：" <<(s1 >  s2) << endl;
		cout << "串1=" << s1 << " 串2=" << s2 << " >=结果应为1，实际：" <<(s1 >= s2) << endl;
		cout << "串1=" << s1 << " 串2=" << s2 << " < 结果应为0，实际：" <<(s1 <  s2) << endl;
		cout << "串1=" << s1 << " 串2=" << s2 << " <=结果应为0，实际：" <<(s1 <= s2) << endl;
		cout << "串1=" << s1 << " 串2=" << s2 << " ==结果应为0，实际：" <<(s1 == s2) << endl;
		cout << "串1=" << s1 << " 串2=" << s2 << " !=结果应为1，实际：" <<(s1 != s2) << endl;
		
		cout << "串1=" << s1 << " 串3=" << s3 << " > 结果应为0，实际：" <<(s1 >  s3) << endl;
		cout << "串1=" << s1 << " 串3=" << s3 << " >=结果应为1，实际：" <<(s1 >= s3) << endl;
		cout << "串1=" << s1 << " 串3=" << s3 << " < 结果应为0，实际：" <<(s1 <  s3) << endl;
		cout << "串1=" << s1 << " 串3=" << s3 << " <=结果应为1，实际：" <<(s1 <= s3) << endl;
		cout << "串1=" << s1 << " 串3=" << s3 << " ==结果应为1，实际：" <<(s1 == s3) << endl;
		cout << "串1=" << s1 << " 串3=" << s3 << " !=结果应为0，实际：" <<(s1 != s3) << endl;

		cout << "串1=" << s1 << " 串4=" << s4 << " > 结果应为1，实际：" <<(s1 >  s4) << endl;
		cout << "串1=" << s1 << " 串4=" << s4 << " >=结果应为1，实际：" <<(s1 >= s4) << endl;
		cout << "串1=" << s1 << " 串4=" << s4 << " < 结果应为0，实际：" <<(s1 <  s4) << endl;
		cout << "串1=" << s1 << " 串4=" << s4 << " <=结果应为0，实际：" <<(s1 <= s4) << endl;
		cout << "串1=" << s1 << " 串4=" << s4 << " ==结果应为0，实际：" <<(s1 == s4) << endl;
		cout << "串1=" << s1 << " 串4=" << s4 << " !=结果应为1，实际：" <<(s1 != s4) << endl;

		cout << "串1=" << s1 << " 串5=" << s5 << " > 结果应为1，实际：" <<(s1 >  s5) << endl;
		cout << "串1=" << s1 << " 串5=" << s5 << " >=结果应为1，实际：" <<(s1 >= s5) << endl;
		cout << "串1=" << s1 << " 串5=" << s5 << " < 结果应为0，实际：" <<(s1 <  s5) << endl;
		cout << "串1=" << s1 << " 串5=" << s5 << " <=结果应为0，实际：" <<(s1 <= s5) << endl;
		cout << "串1=" << s1 << " 串5=" << s5 << " ==结果应为0，实际：" <<(s1 == s5) << endl;
		cout << "串1=" << s1 << " 串5=" << s5 << " !=结果应为1，实际：" <<(s1 != s5) << endl;

		cout << endl << "任意键继续..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		TString s1="house";

		cout << "比较运算测试(TString类和字符串常量)" << endl;

		cout << "串1=" << s1 << " 常量=horse" << " > 结果应为1，实际：" << (s1 >  "horse") << endl;
		cout << "串1=" << s1 << " 常量=horse" << " >=结果应为1，实际：" << (s1 >= "horse") << endl;
		cout << "串1=" << s1 << " 常量=horse" << " < 结果应为0，实际：" << (s1 <  "horse") << endl;
		cout << "串1=" << s1 << " 常量=horse" << " <=结果应为0，实际：" << (s1 <= "horse") << endl;
		cout << "串1=" << s1 << " 常量=horse" << " ==结果应为0，实际：" << (s1 == "horse") << endl;
		cout << "串1=" << s1 << " 常量=horse" << " !=结果应为1，实际：" << (s1 != "horse") << endl;

		cout << "串1=" << s1 << " 常量=house" << " > 结果应为0，实际：" << (s1 >  "house") << endl;
		cout << "串1=" << s1 << " 常量=house" << " >=结果应为1，实际：" << (s1 >= "house") << endl;
		cout << "串1=" << s1 << " 常量=house" << " < 结果应为0，实际：" << (s1 <  "house") << endl;
		cout << "串1=" << s1 << " 常量=house" << " <=结果应为1，实际：" << (s1 <= "house") << endl;
		cout << "串1=" << s1 << " 常量=house" << " ==结果应为1，实际：" << (s1 == "house") << endl;
		cout << "串1=" << s1 << " 常量=house" << " !=结果应为0，实际：" << (s1 != "house") << endl;

		cout << "串1=" << s1 << " 常量=" << " > 结果应为1，实际：" << (s1 >  "") << endl;
		cout << "串1=" << s1 << " 常量=" << " >=结果应为1，实际：" << (s1 >= "") << endl;
		cout << "串1=" << s1 << " 常量=" << " < 结果应为0，实际：" << (s1 <  "") << endl;
		cout << "串1=" << s1 << " 常量=" << " <=结果应为0，实际：" << (s1 <= "") << endl;
		cout << "串1=" << s1 << " 常量=" << " ==结果应为0，实际：" << (s1 == "") << endl;
		cout << "串1=" << s1 << " 常量=" << " !=结果应为1，实际：" << (s1 != "") << endl;

		cout << "串1=" << s1 << " 常量=<NULL>" << " > 结果应为1，实际：" << (s1 >  NULL) << endl;
		cout << "串1=" << s1 << " 常量=<NULL>" << " >=结果应为1，实际：" << (s1 >= NULL) << endl;
		cout << "串1=" << s1 << " 常量=<NULL>" << " < 结果应为0，实际：" << (s1 <  NULL) << endl;
		cout << "串1=" << s1 << " 常量=<NULL>" << " <=结果应为0，实际：" << (s1 <= NULL) << endl;
		cout << "串1=" << s1 << " 常量=<NULL>" << " ==结果应为0，实际：" << (s1 == NULL) << endl;
		cout << "串1=" << s1 << " 常量=<NULL>" << " !=结果应为1，实际：" << (s1 != NULL) << endl;

		cout << endl << "任意键继续..." << endl;
		getch();
		cout << endl;
		}
	
	if (1) {
		TString s1="house";
		char *str2="horse", *str3="house", *str4="", *str5=NULL;

		cout << "比较运算测试(TString类和字符指针)" << endl;

		cout << "串1=" << s1 << " 串2=" << str2 << " > 结果应为1，实际：" <<(s1 >  str2) << endl;
		cout << "串1=" << s1 << " 串2=" << str2 << " >=结果应为1，实际：" <<(s1 >= str2) << endl;
		cout << "串1=" << s1 << " 串2=" << str2 << " < 结果应为0，实际：" <<(s1 <  str2) << endl;
		cout << "串1=" << s1 << " 串2=" << str2 << " <=结果应为0，实际：" <<(s1 <= str2) << endl;
		cout << "串1=" << s1 << " 串2=" << str2 << " ==结果应为0，实际：" <<(s1 == str2) << endl;
		cout << "串1=" << s1 << " 串2=" << str2 << " !=结果应为1，实际：" <<(s1 != str2) << endl;
		
		cout << "串1=" << s1 << " 串3=" << str3 << " > 结果应为0，实际：" <<(s1 >  str3) << endl;
		cout << "串1=" << s1 << " 串3=" << str3 << " >=结果应为1，实际：" <<(s1 >= str3) << endl;
		cout << "串1=" << s1 << " 串3=" << str3 << " < 结果应为0，实际：" <<(s1 <  str3) << endl;
		cout << "串1=" << s1 << " 串3=" << str3 << " <=结果应为1，实际：" <<(s1 <= str3) << endl;
		cout << "串1=" << s1 << " 串3=" << str3 << " ==结果应为1，实际：" <<(s1 == str3) << endl;
		cout << "串1=" << s1 << " 串3=" << str3 << " !=结果应为0，实际：" <<(s1 != str3) << endl;

		cout << "串1=" << s1 << " 串4=" << str4 << " > 结果应为1，实际：" <<(s1 >  str4) << endl;
		cout << "串1=" << s1 << " 串4=" << str4 << " >=结果应为1，实际：" <<(s1 >= str4) << endl;
		cout << "串1=" << s1 << " 串4=" << str4 << " < 结果应为0，实际：" <<(s1 <  str4) << endl;
		cout << "串1=" << s1 << " 串4=" << str4 << " <=结果应为0，实际：" <<(s1 <= str4) << endl;
		cout << "串1=" << s1 << " 串4=" << str4 << " ==结果应为0，实际：" <<(s1 == str4) << endl;
		cout << "串1=" << s1 << " 串4=" << str4 << " !=结果应为1，实际：" <<(s1 != str4) << endl;

		cout << "串1=" << s1 << " 串5=<NULL>" << " > 结果应为1，实际：" <<(s1 >  str5) << endl;
		cout << "串1=" << s1 << " 串5=<NULL>" << " >=结果应为1，实际：" <<(s1 >= str5) << endl;
		cout << "串1=" << s1 << " 串5=<NULL>" << " < 结果应为0，实际：" <<(s1 <  str5) << endl;
		cout << "串1=" << s1 << " 串5=<NULL>" << " <=结果应为0，实际：" <<(s1 <= str5) << endl;
		cout << "串1=" << s1 << " 串5=<NULL>" << " ==结果应为0，实际：" <<(s1 == str5) << endl;
		cout << "串1=" << s1 << " 串5=<NULL>" << " !=结果应为1，实际：" <<(s1 != str5) << endl;

		
		cout << endl << "任意键继续..." << endl;
		getch();
		cout << endl;
		}
	
	if (1) {
		TString s1="house";
		char str2[]="horse", str3[]="house", str4[]="";

		cout << "比较运算测试(TString类和字符指针)" << endl;
		
		cout << "串1=" << s1 << " 串2=" << str2 << " > 结果应为1，实际：" <<(s1 >  str2) << endl;
		cout << "串1=" << s1 << " 串2=" << str2 << " >=结果应为1，实际：" <<(s1 >= str2) << endl;
		cout << "串1=" << s1 << " 串2=" << str2 << " < 结果应为0，实际：" <<(s1 <  str2) << endl;
		cout << "串1=" << s1 << " 串2=" << str2 << " <=结果应为0，实际：" <<(s1 <= str2) << endl;
		cout << "串1=" << s1 << " 串2=" << str2 << " ==结果应为0，实际：" <<(s1 == str2) << endl;
		cout << "串1=" << s1 << " 串2=" << str2 << " !=结果应为1，实际：" <<(s1 != str2) << endl;
		
		cout << "串1=" << s1 << " 串3=" << str3 << " > 结果应为0，实际：" <<(s1 >  str3) << endl;
		cout << "串1=" << s1 << " 串3=" << str3 << " >=结果应为1，实际：" <<(s1 >= str3) << endl;
		cout << "串1=" << s1 << " 串3=" << str3 << " < 结果应为0，实际：" <<(s1 <  str3) << endl;
		cout << "串1=" << s1 << " 串3=" << str3 << " <=结果应为1，实际：" <<(s1 <= str3) << endl;
		cout << "串1=" << s1 << " 串3=" << str3 << " ==结果应为1，实际：" <<(s1 == str3) << endl;
		cout << "串1=" << s1 << " 串3=" << str3 << " !=结果应为0，实际：" <<(s1 != str3) << endl;

		cout << "串1=" << s1 << " 串4=" << str4 << " > 结果应为1，实际：" <<(s1 >  str4) << endl;
		cout << "串1=" << s1 << " 串4=" << str4 << " >=结果应为1，实际：" <<(s1 >= str4) << endl;
		cout << "串1=" << s1 << " 串4=" << str4 << " < 结果应为0，实际：" <<(s1 <  str4) << endl;
		cout << "串1=" << s1 << " 串4=" << str4 << " <=结果应为0，实际：" <<(s1 <= str4) << endl;
		cout << "串1=" << s1 << " 串4=" << str4 << " ==结果应为0，实际：" <<(s1 == str4) << endl;
		cout << "串1=" << s1 << " 串4=" << str4 << " !=结果应为1，实际：" <<(s1 != str4) << endl;

		cout << endl << "任意键继续..." << endl;
		getch();
		cout << endl;
		}
	
	if (1) {
		TString s1="tong", s2;

		cout << "求长度测试(length()函数)" << endl;
		
		cout << "s1为tong，  长度应为4，实际：" << s1.length() << endl;
		cout << "s2为<NULL>，长度应为0，实际：" << s2.length() << endl;
		s2 = s1+"ji";
		cout << "s2为tongji，长度应为6，实际：" << s2.length() << endl;

		cout << endl << "任意键继续..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		TString s1="tong", s2;

		cout << "求长度测试(TStringLen()函数)" << endl;
		
		cout << "s1为tong，  长度应为4，实际：" << TStringLen(s1) << endl;
		cout << "s2为<NULL>，长度应为0，实际：" << TStringLen(s2) << endl;
		cout << "串为tongji，长度应为6，实际：" << TStringLen(s1+(s2="ji")) << endl;
		cout << "串为tongji，长度应为6，实际：" << TStringLen(s1+"ji") << endl;
		cout << "串为tongji，长度应为6，实际：" << TStringLen(s2=s1+"ji") << endl;
		cout << "串为tong，  长度应为4，实际：" << TStringLen(s1+NULL) << endl;

		cout << endl << "任意键继续..." << endl;
		getch();
		cout << endl;
		}

	if (1) {
		TString s1;
		int     total, len, i;
		char    temp[65536];
		long    t_start, t_end;
		long    teacher_time = 850000;
		char   *crc_str;

		cout << "内存性能测试(大约需要12-20分钟)，以内存耗尽或申请满100MB字节为结束条件，按任意键开始" << endl;
		getch();

		crc_str = new char[100*1024*1024+65536]; //申请（100MB+64KB）空间
		*crc_str = 0; //置为空串

		t_start = GetTickCount(); //取当前系统时间，单位毫秒
		srand(time(0));
		total = 0;
		while(1) {
		    len = 32768 + rand()%32768;

			cout << "s1已有长度：" << (double)total/(1024*1024) << " MB字节，本次增加 " << len << " 字节" << endl;
			for(i=0; i<len; i++)
				temp[i] = ' '+rand()%95;	//数组用随机字符填充
			temp[len] = 0;
			total += len;
			s1 = s1 + temp;
			strcat(crc_str, temp);
			if (s1!=crc_str) {
				cout << "s1累加验证出错，请检查程序的实现部分" << endl;
				goto END;
				}
			if (s1.length()==0 || s1.length() > 1024*1024*100)	//满100MB或内存耗尽则结束
				break;
			}
		t_end = GetTickCount();   //取当前系统时间

	    cout << "time=" << (t_end - t_start)/1000.0 << endl; 
		if (s1.length()==0)
		    cout << "内存分配到达 " << total/(1024*1024) << " MB字节后，内存耗尽" << endl;
		else
		    cout << "内存分配到达满100MB，测试结束" << endl;
		cout << "    本次测试耗时 " << (t_end - t_start)/1000.0 << "秒，大约是老师机器的" << (100.0*(t_end - t_start)/teacher_time) << "%" << endl;
		cout << "    【说明】：只有VC++6.0编译系统下的数据才有可比性" << endl;
		cout << "              老师的机器为Intel(R) Core(TM) i3-2310M CPU @2.10GHz" << endl;
		cout << "              如果时间相差太大，除CPU的性能差异外，还有可能是算法问题" << endl;

		cout << endl << "任意键继续..." << endl;
		getch();
		cout << endl;
		}
END:
	system("pause");

	return 0;
}
