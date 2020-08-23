#include<iostream>
#include<set>
using namespace std;
int main(){
	int q,a,b;
	multiset<int> hc;
	multiset<int>::iterator it;
	cin>>q;
	while(q--){
		cin>>a;
		switch(a)
		{
			case 1: 
				cin>>b;
				hc.insert(b);
				break;
			case 2:
				cin>>b;
				it=hc.find(b);
				if(it==hc.end())
					cout<<"-1"<<endl;
				else
					hc.erase(it);
				break;
			case 3:
				if(hc.empty())
					cout<<"-1"<<endl;
				else{
					it=hc.end();
					it--;
					cout<<(*it)<<endl;
				}
				break;
			case 4:
				if(hc.empty())
					cout<<"-1"<<endl;
				else{
					it=hc.begin();
					cout<<(*it)<<endl;
				}
				break;
		}
	}
}