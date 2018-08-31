#include<stdio.h>
char stack[100];
top=-1;
void print()
{
    int i;
    printf("\nstack\n");
    for(i=top;i>=0;i--)
    {
        printf("||\t%c\t||\n",stack[i]);
    }
}
void push(char x)
{
    top++;
    if(top>=10)
    {
        printf("Stack full");
        return;
    }
    else
    {
        stack[top]=x;
    }
    print();
}
void pop()
{
    if(top==-1)
    {
        printf("Stack Empty");
    }
    else
    {
        top--;
    }
    print();
}
int main()
{
    int c;
    char x;
    while(1)
    {
        printf("1.push\n2.pop\n3.exit\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:scanf("\n%c",&x);
                    push(x);
                    break;
            case 2:pop();
                    break;
            case 3:exit(0);
                    break;
        }
    }
}
