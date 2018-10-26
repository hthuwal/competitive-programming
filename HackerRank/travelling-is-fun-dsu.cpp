/**
 * https://www.hackerrank.com/contests/hack-it-to-win-it-paypal/challenges/q4-traveling-is-fun/problem
 *
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 200005

int parent[N];
int size[N];

int find(int a)
{
    if(parent[a] == a)
        return a;
    return parent[a] = find(parent[a]);
}

void uni(int a, int b)
{
    int pa = find(a);
    int pb = find(b);
    if(pa != pb)
    {
        if(size[pa] < size[pb])
            swap(pa, pb);
        parent[pb] = pa;
        size[pa] += size[pb];
    }
}

// could have used __gcd instead (same result)
int gcd(int a, int b)
{
    int r;
    while(b!=0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int n,g,t;
    scanf("%d %d %d",&n,&g, &t);
    for(int i=1;i<=n;i++)
    {
        parent[i] = i;
        size[i] = 1;
    }

    // No need to find gcd of every pair of numbers
    
    // Let x be a number greater than g
    // Let y be a multiple of x i.e. y = k*x
    // There gcd will always be = x > g
    
    // Therefore all numbers greater than g and their multiples
    // are connected
    // O(n)
    for(int i = g+1;i<=n;i++)
        for(int j=i;j<=n;j+=i)
            // if(gcd(i, j) > g)
                uni(i, j);
    
    vector<int> start(t, 0);
    for(int i=0;i<t;i++)
        scanf("%d",&start[i]);

    scanf("%d", &t);
    vector<int> end(t, 0);
    for(int i=0;i<t;i++)
        scanf("%d",&end[i]);
    
    for(int i=0;i<t;i++)
    {
        if(find(start[i]) == find(end[i]))
            printf("1\n");
        else
            printf("0\n");
    }
    return 0;
}
