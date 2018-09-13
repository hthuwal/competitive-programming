#include<bits/stdc++.h>

using namespace std;

int root2(int A) {
    double change, l=0, h=A;
    double thresh = 1e-3; //threshold matters
    double mid, old_mid = 0;
    
    int count = 0;
    cout<<"Finding Square root of: "<<A<<endl;
    if(A == 1)
        return 1;
    do
    {
        mid = (l+h)/2;
        double cand = mid*mid;
        if (cand == A) //better to use doubles to increase precision
            return floor(mid);
        else if (cand > A)
           h = mid;
        else
            l = mid;
        
        change = fabs(mid - old_mid);
        old_mid = mid;
        
        printf("Candidate %d: %.17f %d\n", count, mid);
        count++;
    }while(change > thresh);
    
    double cand = floor(mid) + 1;
    if(cand*cand == A)
        return cand;

    return floor(mid);
}

int main()
{
    int n;
    // for(int i=0; i<50; i++)
    // {
    //     double a = root2(i);
    //     double b = floor(sqrt(i));  
    //     if(fabs(a-b) < 1e-3)
    //         cout<<"True";
    //     else
    //     {
    //         cout<<"False";
    //         printf(": %0.5f %0.5f\n", a, b);
    //     }

    // }
    cin >> n;
    double a = root2(n);
    double b = floor(sqrt(n)); 
}