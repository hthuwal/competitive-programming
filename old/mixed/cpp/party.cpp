#include<iostream>
using namespace std;
int a[102][502], d[102], c[102];
int main()
{
    int b, n, res, res1;
    while(1)
    {
        cin >> b >> n;
        if(b == 0 && n == 0)
        {
            break;
        }
        for(int i = 0; i < n; i++)
        {
            cin >> c[i] >> d[i];
        }
        for(int i = 0; i <= n; i++)
        {
            a[i][0] = 0;
        }
        for(int i = 0; i <= b; i++)
        {
            a[0][i] = 0;
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= b; j++)
            {
                if(j < c[i-1])
                {
                    a[i][j] = a[i-1][j];
                }
                else
                {
                    a[i][j] = max(a[i-1][j], d[i-1] + a[i-1][j-c[i-1]]);
                }
            }
        }
        res1 = a[n][b];
        res = b;
        for(int i = 0; i <= b; i++)
        {
            if(a[n][i] >= res1 && i < res)
            {
                res1 = a[n][i];
                res = i;
            }
        }
        cout << res << ' ' << res1 << '\n';
    }
    return 0;
}
