#include <iostream>
#include <cstdio>
using namespace std;
bool is historic(string a,string b,int p,int q)
{
    
}
int main()
{
    int t;
    string a,b;
    for(scanf("%d",&t);t--;)
    {
        cin>>a>>b;
        if(a.length()==b.length())
        {
            int hash[26]={0};
            int flag=1;
            for(int i=0;i<a.length();i++)
            {
                if(a[i]==b[i])
                    hash[a[i]-'a']=a[i]-'a'+1;
                else
                {
                    if(hash[b[i]-'a']!=0)
                    {
                        printf("NO\n");
                        flag=0;
                        break;
                    }
                    else if(hash[a[i]-'a']==0)
                        hash[a[i]-'a']=b[i]-'a'+1;
                    else if(hash[a[i]-'a']!=b[i]-'a'+1)
                    {
                        printf("NO\n");
                        flag=0;
                        break;
                    }
                }
            }
            if(flag==1)
                    printf("YES\n");
        }
        else
            printf("NO\n");

        
    }
}