#include<iostream>
#include<cstdio>
using namespace std;
string a;
string b;
int main()
{
    int m,i,j,n;
    while(scanf("%d",&m)!=EOF)
    {
        scanf("%s",a);
        int prefix[m]={0};
        i=0;
        for(j=2;j<=m;j++)
        {
                while(i>0 && a[i]!=a[j-1])
                {
                    i=prefix[i];
                }
                if(a[i]==a[j-1])
                {
                    i++;
                }
                prefix[j-1]=i;
        }
        i=0;
        j=0;
        char b;
        cin.ignore();
        while(1)
        {
            scanf("%c",&b);
            if(b=='\n')
                break;
            j++;
            while(i>0 && a[i]!=b)
            {
                i=prefix[i];
            }
            if(a[i]==b)
            {
                i=i+1;
            }
            if(i==m)
            {
                printf("%d\n",j-m);
                i=prefix[i-1];
            }
        }
        printf("\n");
    }
}
