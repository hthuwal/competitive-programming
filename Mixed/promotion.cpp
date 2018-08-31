#include<iostream>
#include<set>
using namespace std;
int main(){
	long long int temp,n,ans=0,k;
	multiset<long long int> hc;
	multiset<long long int>::iterator itlow,itup;
	cin>>n;
	while(n--){
		cin>>k;
		while(k--){
			cin>>temp;
			hc.insert(temp);
		}
		itlow=hc.begin();
		itup=hc.end();
		itup--;
		ans+=(*itup)-(*itlow);
		hc.erase(itup);
		hc.erase(itlow);
	}
	cout<<ans;
}
