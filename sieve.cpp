/**
Time Complexity = O(N(log(log(N))))
**/
#include <cstdio>
#include <vector>
#include <ctime>
using namespace std;
#define N 100000009

int prime_arr[N]={0};
vector<int> prime;

void sieve()
{
    prime.push_back(2);
    for(int i=3; i*i <= N; i+=2)
    {
        if(prime_arr[i]==0)
        {
            for(int j = i+i ;j<= N; j+=i)
                prime_arr[j]=1;
        }
    }
    for(int i=3;i<N;i+=2)
    {
        if(prime_arr[i]==0)
            prime.push_back(i);
    }
}

int main()
{
    clock_t start = clock();
    sieve();
    clock_t stop = clock();
    printf("Time taken : %lf\n\n",(double)(stop-start)/CLOCKS_PER_SEC);
    printf("Number of primes : %ld\n",prime.size());
    printf("Few primes are:\n");
    for(int i=0;i<100;i++)
        printf("%d ",prime[i]);
    printf("\n");
}

