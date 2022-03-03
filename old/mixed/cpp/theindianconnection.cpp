/*
M=0,F=1
Gen 1: 0
Gen 2: 01
Gen 3: 0110
Gen 4: 01101001
Gen 5: 0110100110010110
.
.
Gen x: 01101001100101101001011001101001....
the sequence obtained for any generation is Thue-Morse
Sequence

In mathematics, the Thue–Morse sequence, or Prouhet–Thue–Morse sequence,
is the binary sequence (an infinite sequence of 0s and 1s) obtained by 
starting with 0 and successively appending the Boolean complement of the 
sequence obtained thus far. The first few steps of this procedure yield the 
strings 0 then 01, 0110, 01101001, 0110100110010110, and so on, which are 
prefixes of the Thue–Morse sequence.

To compute the nth element tn, write the number n in binary. If the number 
of ones in this binary expansion is odd then tn = 1, if even then tn = 0.
E.g 8th bit of sequence : 8 = 1000 => number of 1's in the binary expansion is odd
therefore 8th bit must be 1

This method leads to a fast method for computing the Thue–Morse sequence: 
start with t0 = 0, and then, for each n, find the highest-order bit in the 
binary representation of n that is different from the same bit in the representation of n − 1. 
(This bit can be isolated by letting x be the bitwise exclusive or of n and n − 1,
shifting x right by one bit, and computing the exclusive or of this shifted value with x.) 
If this bit is at an even index, tn differs from tn − 1, and otherwise it is the same as tn − 1. 
The resulting algorithm takes constant time to generate each sequence element, using only a
 logarithmic number of bits (constant number of words) of memory.[2]

*/

#include <cstdio>
#define lli long long int
int count_special(lli n)
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
    freopen("in.txt","r",stdin);
    int t;
    lli n,k;
    for(scanf("%d",&t);t--;)
    {
        scanf("%lld %lld",&n,&k);
        if(count_special(k-1)%2==0)//if number of set bits in k is even then kth bit of Thue-Morse Series is 0
            printf("Male\n");
        else 
            printf("Female\n");           
    }
}