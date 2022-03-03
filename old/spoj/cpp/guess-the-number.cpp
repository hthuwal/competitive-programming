/**
 * https://www.spoj.com/problems/GUESSTHE/
 *  
**/

#include<bits/stdc++.h>
#define lli long long int

using namespace std;

lli gcd(lli a, lli b)
{
    lli temp;
    while(b!=0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

lli lcm(lli a, lli b)
{
    lli g = gcd(a, b);
    return (a * b) / g;
}

lli solve(string str)
{
    lli len = str.length();
    lli ans = 1;
    for(int i = 0; i < len; i++)
    {
        if(str[i]=='Y')
            ans = lcm(ans, (i+1));
    }
    
    for(int i = 0; i < len; i++)
    {
        if(str[i]=='N' and ans % (i+1) == 0)
            return -1;
    }
    return ans;
}
int main()
{
    string inp;
    cin.sync_with_stdio(false);
    while(1)
    {
        cin>>inp;
        if(inp == "*")
            break;
        cout<<solve(inp)<<"\n";
    }
}