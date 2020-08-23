#include<iostream>
#define lld long long int
#define mod 1000000007
using namespace std;
int main()
{
    lld a = 985745946;
    lld b = 985745946;
    lld c = (a%mod*b%mod)%mod;
    cout<<c;
}