#include<stdio.h>
int main()
{
    int t,s,i,count;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&s);
        for(i=1,count=0;;i++)
        {
            if(s%i==0)
            {
                if(s/i<i)
                    break;
                else if(s/i==i&&s!=1)
                {
                    count=count+s/(2*i);
                }
                else
                    count=count+s/i;
            }
            if(s/i<s)
                    break;
        }
        printf("%d\n",count);
    }
    return 0;
}
