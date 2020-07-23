#include <iostream>
#include <iomanip>
#include <fstream>//文件操作类 
#include <algorithm>//排序算法库 
#include "per.h"//人员类 
#include "menu.h"//菜单类 
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
per man[1000];//数据成员
void read_TXT();//读入数据
void save_TXT();//数据保存 
bool px(per a,per b);//姓名排序
void head_show();//表头 
int p=0;


int main(int argc, char** argv) {
	
	int inp_time=0;//选项输入次数 
	
	read_TXT();
	string x[]={"++++++通讯录管理系统++++++","添加通讯录成员","查询人员信息",
				"姓名排序输出人员信息","修改人员信息",
				"删除人员信息","显示所有人员信息","显示分组所有成员信息","显示成员创建时间","清屏","\0"};
	menu _menu(x);//构建菜单
	
	int _case;
	while(1)//接收菜单输入项 
	{
		if(inp_time!=0&&inp_time%3==0)
		{
			cout<<"每三次自动清屏\n";
			system("pause");
			system("cls");
		}
		_case=_menu.show();
		inp_time++;
		
		switch(_case)//选择分支 
		{
			case 1://添加成员 
			{
				man[++p]=per();
				man[p].change();
				continue;
				cout<<"添加成功!\n";
			}
			
			case 2://查询人员 
			{
				bool find=false;
				cout<<"\n请输入姓名/电话/地址查找成员信息:\n";
				string inp;//输入
				cin>>inp;
				cout<<"\n查询结果:\n";
				head_show();
				for(int i=0;i<1000;i++)
				{
					if(man[i]._in(inp,true)){
					man[i].list_show();
					find=true;
					}
				}
				if(find!=true) cout<<"未查到!";
				cout<<endl;
				continue;
			}
			
			case 3://姓名排序 
			{
				cout<<"\n姓名排序结果:\n\n";
				head_show();
				per new_man[1000];
				for(int i=0;i<1000;i++) new_man[i]=man[i];
				sort(new_man,new_man+1000,px);
				for(int i=0;i<1000;i++)
				if(new_man[i].is_set()) new_man[i].list_show();
				cout<<endl;
				continue;
			}
			
			case 4://修改信息 
			{
				bool is_find=false;//是否搜索到 
				cout<<"\n请输入姓名/电话查找成员并修改信息:\n";
				string inp;//输入
				cin>>inp;
				cout<<endl;
				
				head_show();
				for(int i=0;i<1000;i++)
				{
					
					if(man[i]._in(inp,false))
					{
						is_find=true;//查到了
						
						//显示 
						man[i].list_show();
						
						//是否修改 
						cout<<"\n是否修改?[Y/N]\n";
						char inchr;
						cin>>inchr;
						cout<<endl;
						
						//取消修改 
						if(inchr=='N'||inchr=='n')
						{
							cout<<"取消成功!\n";
							continue;
						}
						else//否则修改 
						{
							man[i].change();
							cout<<"\n修改后的结果:\n";
							head_show();
							man[i].list_show();
							cout<<"\n修改成功!\n";
							system("pause");
						}
					}
					
				}
				if(is_find==false) cout<<"\n未搜索到成员!\n"; //没找到 
				continue;
			}
			
			case 5://删除人员 
			{
				cout<<"\n请输入姓名/电话查找成员并删除信息:\n";
				bool is_find=false;//是否搜索到
				string inp;//输入
				cin>>inp;
				cout<<endl;
				head_show();
				for(int i=0;i<1000;i++)
				{	
					if(man[i]._in(inp,false))
					{
						is_find=true;
						man[i].list_show();
						cout<<"\n是否删除?[Y/N]\n";
						char inchr;
						cin>>inchr;
						if(inchr=='N'||inchr=='n')
						{
							cout<<"已取消!\n";
							continue;
						}
						else{
							man[i].del();
							cout<<"删除完成!\n";
						}
					}
				} 
				if(is_find==false) cout<<"\n未搜索到成员!\n";//没找到 
				continue;
			}
			
			case 6://全显 
			{
				cout<<endl;
				head_show();
				for(int i=0;i<1000;i++)
				if(man[i].is_set()) man[i].list_show();
				cout<<endl;
				continue;
			}
			
			case 7://分组输出 
			{
				cout<<"\n请输入组名:\n";
				string inp;
				cin>>inp;
				cout<<endl;
				head_show();
				for(int i=0;i<1000;i++)
				if(man[i].get_group()==inp) man[i].list_show();
				cout<<endl;
				continue;
			}
			
			case 8://输出创建时间 
			{
				cout<<endl;
				for(int i=0;i<1000;i++)
				if(man[i].is_set())
				{
						man[i].show_name();
						cout<<":";
						man[i].show();
				}
				cout<<endl;
				continue;
			}
			
			case 9:system("cls");continue;//清屏
			
			default:save_TXT();cout<<"即将退出!\b";break;//保存退出 
		}
	}
	
	system("pause");//屏幕暂停 
	return 0;
}

bool px(per a,per b)
{
	return a.get_name()<b.get_name();
}

void read_TXT()//读入数据
{
	ifstream infile; 
	infile.open("data.txt",ios::in);   //将文件流对象与文件连接起来 
    while (!infile.eof())
    {
    	string a,b,c,d,e,f,g,h;
    	int i,j,k,l,m,n;
    	infile>>a;
    	infile>>b;
    	infile>>c;
    	infile>>d;
    	infile>>e;
    	infile>>f;
    	infile>>g;
    	infile>>h;
    	infile>>i;
    	infile>>j;
    	infile>>k;
    	infile>>l;
    	infile>>m;
    	infile>>n;
        man[p++].auto_change(a,b,c,d,e,f,g,h,i,j,k,l,m,n);
        if(a=="\0") break;
    }
    infile.close();//关闭文件输入流 
}

void save_TXT()//保存数据
{
	ifstream tfile; 
	tfile.open("data.txt",ios::out|ios::trunc);   //将文件流对象与文件连接起来
	tfile.close();//关闭文件输入流  
    for(int i=0;i<1000;i++)
    	if(man[i].is_set()) man[i].save();
}

void head_show()
{
	cout<<setiosflags(ios::left)
		<<setw(9)<<"姓名" 
		<<setw(8)<<"性别"
		<<setw(15)<<"电话"
		<<setw(15)<<"地址"
		<<setw(10)<<"邮编"
		<<setw(20)<<"电子邮箱"
		<<setw(12)<<"QQ"
		<<setw(8)<<"组别"
		<<endl;
}
