#include<iostream>
using namespace std;
int main(){
    long long int t,n,k,count,food,eaten,i;
    cin>>t;
    while(t--){
        cin>>n>>k;
        count=1;
        food=k;
        for(i=0;i<n;i++){
            cin>>eaten;
            if(eaten<=food){
                food=food-eaten;
            }
            else{
                eaten=eaten-food;
                food=0;
                if(eaten%k==0){
                    count+=(eaten/k);
                    food=0;
                }
                else{
                    count+=((eaten/k)+1);
                    food=k-(eaten%k);
                }
            }
            if(food>0)
                food--;
        }
        cout<<count<<endl;
    }
}
