#include <iostream>
#include <algorithm>
using namespace std;
 
int main()
{
	int t,n,m,boy[11000],girl[11000],i,j,flag;
	cin>>t;
	while(t--)
	{
	    cin>>m>>n;
	    for(i=0;i<m;i++)
	    	cin>>boy[i];
	    for(i=0;i<n;i++)
	    	cin>>girl[i];
	    if(n<m)
	    {
	    	cout<<"NO"<<endl;
	    	continue;
	    }
	   	sort(boy,boy+m);
	   	sort(girl,girl+n);
	   	// for(i=0;i<n;i++)
	   	// 	cout<<girl[i]<<" ";
	   	// cout<<endl;
	   	// for(i=0;i<m;i++)
	   	// 	cout<<boy[i]<<" ";	
	   	for(i=0,j=0,flag=1;i<m &&j<n;i++,j++)
	   	{
	   		if(boy[i]<=girl[j])
	   		{
	   			flag=0;
	   			break;
	   		}
	   	}
	   	if(flag==1)
	   		cout<<"YES"<<endl;
	   	else
	   		cout<<"NO"<<endl;
	}   	
}	