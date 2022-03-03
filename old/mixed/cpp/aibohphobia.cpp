/*The number of insertions equals to the length of the string minus LCS(longest common subsequence) of the given string and the reversed string of the given string.
formula
answer=n - LCS( string, reversed string)*/

#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
/* Following steps build L[m+1][n+1] in bottom up fashion. Note
      that l[i][j] contains length of lcx of a[0..i-1] and b[0..j-1] */
int lcs(char a[],char b[],int n, int m)
{
    int l[2][n+1],i,j,k;
    for(i=0;i<=n;i++)
    {
        l[0][i]=0;
        l[1][i]=0;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(i==0 || j==0)
                l[i][j]=0;
            else if(a[i-1]==b[j-1])
                l[1][j]=1+l[0][j-1];
            else
                l[1][j]=max(l[0][j],l[1][j-1]);
        }
        for(k=0;k<=m;k++)
        {
            l[0][k]=l[1][k];
        }
    }
    return l[0][m];
}
int main()
{
    int t,i,n,ans;
    char a[6200],b[6200];
    cin >> t;
    while(t--)
    {
        scanf("%s",a);
        n=strlen(a);
        for(i=0;i<n;i++)
        {
            b[n-i-1]=a[i];
        }
        ans=lcs(a,b,n,n);
        cout<<n-ans<<endl;
    }
    return 0;
}
