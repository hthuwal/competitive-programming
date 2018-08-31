#include<iostream>
#include<list>
using namespace std;
int location[];
int frog[110000];
int main(){
    int i,j,n,k,p,a,b,c,d,flag;
    cin>>n>>k>>p;
    for(i=1;i<=n;i++){
        cin>>frog[i];
        location[frog[i]].push_back(i);
    }
    while(p--){
        cin>>a>>b;
        if(frog[a]<=frog[b]){
            c=frog[a];
            d=frog[b];
        }
        else{
            c=frog[b];
            d=frog[a];
        }
        flag=1;
        for(i=c;i<d;){
            flag=0;
            for(j=i+1;j<=i+k;j++){
                if(!location[j].empty()){
                    flag=1;
                    i=j;
                    break;
                }
            }
            if(flag==0)
                break;
        }
        if(flag==1)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
}
