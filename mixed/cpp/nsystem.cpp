#include <cstdio>
int mcxitoint(char a[])
{
    int place=1,ans=0;
    for(int i=0;a[i]!='\0';i++)
    {
        if(a[i]>='2' && a[i]<='9')
            place = a[i]-'0';
        else 
        {
            switch(a[i])
            {
                case 'm':ans+=(place*1000);
                         break;
                case 'c':ans+=(place*100);
                         break;
                case 'x':ans+=(place*10);
                         break;
                case 'i':ans+=place;
                         break;
            }
            place=1;
        }
    }
    return ans;
}
int intomcxmi(int a)
{
    char ans[50];
    int t,ptr=0;
    t=a%10;
    if(t!=0)
    {
        ans[ptr++]='i';
        if(t>1)
            ans[ptr++]='0'+t;
    }
    a=a/10;
    t=a%10;
    if(t!=0)
    {
        ans[ptr++]='x';
        if(t>1)
            ans[ptr++]='0'+t;
    }
    a=a/10;
     t=a%10;
    if(t!=0)
    {
        ans[ptr++]='c';
        if(t>1)
            ans[ptr++]='0'+t;
    }
    a=a/10;
     t=a%10;
    if(t!=0)
    {
        ans[ptr++]='m';
        if(t>1)
            ans[ptr++]='0'+t;
    }
    for(int i=ptr-1;i>=0;i--)
        printf("%c",ans[i]);
    printf("\n");
}
int main()
{
    freopen("in.txt","r",stdin);
    int t;
    char a[50],b[50];
    for(scanf("%d",&t);t--;)
    {
        scanf("%s %s",a,b);
        intomcxmi(mcxitoint(a)+mcxitoint(b));
    }
}