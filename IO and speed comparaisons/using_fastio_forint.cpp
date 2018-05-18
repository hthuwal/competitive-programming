#include <cstdio>
#include <ctime>

inline void fastscan(int &x)
{  
    register char c=0;
    while (c<33) c=getchar_unlocked();
    x=0;
    while (c>33)
    {
        x=x*10+c-'0';
        c=getchar_unlocked();
    }
}

int main(){
    int i,n;
    printf("\nUsing Fattscan\n");
    clock_t start = clock();
    for(int i=0;i<10000000;i++)
        fastscan(n);
    clock_t stop = clock();
    printf("Time taken : %lf\n",(double)(stop-start)/CLOCKS_PER_SEC);
    printf("%c",33);
}