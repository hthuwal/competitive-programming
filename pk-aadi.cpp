#include<iostream>
#define x 1000000007
using namespace std;
class matrix
{
	private:
		long long int a[26][26];
	public:
		matrix()
		{
			for(long long int i=0;i<26;i++)
				for(long long int j=0;j<26;j++)
					a[i][j]=0;
		};
		void input()
		{
			for(long long int i=0;i<26;i++)
				for(long long int j=0;j<26;j++)
					cin>>a[i][j];
		}
		void append(long long int i,long long int j,long long int y)
		{
			this->a[i][j]+=(y%x);
		}
		long long int get(long long int i,long long int j)
		{
			return this->a[i][j];
		}
		matrix mul(matrix b)
		{
			matrix c;
			for(long long int i=0;i<26;i++)
				for(long long int j=0;j<26;j++)
					for(long long int k=0;k<26;k++)
					{
						long long int p,q,r;
						p=this->get(i,k);
						q=b.get(k,j);
						r=((p%x)*(q%x))%x;
						c.append(i,j,r);
					}

			return c;
		}
};
matrix power(matrix a,long long int n)
{
	if(n==1)
		return a;
	matrix b=power(a,n/2);
	if(n%2==0)
		return b.mul(b);
	else
		return (b.mul(b)).mul(a);
}
int main()
{
	long long int t,l,ans;
	char c;
	matrix hc;
	hc.input();
	cin>>t;
	while(t--)
	{
		cin>>c>>l;
		matrix jp = power(hc,l-1);
		ans=0;
		for(long long int i=0;i<26;i++)
		{
			ans+=(jp.get(i,c-'a'))%x;
			ans=ans%x;
		}
		cout<<ans<<endl;
	}
}