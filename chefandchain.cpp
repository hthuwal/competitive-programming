#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int t,i;
    string hc;
    scanf("%d",&t);
    while(t--)
    {
        char a = '-';
        char b = '+';
        char temp;
        int count1=0,count2=0;
        cin>>hc;
        for(i=0;i<hc.length();i++)
        {
            if(hc[i]!=a)
                count1++;
            if(hc[i]!=b)
                count2++;
            temp=a;
            a=b;
            b=temp;
        }
        printf("%d\n",min(count1,count2));
    }
    return 0;
}
