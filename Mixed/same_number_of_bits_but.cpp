#include <cstdio>
#include <iostream>
#define lli long long int
/*
snoobh => same number of one bits and just higher

If we flip a zero to a one, we must flip a one to a zero.
The number (After two flips) will be bigger if and only if the zero-to-one bit was to the left of the one to zero bit.
We want to make the number bigger, but not unnecessarily bigger. Therefore, we need to flip the rightmost zero which has ones on the right of it.

The idea is to find right most string of 1’s in x, and shift the pattern to right extreme, except the left most bit in the pattern. 
Shift the left most bit in the pattern (omitted bit) to left part of x by one position. 
e.g snoob of 10011100 is 10100011
*/
lli snoobh(lli x)
{
    if(x==0)
        return -1;

    lli right_most_set_bit = (x&-x); //00000100

    lli left_half = x + right_most_set_bit; //10100000

    lli right_and_two_extra = (x ^ left_half); //00111100
    lli right_half = right_and_two_extra/right_most_set_bit; //00001111
    right_half = right_half >> 2; //00000111
    lli ans = left_half | right_half;
    return ans;
}
/*
snoobl => same number of one bits and just lower

If we flip a zero to a one, we must flip a one to a zero.
The number (After two flips) will be smaller if and only if one to zero bit is to the left of the zero-to-one bit.
We want to make the number maller, but not unnecessarily smaller. Therefore, we need to flip the rightmost one which has zeroes 0 on the right of it.
flip the zero to 1 and shift all the one's on right to close to it
e.g snoobl of 10010001111 is 10001111100
= not(snoolh of not(10010001111))

*/
lli snoobl(lli x)
{
    if(x==0 || x==1)
        return -1;
    x = ~x;
    return ~snoobh(x);
}