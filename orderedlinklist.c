#include<stdio.h>
#include<stdlib.h>
struct node{
char x;
int y;
struct node *ptr;
};
typedef struct node harish;
harish *start=NULL;
void sort()
{
    char c;
    int y;
    harish *hc,*jp;
    hc=start;
    while(hc!=NULL)
    {
        jp=start;
        while(jp!=NULL)
        {
            if(hc->y < jp->y)
            {
                c=hc->x;
                y=hc->y;
                hc->x=jp->x;
                hc->y=jp->y;
                jp->x=c;
                jp->y=y;
            }
            jp=jp->ptr;
        }
        hc=hc->ptr;
    }
}
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
    hc=start;
    while(hc!=NULL)
    {
        printf("%d ",(hc->y));
        hc=hc->ptr;
    }
    printf("\n");

}
void insert()
{
    char x;
    int y;
    harish* temp,*hc;
    temp=(harish*)malloc(sizeof(harish));
    printf("Enter element to be inserted\n");
    scanf("\n%c",&x);
    printf("Enter elements priority");
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
            case 1:insert();
                    break;
            case 2:exit(0);
                    break;
        }
    }
}
