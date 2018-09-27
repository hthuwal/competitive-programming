#include <cstdio>
#include <ctime>

void using_scanf(int &n)
{
    scanf("%d",&n);
}

int main(){
    int i,n;
    printf("\nUsing Scanf\n");
    clock_t start = clock();
    for(int i=0;i<10000000;i++)
        using_scanf(n);
    clock_t stop = clock();
    printf("Time taken : %lf\n",(double)(stop-start)/CLOCKS_PER_SEC);
}