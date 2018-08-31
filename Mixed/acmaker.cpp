#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<string> insig;
vector<string> phrase;

void init()
{
    insig.clear();
    phrase.clear();
}

void input()
{
    int n;
    string in;
    cin>>n;
    if(t==0)
        break;
    while(n--)
    {
        cin>>in;
        insig.push_back(in);
    }
    while(1)
    {
        getline(cin, in);
        if(in=="LAST CASE")
            break;
        
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(1)
    {
        init();        

    }
}