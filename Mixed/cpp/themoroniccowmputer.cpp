/**The base \scriptstyle -r expansion of a number can be found by repeated division by \scriptstyle  -r, recording the non-negative remainders of \scriptstyle  0, 1,\ldots r-1, and concatenating those remainders, starting with the last. Note that if \scriptstyle  a / b = c, remainder d, then \scriptstyle  bc + d = a. For example, in negaternary:

\begin{align}
 146 & ~/~ -3 = & -48, & ~\mbox{remainder}~ 2 \\
 -48 & ~/~ -3 = &  16, & ~\mbox{remainder}~ 0 \\
  16 & ~/~ -3 = &  -5, & ~\mbox{remainder}~ 1 \\
  -5 & ~/~ -3 = &   2, & ~\mbox{remainder}~ 1 \\
   2 & ~/~ -3 = &   0, & ~\mbox{remainder}~ 2 \\
\end{align}
Reading the remainders backward we obtain the negaternary expression of 146: 21102.

Note that in most programming languages, the result (in integer arithmetic) of dividing a negative number by a negative number is rounded towards 0, usually leaving a negative remainder. In such a case we have \scriptstyle  a = (-r)c + d = (-r)c + d - r + r = (-r)(c + 1) + (d + r). Because \scriptstyle |d| < r, \scriptstyle (d + r) is the positive remainder. Therefore, to get the correct result in such case, computer implementations of the above algorithm should add 1 and r to the quotient and remainder respectively (shown below in the Python programming language):

def negaternary(i):
    digits = []
    if not i:
        digits = ['0']
    else:
        while i != 0:
            i, remainder = divmod(i, -3)
            if remainder < 0:
                i, remainder = i + 1, remainder + 3
            digits.append(str(remainder))
    return ''.join(digits[::-1])**/


#include<iostream>
#include<stack>
using namespace std;
int main()
{
    long long int n,q,r;
    stack<int>hc;
    cin>>n;
    if(n==0)
        hc.push(0);
    while(n!=0)
    {
        r=n%(-2);
        n=n/(-2);
        if(r<0)
        {
            n++;
            r=r+2;
        }
        hc.push(r);
    }
    while(!hc.empty())
    {
        cout<<hc.top();
        hc.pop();
    }
}
