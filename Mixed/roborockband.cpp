#include <iostream>
#include <cstdio>
#include <algorithm>
#include <ctime>
#define f(i,a,b) for(int i=a;i<b;i++)
// #define mul(a,b) ((a%MOD)*(b%MOD))%MOD
#define MOD 1000000007

int hc[1100000]={0};
int jp[1100000]={0};
clock_t start,end;

using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int a[1100],c[1100],d[1100];
	int b[1100],T,n,k;
	long long int count;

	start =clock();
	cin>>T;
	f(t,1,T+1)
	{
		cout<<"Case #"<<t<<": ";
		cin>>n>>k;

		f(i,0,n)
			cin>>a[i];
		f(i,0,n)
			cin>>b[i];
		f(i,0,n)
			cin>>c[i];
		f(i,0,n)
			cin>>d[i];

		int p=0;
		f(i,0,n)
			f(j,0,n)
				{
					hc[p]=a[i]^b[j];
					p++;
				}

		p=0;
		f(i,0,n)
			f(j,0,n)
				{
					jp[p]=c[i]^d[j];
					p++;
				}

		sort(jp,jp+p);
		count=0;
		// f(i,0,p)
		// 	cout<<hc[i]<<" ";
		// cout<<endl;
		// f(i,0,p)
		// 	cout<<hc[i]<<" ";

		f(i,0,p)
		{
			int y = hc[i]^k;
			int *l = lower_bound(jp,jp+p,y);
			if(*l==y)
			{
				int *h = upper_bound(jp,jp+p,y);
				count+=(h-l);
			}
		}
		cout<<count<<"\n";
	}
	end =clock();
	cout<<(double)(end-start)/CLOCKS_PER_SEC;
}