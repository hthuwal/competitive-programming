#include<iostream>
#include<cstdio>
using namespace std;
float a[1100][1100];

int main(){
    int t,n,m,i,j,p,q;
    float sum;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        sum=0.0;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                a[i][j]=0.0;
            }
        }
        a[0][0]=1.0;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(i+1<n && j+1<m){
                    a[i+1][j]+=(a[i][j]*0.5);
                    a[i][j+1]+=(a[i][j]*0.5);
                }
                else if(i+1<n){
                    a[i+1][j]+=a[i][j];
                }
                else if(j+1<m){
                    a[i][j+1]+=a[i][j];
                }
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                sum+=a[i][j];
            }
        }
        printf("%0.6f\n",sum);
    }
}
