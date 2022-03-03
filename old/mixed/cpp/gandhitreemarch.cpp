#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	char a[11111];
	int n,i,p,t;
	vector<char>hc;
	cin>>t;
	while(t--){
		scanf("%d %s",&n,a);
		hc.clear();
		for(i=0,p=0;i<strlen(a);i++){
            if(i>0)
            {
                if(a[i]=='('){

                }
            }

		}
		sort(hc.begin(),hc.end());
		if(hc.empty()){
			cout<<"Common Gandhijee!";
		}
		else
		{
		for(i=0;i<hc.size();i++)
			cout<<hc[i];
		}
		cout<<endl;
	}
}
