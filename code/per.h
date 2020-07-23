#include "stime.h"
#include <cstring>
#include <iostream>
using namespace std;
class per:public stime//通讯录成员,继承创建时间管理类 
{
	protected:
	string name;//姓名 
	string sex;//性别 
	string tel;//电话 
	string addr;//地址 
	string post_code;//邮编 
	string email;//电子邮箱 
	string qq;//QQ
	string group;//类别
	
	public:
	per(string,string,string,string,string,string,string,string);
	per();
	void auto_change(string,string,string,string,string,string,string,string,int,int,int,int,int,int);//自动读入数据
	void change();//输入数据 
	void save();//保存到文件
	void del();//类清空
	void list_show();//表单输出 
	bool _in(string,bool);//姓名/电话查找存在 
	bool is_set();//是否为空
	char get_name();//获取姓名首字母 
	void show_name();//输出姓名 
	string get_group();//获取组名 
};
