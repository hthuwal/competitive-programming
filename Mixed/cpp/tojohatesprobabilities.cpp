/** follow the pattern **/
#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int t;
    float n,m;
    scanf("%d",&t);
    while(t--){
        scanf("%f %f",&n,&m);
        printf("%0.6f\n",n+m-1);
    }
}
