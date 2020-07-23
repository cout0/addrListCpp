#include "per.h"
#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
per::per(string a="",string b="",string c="",string d="",string e="",string f="",string g="",string h=""):stime()//通讯录成员构造
{
	name=a;//姓名 
	sex=b;//性别 
	tel=c;//电话 
	addr=d;//地址 
	post_code=e;//邮编 
	email=f;//电子邮箱 
	qq=g;//QQ 
	group=h;//类别
}

per::per():stime()//通讯录成员构造
{
	name="";//姓名 
	sex="";//性别 
	tel="";//电话 
	addr="";//地址 
	post_code="";//邮编 
	email="";//电子邮箱 
	qq="";//QQ 
	group="";//类别
}

void per::auto_change(string a,string b,string c,string d,string e,string f,string g,string h,
					int i,int j,int k,int l,int m,int n)//数据读入 
{
	name=a;//姓名 
	sex=b;//性别 
	tel=c;//电话 
	addr=d;//地址 
	post_code=e;//邮编 
	email=f;//电子邮箱 
	qq=g;//QQ 
	group=h;//类别
	year=i;//年 
	mon=j;//月 
	day=k;//日 
	hour=l;//时 
	min=m;//分 
	sec=n;//秒 
}

void per::change()//通讯录成员构造
{
	string in;
	cout<<"请依次输入--电话 地址 邮编 电子邮箱 QQ 组类别:\n";
	cin>>in;
	tel=in;//电话 
	cin>>in;
	addr=in;//地址 
	cin>>in;
	post_code=in;//邮编 
	cin>>in;
	email=in;//电子邮箱 
	cin>>in;
	qq=in;//QQ 
	cin>>in;
	group=in;//类别
}

void per::save()//数据保存到文件 
{
	ofstream outfile;
	outfile.open("data.txt", ios::app);
	outfile<<name<<' '<<sex<<' '<<tel
			<<' '<<addr<<' '<<post_code<<
			' '<<email<<' '<<qq<<' '<<group<<
			' '<<year<<' '<<mon<<' '<<day
			<<' '<<hour<<' '<<min<<' '<<sec<<'\n'; 
	outfile.close();
}

void per::del()//删除
{
	name="";
	sex="";
	tel="";
	addr="";
	email="";
	qq="";
	group="";
}

bool per::_in(string x,bool _addr=false)//检查字符串是否包含在类属性 
{
	if(name.find(x)<name.length()||name==x) return true;
	if(tel.find(x)<tel.length()||tel==x) return true;
	if(_addr=true) if(addr.find(x)<addr.length()||tel==x) return true;
	return false;
}

void per::list_show()//信息显示 
{
	if(name!=""&&sex!="")
	cout<<setiosflags(ios::left)
		<<setw(9)<<name
		<<setw(8)<<sex
		<<setw(15)<<tel
		<<setw(15)<<addr
		<<setw(10)<<post_code
		<<setw(20)<<email
		<<setw(12)<<qq
		<<setw(8)<<group
		<<endl;
}

bool per::is_set()//检测类是否被删除 
{
	if(name!=""&&sex!="") return true;
	return false;
}

string per::get_group(){
	return group;
}

char per::get_name()//获取姓名 
{
	return name[0];
}

void per::show_name()//输出姓名 
{
	cout<<setw(8)<<setiosflags(ios::left)
		<<name;
}
