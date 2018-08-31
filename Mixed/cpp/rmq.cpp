/**Range Minimum Query (RMQ) is used on arrays to find the position of an element
 with the minimum value between two specified indices.**/
#include <cstdio>
#include <cmath>
#define N 100
#define LOG2N 7
/**
trivial algorithms for RMQ
For every pair of indices (i, j) store the value of RMQA(i, j) in a 
table M[0, N-1][0, N-1]. 
Trivial computation will lead us to an <O(N3), O(1)> complexity. **/

/**by using an easy dynamic programming approach we can reduce the complexity 
to <O(N2), O(1)>. The preprocessing function will look something like this:**/
/**after preprocessing mat[i][j] will have the index of minimum value between 
a[i] an a[j]**/
void preprocessing1(int mat[N][N],int a[N],int n)
{
    int i,j;
    for(i=0;i<n;i++)
        mat[i][i]=i;
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
        {
            if(a[mat[i][j-1]]<a[j])
                mat[i][j]=mat[i][j-1];
            else
                mat[i][j]=j;
        }
}

/**
This trivial algorithm is quite slow and uses O(N2) memory, so it won’t work for 
large cases.
An <O(N), O(sqrt(N))> solution
An interesting idea is to split the vector in sqrt(N) pieces. We will keep in a 
vector M[0, sqrt(N)-1] the position for the minimum value for each section. 
M can be easily preprocessed in O(N).**/

/**
Sparse Table (ST) algorithm
A better approach is to preprocess RMQ for sub arrays of length 2^k using dynamic 
programming. We will keep an array M[0, N-1][0, logN] where M[i][j] is the index 
of the minimum value in the sub array starting at i having length 2^j.
So, the overall complexity of the algorithm is <O(N logN), O(1)>.**/
void preprocessing2(int m[N][LOG2N],int a[N],int n)
{
    int i,j;
    for(i=0;i<n;i++)
        m[i][0]=i;
    
    for(j=1;(1<<j)<=n;j++)
        for(i=0;i+(1<<j)-1<n;i++)
            if(a[m[i][j-1]]<a[m[i+(1<<(j-1))][j-1]])
                m[i][j]=m[i][j-1];
            else
                m[i][j]=m[i+(1<<(j-1))][j-1];
}
int getRMQ(int m[N][LOG2N],int a[N],int i,int j)
{
    int k = floor(log2(j-i+1));
    if(a[m[i][k]]<a[m[j-(1<<k)+1][k]])
        return m[i][k];
    else
        return m[j-(1<<k)+1][k];
}
int main()
{
    int rootN = (int)sqrt(N);
    int mar[N][N],u,v;
    int a[]={1,-2,0,4,2};
    preprocessing1(mar,a,5);
    scanf("%d %d",&u,&v);
    printf("%d",mar[u][v]);


    int m[N][LOG2N];
    preprocessing2(m,a,5);
    printf("%d",getRMQ(m,a,u,v));
}