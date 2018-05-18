#include<iostream>
using namespace std;
int main()
{
    int a[5002];
    string b;
    int c1, c2, i, x;
    while(1)
    {
        cin >> b;
        if(b == "0")
        {
            return 0;
        }
        a[0] = a[1] = 1;
        for(i = 2; i <= b.length(); i++)
        {
            a[i] = 0;
            c1 = b[i-1] - '0';
            c2 = b[i-2] - '0';
            x = (c2 * 10 + c1);
            if( c2 == 1 || ((c2 == 2) && (c1 <= 6)))
            {
                a[i] += a[i-2];
            }
            if(c1 != 0)
            {
                a[i] += a[i-1];
            }
        }
        cout << a[b.length()] << '\n';
    }
}
