## [Problem](https://www.spoj.com/problems/CIRCLE_E/)

Radius of Inner Soddy Circles.

## [Solution](http://www.gogeometry.com/geometry/soddy_descartes_circles.htm)

## Code

```cpp
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    double a, b, c;
    cin.sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c;
        double nr = a * b * c;
        double dr = a * b + a * c + b * c;
        dr = dr + 2 * sqrt(nr * (a+b+c));
        double ans  = nr / dr;
        printf("%0.7lf\n", ans);
    }
}
```