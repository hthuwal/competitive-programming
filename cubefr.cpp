#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#define X 110
using namespace std;
int prime[X];
int cf[1100000];
vector<int> cubefree;
void generate_primes()
{
    for(int i=0;i<X;i++)
        prime[i]=i;
    for(int i=2;i<X;i++)
    {
        if(prime[i]!=0)
        {
            for(int j=i+i;j<X;j+=i)
            {
                prime[j]=0;
            }
        }
    }
}
void generate_cubefree()
{
    for(int i=1;i<1100000;i++)
        cf[i]=1;
    /**
     * all no. of form prime^(3) are not cube free
     * making cf[prime^(3)]=0;
     */
    for(int i=2;i<110;i++)
    {
        if(prime[i]!=0)
        {
            int k=i*i*i;
            if(k<=1100000)
            {
                cf[k]=0;
            }
        }
    }
    /**
     * marking multiples of non cube free as non cube fee
     */
    for(int i=2;i<1100000;i++)
    {
        if(cf[i]==0)
        {
            for(int j=i+i;j<1100000;j+=i)
            {
                cf[j]=0;
            }
        }
    }
    /**
     * saving index of cube free numbers
     */
    int count=1;
    for(int i=2;i<1100000;i++)
    {
        if(cf[i]!=0)
        {
            count++;
            cf[i]=count;
        }
    }
}
int main()
{
	#ifndef ONLINE_JUDGE
    	freopen("in.txt", "r", stdin);
	#endif
    generate_primes();
    generate_cubefree();
    // for(int i=0;i<500;i++)
    // {
    //     if(cf[i]!=0)
    //         cout<<cf[i]<<"\t:\t"<<i<<endl;
    // }
    int t,n,i;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cout<<"Case "<<i<<": ";
        cin>>n;
        if(cf[n]==0)
            cout<<"Not Cube Free\n";
        else
            cout<<cf[n]<<"\n";
    }
    
}