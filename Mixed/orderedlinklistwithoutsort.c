#include<stdio.h>
#include<stdlib.h>
struct node{
    char x;
    int y;
    struct node* ptr;
};
typedef struct node harish;
harish *start;
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
    harish *hc,*temp,*jp;
    temp=(harish *)malloc(sizeof(harish));
    printf("Enter the element\n");
    scanf("\n%c",&temp->x);
    printf("Enter priority\n");
    scanf("%d",&temp->y);
    temp->ptr=NULL;
    if(start==NULL)
        start=temp;
    else if(temp->y < start->y)
    {
        temp->ptr=start;
        start=temp;
    }
    else
    {
        jp=start;
        hc=start->ptr;
        while(hc!=NULL)
        {
            if(hc->y > temp->y)
                break;
            hc=hc->ptr;
            jp=jp->ptr;
        }
        jp->ptr=temp;
        temp->ptr=hc;
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
            case 1:insert();
                    break;
            case 2:exit(0);
                    break;
        }
    }
}
