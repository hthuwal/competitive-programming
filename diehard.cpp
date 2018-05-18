#include<iostream>
using namespace std;
int play(int h,int a,char s)
{
	if(s=='s' || s=='w' || s=='f')
	{
		return play(h+3,a+2,'a')+1;
	}
	else
	{
		if((h-5<=0 || a-10<=0) && (h-20<=0))
			return 0;
		else if(h-5>0 && a-10>0)
			return play(h-5,a-10,'w')+1;
		else if(h-20>0)
			return play(h-20,a+5,'f')+1;
		else
			return max(play(h-5,a-10,'w'),play(h-20,a+5,'f'))+1;
	}
}
int main()
{
	int t,h,a;
	cin>>t;
	while(t--)
	{
		cin>>h>>a;
		cout<<play(h,a,'s')<<endl<<endl;
	}
}