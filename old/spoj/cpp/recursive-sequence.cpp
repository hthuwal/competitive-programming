/**
 *  https://www.spoj.com/problems/SEQ/
 * 
 *  Find the nth element of the recurrence relation
 *  ai = bi (i<=k)
 *  ai = c1 * bi-1 + c2 * bi-2 ...... + ck * bi-k
 *  Find an % 10^9. 
 *  Constraints: 
 *      k <= 10
 *      n <= 10^9
 *  
 *  Solution 1:
 *      Linear Solution O(k * n) * 1000 test cases => TLE
 * 
 *  Solution 2:
 *      Convert to Multiplicative Matrix Problem
 *      https://math.stackexchange.com/questions/858268/converting-recursive-equations-into-matrices     
 * 
 *      Suppose k = 3
 * 
 *      [c1, c2, c3,]         [ ak   ]        [ ak+1 ]  
 *      [ 1,  0,  0,]    x    [ ak-1 ]  =     [ ak   ]  
 *      [ 0,  1,  0,]         [ ak-2 ]        [ ak-1 ]
 *          
 *        Matrix A    x     Vk   = Vk+1
 * 
 *      So to get k+m th term we need to find A^(m) x Vk  (m = n-k)
 * 
 *      A^m can be found in logarithm term using matrix exponentiation
 *      
 *      Time = k^3 * log(n) * 1000 test cases => 9x10^6 :)
**/

#include<bits/stdc++.h>
#define lli long long int
#define vi vector<lli>
#define vvi vector<vi>

#define mod 1000000000
using namespace std;

/**
 * Given a vector c generate the recurrence matrix A 
 * as described above.
**/
vvi get_recurrence_matrix(vi c)
{
    lli k = c.size();
    vvi matrix(k, vi(k, 0));
    matrix[0] = vi(c);
    for(lli i=1;i<k;i++)
        matrix[i][i-1] = 1;
    return matrix;
}

/**
 * Print a vector
 */
void print(vi b)
{
    for(lli i=0;i<b.size();i++)
        cout<<b[i]<<"\t";
}

/**
 * Print a 2D square matrix
**/
void print(vvi a)
{
    for(lli i=0;i<a.size();i++)
    {
        print(a[i]);
        cout<<"\n";
    }
}

/**
 * Multipl 2 integers modulo mod
**/
lli multiply(lli a, lli b)
{
    return ((a % mod) * (b % mod) ) % mod;
}

/**
 * multiply two n x n matrices.
**/
vvi multiply(vvi a, vvi b)
{
    lli size = a.size();
    vvi ans = vvi(size, vi(size, 0));

    for(lli i = 0; i < size; i++)
    {
        for(lli j = 0; j < size; j++)
        {
            for(lli k = 0; k < size; k++)
            {
                ans[i][j] = (ans[i][j] + multiply(a[i][k], b[k][j])) % mod;
            }
        }
    }
    return ans;
}

/**
 * Multiply n x n matrix with n dimensional vector
**/
vi multiply(vvi a, vi b)
{
    lli size = a.size();
    vi ans(size, 0);
    for(lli i = 0; i < size; i++)
    {
        for(lli j = 0; j < size; j++)
        {
            ans[i] = (ans[i] + multiply(a[i][j], b[j])) % mod;
        }
    }
    return ans;
}

/**
 * Returne a kxk identity matrix
**/
vvi id(int k)
{
    vvi ret(k, vi(k, 0));
    for(int i = 0; i < k; i++)
        ret[i][i] = 1;
    return ret;
}

/**
 * Find the result of matrix A raised to the power n in O(k^3 * log(n)) time
 * where k is the size of matrix A
**/
vvi exponentiate(vvi a, int n)
{
    vvi ans = id(a.size());
    while(n>0)
    {
        if(n%2 == 1)
            ans = multiply(ans, a);
        a = multiply(a, a);
        n /= 2;
    }
    return ans;
}

int main()
{
    lli t, k, n;
    cin.sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        cin>>k;
        vi b(k, 0);
        vi c(k, 0);

        for(lli i=0;i<k;i++) { cin>>b[k-1-i]; b[k-1-i] = b[k-1-i] % mod; }
        for(lli i=0;i<k;i++) { cin>>c[i]; c[i] = c[i] % mod; }

        cin>>n;
        n--; k--;

        if(n<=k)
            cout<<b[k-n]<<"\n";
        else
        {
            vvi mat = get_recurrence_matrix(c);
            mat = exponentiate(mat, n-k);
            b = multiply(mat, b);
            cout<<b[0]<<"\n";
        }
    }
}