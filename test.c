    #include <stdio.h>
    int a[1000000];

    int main()
    {
        int i,j,t,n,m,flag,count,x,y,temp;
        for(i=2;i<1000000;i++)
        {
            a[i]=i;
        }
        for(i=2;i<=sqrt(1000000);i++)
        {
            if(a[i]!=0)
            {
                for(j=i*i;j<1000000;j++)
                {
                    if(a[j]%i==0)
                    {
                        a[j]=0;
                    }
                }
            }
        }
        scanf("%d",&t);
        while(t--)
        {
            scanf("%d %d",&m,&n);
            if(m==1)
                m++;

            for(i=m,count=0;i<=n;i++)
            {
                for(j=2,flag=1;j<=sqrt(i);j++)
                {
                    if(a[j]!=0)
                    {
                        if(i%a[j]==0)
                        {
                            flag=0;
                            break;
                        }
                    }
                }
                if(flag==1)
                {
                	x=i;
                	y=0;
                	while(x!=0)
                	{
                		temp=x%10;
                		if(temp==2||temp==3||temp==5||temp==7)
                			y++;
                        x=x/10;
                	}
                	if(y==2||y==3||y==7||y==11|y==13)
                		count++;
                }
            }
            printf("%d\n",count);
        }
        return 0;
    }
