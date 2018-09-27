#include <cstdio>
/*
Complexity : O(number of digits is base representaion)
Binary representaion => O(log2(n))
*/
int count_normal(int b)
{
    int count=0;
    while(b)
    {
        count += (b&1);
        b>>=1;
    }
    return count;
}
/*Brian ... Algo
Subtraction of 1 from a number toggles all the bits (from right to left) 
till the rightmost set bit(including the righmost set bit). 
So if we subtract a number by 1 and do bitwise & with itself 
(n & (n-1)), we unset the righmost set bit. If we do n & (n-1) 
in a loop and count the no of times loop executes we get the set bit count.
*/
int count_special(int n)
{
    int count=0;
    while(n)
    {
        n=(n&(n-1));
        count++;
    }
    return count;
}
int main() 
{
    int x = 6185344;
    printf("%d %d\n",count_normal(x),count_special(x));
}