#include <iostream>
using namespace std;

int main()
{
    int t,c,n1,n5,n0,count;
    cin>>t;
    while(t--)
    {
    	count=0;
    	cin>>c>>n1>>n5>>n0;
    	while(c>0)
    	{
    		//p=8;
    		if(n0>0)
    		{
    		//	p=0;
    			count++;
    			n0--;
    			n1+=2;
    			c--;
    		}
    		else if(n5>1)
    		{
    		//	p=0;
    			count+=2;
    			n5-=2;
    			n1+=2;
    			c--;
    		}
    		else if(n5>0)
    		{
    		//	p=3;
    			n5--;
    			count+=1;
    			if(n1>2)
    			{
    		//		p=0;
    				n1-=3;
    				count+=3;
    				c--;
    			}
    			else
    			{
    				break;
    			}
    		}
    		else if(n1>7)
    		{
    		//	p=0;
    			n1-=8;
    			count+=8;
    			c--;
    		}
    	}
    	if(c==0)
    		cout<<count<<endl;
    	else
    		cout<<"-1"<<endl;
    }
}
