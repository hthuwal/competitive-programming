#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define x 250
int knapsack(int k,int n,char hc[])
{
	int jp[n+1][k+1],i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=k;j++)
		{
			if(i==0 || j==0)
				jp[i][j]=0;
			else
				jp[i][j]=max(int(hc[i-1])+jp[i-1][j-1],jp[i-1][j]);
		}
	}
	return jp[n][k];
}
int lcs(char a[],char b[], int n,int m,int k)
{

	int l[n+1][m+1];
	int i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			if(i==0 || j==0)
			{
				l[i][j]=0;
			}
			else if(a[i-1]==b[j-1])
			{
				l[i][j]=l[i-1][j-1]+1;
			}
			else
			{
				l[i][j]=max(l[i-1][j],l[i][j-1]);
			}
		}
	}
	int index = l[n][m];
	char hc[index+1];
	i=n;j=m;
	hc[index]='\0';
	while(i>0 && j>0)
	{
		if(a[i-1]==b[j-1])
		{
			hc[index-1]=a[i-1];
			i--;j--;index--;
		}
		else if(l[i-1][j]>l[i][j-1])
			i--;
		else
			j--;
	}
	if(k<=l[n][m])
        return knapsack(k,l[n][m],hc);
    else
        return 0;
}

int main()
{
    char a[x],b[x];
    int t,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",a);
        scanf("%s",b);
        scanf("%d",&k);
        cout<<lcs(a,b,strlen(a),strlen(b),k)<<endl;
    }
}
