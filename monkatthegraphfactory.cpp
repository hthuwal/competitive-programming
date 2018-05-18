 /***in a graph sum of degree of all vertices == 2*number of edges
     also for a tree if number of vertices is n then the number of edges is n-1***/
#include <iostream>
using namespace std;

int main()
{
	int n,sum,temp,i;
    cin>>n;
    for(i=0,sum=0;i<n;i++){
    	cin>>temp;
    	sum+=temp;
    }
    if(sum==2*(n-1))
    	cout<<"Yes"<<endl;
    else
    	cout<<"No"<<endl;
}
