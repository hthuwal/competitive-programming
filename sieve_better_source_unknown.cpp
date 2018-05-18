#include <cstdio>
#include <vector>
#include <ctime>
using namespace std;
#define N 100000009

int prime_arr[N]={0};
vector<int> prime;

void find_all_primes () {
	long long i , j , i2 ;
	for( i = 3 ; i <= 9999 ; i += 2 ) { //9999 is sqrt(MAX)
		while( prime_arr[i] == 1 )
			i += 2;
		j = i*(i-2);
		i2 = i << 1 ;
		while( ( j = i2 + j ) <= N )
			prime_arr[j] = 1;
	}
	
	for( i = 3 ; i <= N ; i += 2 ){
		if( prime_arr[i] ==0){
			prime.push_back(i) ;
		}
		//cout << len <<"\n";			//5761454
	}
	printf("%ld\n",prime.size());
}

int main()
{
    clock_t start = clock();
    segmented_sieve();
    clock_t stop = clock();
    printf("Time taken : %lf\n",(double)(stop-start)/CLOCKS_PER_SEC);

    printf("Few primes are:\n");
    for(int i=0;i<100;i++)
        printf("%d ",prime[i]);
    printf("\n");
}

