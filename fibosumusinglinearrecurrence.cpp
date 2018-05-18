/** S[i] denotes sum upto nthe fibonacci number

    S[i]=S[i-1]+S[i-2]+1

    using matrix exponentiation method for programming above recurrence relation

    |0 1 0|   | S[i] |     | S[i+1] |
    |1 1 1| * |S[i+1]|  =  | S[i+2] |
    |0 0 1|   |   1  |     |   1    |

    T * Fi = Fi+1

    F0 will be

    |0|
    |1|
    |0|     as S[0]=0,S[1]=1

    now Fn = T^(n) * F0;
	S[n] is given by the first element of Fn
    **/

/** Refer http://fusharblog.com/solving-linear-recurrence-for-programming-contest/ **/

#include<iostream>
#include<vector>
const long long int mod = 1000000007;
using namespace std;
#define loop(i,n) for (int i=0;i<n;i++)

typedef vector < vector<long long int> > harish;

/** Function to perform Multiplication of Matrices**/
harish multiply(harish a, harish b)
{
    harish c(3,vector<long long int>(3));
    loop(i,3)
    loop(j,3)
    {
    c[i][j]=0;
    loop(k,3)
        c[i][j]=(c[i][j]%mod+((a[i][k]%mod)*(b[k][j]%mod))%mod)%mod;
    }
    return c;
}

/** Function to calculate power of a matrix **/

harish power(harish a, long long int p)
{
    if(p==1)
        return a;
    else if(p%2==1)
        return multiply(a,power(a,p-1));
    else
    {
        harish x = power(a,p/2);
        return multiply(x,x);
    }
}

/** Function to evaluate sum upto nth fibonacci numbers**/
long long int sum(long long int n)
{
    vector<long long int> f(3);
    f[0]=0;
    f[1]=1;
    f[2]=1;
    harish T(3,vector<long long int>(3));
    T[0][0]=0;T[0][1]=1;T[0][2]=0;
    T[1][0]=1;T[1][1]=1;T[1][2]=1;
    T[2][0]=0;T[2][0]=0;T[2][2]=1;

    if(n==0)
        return T[0][0];
    else
        T = power(T,n);

    int result;
    result=0;
    loop(i,3)
        result=(result%mod+((T[0][i]%mod)*f[i]))%mod;
    return result;
}
int main()
{
    long long int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        if(n)
            n--;
        long long int hc = (sum(m)%mod)-(sum(n))%mod;
        if(hc < 0)
        {
            hc+=mod;
        }
        cout<<hc<<endl;
    }
    return 0;
}
