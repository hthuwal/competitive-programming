#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t, n;
	for(scanf("%d", &t); t--; )
	{
	    scanf("%d", &n);
	    int count = 0;
	    for(int i=1; i<=int(ceil(cbrt(n))); i++)
	    {
	        float x = n-i*i*i;
	        float y = int(cbrt(x));
	        if(y*y*y == x && y>=0)
	            count ++;
	    }
	    printf("%d\n",count);
	}
	return 0;
}