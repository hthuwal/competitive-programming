#include<stdio.h>
#include<stdlib.h>
struct node{
    char x;
    struct node* ptr;
};
typedef struct node harish;
harish* start=NULL;
void print()
{
    harish* hc;
    hc=start;
    while(hc!=NULL)
    {
        printf("%c ",(hc->x));
        hc=hc->ptr;
    }
    printf("\n");
}
void insert()
{
    char x;
    harish* temp,*hc;
    temp=(harish*)malloc(sizeof(harish));
    printf("Enter element to be inserted\n");
    scanf("%c",&x);
    temp->x=x;
    temp->ptr=NULL;
    if(start==NULL)
        start=temp;
    else
    {
        hc=start;
        while(hc->ptr!=NULL)
        {
            hc=hc->ptr;
        }
        hc->ptr=temp;
    }
    print();
}
void main()
{
    int x,y;
    while(1)
    {
        printf("1.Insert\n2.Exit\n");
        scanf("%d",&x);
        switch(x)
        {
            case 1: insert();
                    break;
            case 2:exit(0);
                    break;
        }
    }
}
