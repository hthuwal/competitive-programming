#include<iostream>
#include<set>
using namespace std;
int main()
{
	long long int i,n,ans,temp;
	multiset<long long int>hc;
	multiset<long long int>::iterator it;
	cin>>n;
	for(i=0;i<n;i++){
		ans=1;
		cin>>temp;
		hc.insert(temp);
		if(i<2)
			cout<<"-1"<<endl;
		else
		{
			it=hc.end();
			it--;
			ans*=(*it);
			it--;
			ans*=(*it);
			it--;
			ans*=(*it);
			cout<<ans<<endl;
		}
	}
}