#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	int t;
	string hc;
	cin>>t;
	while(t--)
	{
		cin>>hc;
		int count=0,op[1000000],i,count2=0,sum;
		int len=hc.length();
		for(i=0;i<len;i++)
		{
            if(hc[i]=='X')
                count++;
            else if(hc[i]=='B')
                count2++;
		}
        for(i=0;i<count;i++)
        {
            cin>>op[i];
        }
        sort(op,op+count);
        for(i=count-1,sum=0;i>=count2;i--)
        {
            sum+=op[i];
        }
        cout<<sum<<endl;
    }
}
