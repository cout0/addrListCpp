#include "menu.h"
#define star "-"//꽉데輕념 
#define line 40//꽉데낀똑 
#define _space 20//璘긋약잼 
void _show()//왕목鞫刻변鑒
{
	for(int i=0;i<=_space;i++) cout<<' ';
}

menu::menu(string *_p)//꽉데淃커뭐芚 
{
	menu::p=_p;
}

int menu::show()//럿쀼꽉데朞淃 
{
	int x=0;
	string str=*(p+x);
	
	_show();
	for(int i=0;i<=line;i++) cout<<star;
	cout<<endl;
	
	int len=20;len/=2;
	
	//꽉데깃痙迦 
	for(int i=0;i<=_space;i++) cout<<' ';
		for(int i=0;i<len-2;i++) cout<<star;
		cout<<str;
		for(int i=0;i<line+3-len-str.length();i++) cout<<star;
		cout<<endl;
		x++;
		str=*(p+x);
	//꽉데깃痙棺 
	
	do//꽉데淃커渴놔 
	{
		for(int i=0;i<=_space;i++) cout<<' ';
		for(int i=0;i<len;i++) cout<<star;
		cout<<x++<<'.'<<str;
		for(int i=0;i<line-1-len-str.length();i++) cout<<star;
		cout<<endl;
		
		str=*(p+x);
	}while(str!="\0");
	
		//0.藁놔迦 
		for(int i=0;i<=_space;i++) cout<<' ';
		for(int i=0;i<len;i++) cout<<star;
		cout<<0<<'.'<<"藁놔";
		for(int i=0;i<line-5-len;i++) cout<<star;
		cout<<endl;
		//0.藁놔棺 
	
	_show();
	for(int i=0;i<=line;i++) cout<<star;
	cout<<endl;
	
	cout<<"헝渴흙꽉데朞淃:\n"; 
	cin>>x;//渴흙朞淃令 
	return x;
}
