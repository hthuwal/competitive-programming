#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int t,jp,am;
	string hc;
	cin>>t;
	cin.ignore();
	while(t--){
		getline(cin,hc);
		if(hc.length()==5 && hc[2]=='-' && hc[0]>='a' && hc[0]<='h' && hc[3]>='a' && hc[3]<='h' && hc[1]>='1' && hc[1]<='8' && hc[4]>='1' && hc[4]<='8'){
			jp = abs(int(hc[0]-hc[3]));
			am = abs(int(hc[1]-hc[4]));
			if((jp==2 && am==1)||(jp==1 && am==2)){
				cout<<"Yes"<<endl;
			}
			else
			{
				cout<<"No"<<endl;
			}
		}
		else
			cout<<"Error"<<endl;
	}
}
