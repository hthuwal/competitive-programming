#include <bits/stdc++.h>
using namespace std;

#define p pair<int,int>
/**
 * @param  r  [no. of rows]
 * @param  c  [no. of cols]
 * @param  m  [choohe ki positions]
 * @param  c1 [pehli billi ki position]
 * @param  c2 [dusri billi ki position]
 * returns 1 if mouse can escape
 */
int check(int r,int c,p m,p c1,p c2)
{
	p left,right,top,niche;

	if(c1.first<c2.first)
	{
		left = c1;
		right = c2;
	}
	else
	{
		left = c2;
		right =c1;
	}
	if(c1.second<c2.second)
	{
		top = c1;
		niche = c2;
	}
	else
	{
		top = c2;
		niche =c1;
	}

	p disfromc1 = make_pair(c1.first-m.first,c1.second-m.second);//choohe ka pehli cat se distance x and y coordinate 
	p disfromc2 = make_pair(c2.first-m.first,c2.second-m.second);//choohe ka dusri cats se distance x and y coordinate 
	
	int a = disfromc1.first * disfromc2.first; 
	int b = disfromc1.second * disfromc2.second;

	if(a <= 0 && b <= 0) // agar chooha dono cats ke beech main hai
	{
		if(    abs(top.second-m.second) < abs(top.first-m.first) // jitni der main chooha upar bhagne ki koshish kare tab tak upar wali uske barabar aa payegit?
			|| abs(m.second-niche.second) < abs(m.first-niche.first)
			|| abs(m.first-left.first) < abs(m.second-left.second)
			|| abs(right.first-m.first) < abs(right.second-m.second)
		  )
			return 1;
		else
			return 0;
	}
	else
		return 1;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif

	int n,m,t,a,b,c,d,e,f;
	cin>>n>>m;
	cin>>t;

	while(t--)
	{
		cin>>a>>b>>c>>d>>e>>f;
		int x = check(n,m,make_pair(b,a),make_pair(d,c),make_pair(f,e));
		if(x==1)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}