#include<iostream>
#include<cstring>
using namespace std;

int create(int tree[],int si, int a[],int sl,int sh)
{
	if(sl==sh)
	{
		tree[si]=a[sl];
		return tree[si];
	}
	else
	{
		int mid = (sl+sh)/2;
		tree[si]=create(tree,2*si,a,sl,mid)+create(tree,2*si+1,a,mid+1,sh);
		return tree[si];
	}
}
void update(int tree[],int si,int a[],int sl,int sh,int i)
{
	if(i<sl || i>sh)
		return;
	tree[si]+=(a[i]*(-2));
	if(sl!=sh)
	{
		int mid =(sl+sh)/2;
		update(tree,2*si,a,sl,mid,i);
		update(tree,2*si+1,a,mid+1,sh,i);
	}
}
int check(int tree[])
{
	if(tree[1]==0)
		return 1;
	return 0;
}
int main()
{
	int i,j,n,a[31000]={0},tree[65535]={0};
	char c;
	for(int t=0;t<10;t++)
	{
		cin>>n;
		memset(a,0,sizeof(a));
		memset(tree,0,sizeof(tree));
		for(j=0;j<n;j++)
		{
			cin>>c;
			if(c=='(')
				a[j]=1;
			else 
				a[j]=-1;
		}

		create(tree,1,a,0,n-1);
		cin>>i;
		cout<<"Test "<<t+1<<":"<<endl;
		while(i--)
		{
			cin>>j;
			if(j==0)
			{
				
				if(check(tree)==1)
					cout<<"YES\n";
				else 
					cout<<"NO\n";
			}
			else
			{	
				update(tree,1,a,0,n-1,j-1);
				a[j-1]=(a[j-1]*(-1));
			}
		}
	}
}

