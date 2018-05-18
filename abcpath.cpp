#include <iostream>
#include <cstdio>
using namespace std;
int max(int a,int b)
{
	if(a>b)
		return a;
	else 
		return b;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int h,w;
	int t=0;
	while(1)
	{
		t++;
		cin>>h>>w;
		if(h==0 && w==0)
			break;
		char hc[51][51];
		for(int i=0;i<h;i++)
		{
			scanf("%s",hc[i]);
		}
		
		int jp[51][51];
		
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
				jp[i][j]=1;

		for(int k=1;k<26;k++)
		{
			char c = 'Z'-k;
			for(int i=0;i<h;i++)
				for(int j=0;j<w;j++)
					if(hc[i][j]==c)
					{
						int x = jp[i][j];
						if(i-1>=0 && hc[i-1][j]==c+1)
						{
							jp[i][j]=max(jp[i][j],x+jp[i-1][j]);
						}
						if(i-1>=0 && j-1>=0 && hc[i-1][j-1]==c+1)
						{
							jp[i][j]=max(jp[i][j],x+jp[i-1][j-1]);
						}
						if(i-1>=0 && j+1<w && hc[i-1][j+1]==c+1)
						{
							jp[i][j]=max(jp[i][j],x+jp[i-1][j+1]);
						}
						if(j-1>=0 && hc[i][j-1]==c+1)
						{
							jp[i][j]=max(jp[i][j],x+jp[i][j-1]);
						}
						if(j+1<w && hc[i][j+1]==c+1)
						{
							jp[i][j]=max(jp[i][j],x+jp[i][j+1]);
						}
						if(i+1<h && hc[i+1][j]==c+1)
						{
							jp[i][j]=max(jp[i][j],x+jp[i+1][j]);
						}
						if(i+1<h && j-1>=0 && hc[i+1][j-1]==c+1)
						{
							jp[i][j]=max(jp[i][j],x+jp[i+1][j-1]);
						}
						if(i+1<h && j+1<w && hc[i+1][j+1]==c+1)
						{
							jp[i][j]=max(jp[i][j],x+jp[i+1][j+1]);
						}
					}
		}
		int ans=0;
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
				if(hc[i][j]=='A')
					ans=max(ans,jp[i][j]);
		cout<<"Case "<<t<<": "<<ans<<"\n";
	}
}