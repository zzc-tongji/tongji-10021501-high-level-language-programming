#include <iostream>
#include <fstream>
#define LIST_NUM 10
using namespace std;

struct address_list {
	char *name;
	char *mobilephone1;
	char *mobilephone2;
	char *phone_1;
	char *phone_2;
	char *qq_1;
	char *qq_2;
	char *email_1;
	char *email_2;
};

/* 可以在此定义其它需要的函数 */

int tj_strlen(const char *str) //finish
{
	char *s;
	s=(char *)str;
	int counter;
	for (counter=0;*s!='\0';counter++)
	{
		s++;
	}
    return counter;
}

int tj_strncmp(const char *s1, const char *s2, const int len) //finish
{
	char *read1;
	char *read2;
	read1=(char *)s1;
	read2=(char *)s2;
	int counter=1;
	for (;*read1==*read2;)
	{
		if ((*read1=='\0')||(counter==len))
		{
			break;
		}
		read1++;
		read2++;
		counter++;	
	}
    return (*read1-*read2);
}

int tj_judge_strstr(const char *str, const char *substr) //finish
{
	char *s;
	s=(char *)str;
	int counter=1;
	char *p;
	p=s+tj_strlen(substr)-1;
	while (*p!='\0')
	{
		if (tj_strncmp(s,substr,tj_strlen(substr))==0)
		{
			return 1;
		}
		else
		{
			s++;
			p++;
			counter++;
		}
	}
	return 0;
}

/* 查找函数，定义不要动，实现即可 */
int search_list(struct address_list *list, char *item)
{
	/* 查找匹配项并打印 */
	int i;
	int counter=0;
	struct address_list *pointer;
	pointer=list;

	for (i=0;i<=LIST_NUM-1;i++,pointer++)
	{
		
		pointer->name         ==NULL ? 0 : counter=counter+tj_judge_strstr(pointer->name,item);
		pointer->mobilephone1 ==NULL ? 0 : counter=counter+tj_judge_strstr(pointer->mobilephone1,item);
		pointer->mobilephone2 ==NULL ? 0 : counter=counter+tj_judge_strstr(pointer->mobilephone2,item);
		pointer->phone_1      ==NULL ? 0 : counter=counter+tj_judge_strstr(pointer->phone_1,item);
		pointer->phone_2      ==NULL ? 0 : counter=counter+tj_judge_strstr(pointer->phone_2,item);
		pointer->qq_1         ==NULL ? 0 : counter=counter+tj_judge_strstr(pointer->qq_1,item);
		pointer->qq_2         ==NULL ? 0 : counter=counter+tj_judge_strstr(pointer->qq_2,item);
		pointer->email_1      ==NULL ? 0 : counter=counter+tj_judge_strstr(pointer->email_1,item);
		pointer->email_2      ==NULL ? 0 : counter=counter+tj_judge_strstr(pointer->email_2,item);
	}

	return counter;	//返回为匹配的项数，如果一个人有三项匹配，算3（目前为0，可改）
}

/* 主函数，不准动 */
int main()
{
	/* 初始数组的数量随时可能发生变化，因此程序的实现中不能直接用10来表示数组有10个元素!!! */
	struct address_list list[] = {
		{"张三",   "13912345678", "18887654321", "021-65980000",  "021-69584321", "1023123",    "73636276",    "zhangsan@163.com",     "san.zhang@126.com"},
		{"李四",   "13901201234", "18601035283", "010-53629873",  NULL,           "102312301",  "6353292732",  "lisi@hotmail.com",     "lisi@gmain.com"},
		{"王五",   NULL,          "13482330973", "021-64372987",  "025-84436251", "82837323",   NULL,          "wangwu@126.com",       NULL},
		{"赵六",   "13764212387", NULL,          "0571-85239889", NULL,           "1505210003", NULL,          "zhaoliu@sohu.com",     NULL},
		{"猫三",   "13301138263", "13901037653", "0593-8152353",  "0552-7363928", "1023123",    "10293838792", "maosan@tongji.edu.cn", "maosan@qq.com"},
		{"狗四",   NULL,          NULL,          NULL,            NULL,           "2738471827", "827361523",   "gousi@sina.com.cn",    "gousi@vip.sohu.com"},
		{"牛七",   "15002220808", NULL,          "0755-62538792", NULL,           "3527374672", NULL,          "niuqi@sina.com",       "3527374642@qq.com"},
		{"马八",   "18932147635", "18887154321", "0371-27363623", "0372-7263523", "226383726",  NULL,          "maba@163.com",         NULL},
		{"张三丰", "13587126834", NULL,          "028-287362373", "028-76365253", "1029383423", NULL,          "zhangsanfeng@163.com", "sanfeng.zhang@gmail.com"},
		{NULL,     NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}
		};
	char input_str[1024];
	int  match;

	ifstream fin;
	fin.open("7-b5-test.txt",ios::in);
	if (fin==NULL)
	{
		cout << "ERROR" << endl;
		return -1;
	}

	if (1) {
		cout << "请从键盘输入 三 : ";
		//cin >> input_str;
		fin >> input_str; cout << input_str << endl;
		match = search_list(list, input_str);
		cout << "匹配的项数为" << match << endl;
		cout << "答案：" << 3 << endl;
		cout << endl << "按任意键继续" << endl;
		getchar();
		}

	if (1) {
		cout << "请从键盘输入 张三 : ";
		//cin >> input_str;
		fin >> input_str; cout << input_str << endl;
		match = search_list(list, input_str);
		cout << "匹配的项数为" << match << endl;
		cout << "答案：" << 2 << endl;
		cout << endl << "按任意键继续" << endl;
		getchar();
		}

	if (1) {
		cout << "请从键盘输入 123 : ";
		//cin >> input_str;
		fin >> input_str; cout << input_str << endl;
		match = search_list(list, input_str);
		cout << "匹配的项数为" << match << endl;
		cout << "答案：" << 6 << endl;
		cout << endl << "按任意键继续" << endl;
		getchar();
		}

	if (1) {
		cout << "请从键盘输入 126 : ";
		//cin >> input_str;
		fin >> input_str; cout << input_str << endl;
		match = search_list(list, input_str);
		cout << "匹配的项数为" << match << endl;
		cout << "答案：" << 3 << endl;
		cout << endl << "按任意键继续" << endl;
		getchar();
		}

	if (1) {
		cout << "请从键盘输入 126.com : ";
		//cin >> input_str;
		fin >> input_str; cout << input_str << endl;
		match = search_list(list, input_str);
		cout << "匹配的项数为" << match << endl;
		cout << "答案：" << 2 << endl;
		cout << endl << "按任意键继续" << endl;
		getchar();
		}

	if (1) {
		cout << "请从键盘输入 792 : ";
		//cin >> input_str;
		fin >> input_str; cout << input_str << endl;
		match = search_list(list, input_str);
		cout << "匹配的项数为" << match << endl;
		cout << "答案：" << 2 << endl;
		cout << endl << "按任意键继续" << endl;
		getchar();
		}

	if (1) {
		cout << "请从键盘输入 1023 : ";
		//cin >> input_str;
		fin >> input_str; cout << input_str << endl;
		match = search_list(list, input_str);
		cout << "匹配的项数为" << match << endl;
		cout << "答案：" << 3 << endl;
		cout << endl << "按任意键继续" << endl;
		getchar();
		}

	if (1) {
		cout << "请从键盘输入 27384 : ";
		//cin >> input_str;
		fin >> input_str; cout << input_str << endl;
		match = search_list(list, input_str);
		cout << "匹配的项数为" << match << endl;
		cout << "答案：" << 1 << endl;
		cout << endl << "按任意键继续" << endl;
		getchar();
		}

	if (1) {
		cout << "请从键盘输入 71 : ";
		//cin >> input_str;
		fin >> input_str; cout << input_str << endl;
		match = search_list(list, input_str);
		cout << "匹配的项数为" << match << endl;
		cout << "答案：" << 5 << endl;
		cout << endl << "按任意键继续" << endl;
		getchar();
		}

	if (1) {
		cout << "请从键盘输入 037 : ";
		//cin >> input_str;
		fin >> input_str; cout << input_str << endl;
		match = search_list(list, input_str);
		cout << "匹配的项数为" << match << endl;
		cout << "答案：" << 3 << endl;
		cout << endl << "按任意键继续" << endl;
		getchar();
		}

	if (1) {
		cout << "请从键盘输入 sina : ";
		//cin >> input_str;
		fin >> input_str; cout << input_str << endl;
		match = search_list(list, input_str);
		cout << "匹配的项数为" << match << endl;
		cout << "答案：" << 2 << endl;
		cout << endl << "按任意键继续" << endl;
		getchar();
		}

	if (1) {
		cout << "请从键盘输入 sina.com : ";
		//cin >> input_str;
		fin >> input_str; cout << input_str << endl;
		match = search_list(list, input_str);
		cout << "匹配的项数为" << match << endl;
		cout << "答案：" << 2 << endl;
		cout << endl << "按任意键继续" << endl;
		getchar();
		}

	if (1) {
		cout << "请从键盘输入 san : ";
		//cin >> input_str;
		fin >> input_str; cout << input_str << endl;
		match = search_list(list, input_str);
		cout << "匹配的项数为" << match << endl;
		cout << "答案：" << 6 << endl;
		cout << endl << "按任意键继续" << endl;
		getchar();
		}

	if (1) {
		cout << "请从键盘输入 li : ";
		//cin >> input_str;
		fin >> input_str; cout << input_str << endl;
		match = search_list(list, input_str);
		cout << "匹配的项数为" << match << endl;
		cout << "答案：" << 3 << endl;
		cout << endl << "按任意键继续" << endl;
		getchar();
		}

	fin.close();

	return 0;
}
