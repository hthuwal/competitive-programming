/**
 * https://www.hackerrank.com/challenges/30-binary-numbers/problem
 *
 * Asked in Microsoft
 */
#include <bits/stdc++.h>

using namespace std;

int binary(int n)
{
    int count, ans = 0;
    while(n>0)
    {
        if(n%2 == 0)
            count = 0;
        else if(n%2 == 1)
            count += 1;
        if(count > ans)
            ans = count;
        n = n/2;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<binary(n);
    return 0;
}
