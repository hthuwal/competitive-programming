#include<stdio.h>
#include<math.h>
#define x 4*(atan(1))
int main()
{
    int n;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            break;
        printf("%0.2f\n",((n*n)/(2*x)));
    }
    return 0;
}
