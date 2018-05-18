#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int p=1;
char tree[100];
void print()
{
    int i,k,j,l;
    for(i=0,k=1;;i++)
    {
        //for(l=0;l<10-0.5*i*i;l++)
          //  printf(" ");
        for(j=0;j<pow(2,i);j++)
        {
            if(k>=p)
                break;
            else
            {
                printf("%c ",tree[k]);
            }
            k++;
        }
        printf("\n");
        if(k>=p)
            break;
    }
}
void insert(char x)
{
    while(tree[p/2]=='-')
    {
        tree[p]='-';
        p++;
    }
    tree[p]=x;
    p++;
    print();
}

void prefix(int x)
{
    if(tree[x]=='-')
        return;
    else
    {
        printf("%c ",tree[x]);
        prefix(2*x);
        prefix(2*x+1);
    }
}
void postfix(int x)
{
    if(tree[x]=='-')
        return;
    else
    {
        postfix(2*x);
        postfix(2*x+1);
        printf("%c ",tree[x]);
    }
}
void infix(int x)
{
    if(tree[x]=='-')
        return;
    else
    {
        infix(2*x);
        printf("%c ",tree[x]);
        infix(2*x+1);
    }
}
int main()
{
    tree[0]='*';
    char x;
    int c,i;
    for(i=1;i<100;i++)
    {
        tree[i]='-';
    }
    while(1)
    {
        printf("1.Insert\n2.Prefix\n3.Postfix\n4.Infix\n5.Exit\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:scanf("\n%c",&x);
                    insert(x);
                    break;
            case 2: prefix(1);
                    printf("\n");
                    break;
            case 3: postfix(1);
                    printf("\n");
                    break;
            case 4: infix(1);
                    printf("\n");
                    break;
            case 5: exit(0);
                    break;
        }
    }
}
