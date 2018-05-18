#include<stdio.h>
#include<stdlib.h>
struct node{
    char x;
    int y;
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
void sort()
{
    harish *hc,*jp;
    harish temp;
    while(hc->ptr!=NULL)
    {
        jp=hc->ptr;
        while(jp->ptr!=NULL)
        {
            if(hc->y > jp->y)
            {
                temp.x=hc->x;
                temp.y=hc->y;
                hc->x=jp->x;
                hc->y=jp->y;
                jp->x=temp.x;
                jp->y=temp.y;
            }
        }
    }
}
void insert()
{
    char x;
    int y;
    harish* temp,*hc;
    temp=(harish*)malloc(sizeof(harish));
    printf("Enter element to be inserted\n");
    scanf("%c",&x);
    printf("Enter its priority");
    scanf("%d",&y);
    temp->x=x;
    temp->y=y;
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
    sort();
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
            case 1:scanf("%d",&y);
                    insert(x);
                    break;
            case 2:exit(0);
                    break;
        }
    }
}
