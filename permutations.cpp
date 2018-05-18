#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    long long int a[13][100],i,j,d,n,k;

    for(i=0;i<13;i++)
        for(j=0;j<100;j++)
        a[i][j]=0;

   a[1][0]=1;
   for(i=1;i<13;i++)
   {
        for(j=0;j<100;j++) //adding a new integer n to the permutation of length n-1 to can increase the number of inversions by 0,1,2,3....n-1 when added
                            //at the last, second last,....,first position respectively
                            // so if we need to find the "m" inversions wali "n" length ki permutaion that is a[n][m]
                            // it would be equal to = a[n-1][m]+a[n-1][m-1]+....a[n-1][m-r].....a[n-1][m-(n-1)]////m-r>=0
        {
            for(k=0;k<i;k++){
                if(j-k>=0){
                    a[i][j]+=a[i-1][j-k];
                }
                else
                break;
            }
        }
   }
   cin>>d;
   while(d--){
        cin>>n>>k;
        cout<<a[n][k]<<endl;
   }
}
