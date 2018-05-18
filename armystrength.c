#include<stdio.h>
int main()
{
    int t,ng,nm,mng,mnm,i,temp;
    scanf("%d",&t);
    while(t--)
    {
        scanf("\n%d %d",&ng,&nm);
        for(i=0,mng=0;i<ng;i++)
        {
            scanf("%d",&temp);
            if(temp>mng)
                mng=temp;
        }
        for(i=0,mnm=0;i<nm;i++)
        {
            scanf("%d",&temp);
            if(temp>mnm)
                mnm=temp;
        }
        if(mng>=mnm)
            printf("Godzilla\n");
        else
            printf("MechaGodzilla\n");
    }
    return 0;
}
