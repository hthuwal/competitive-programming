#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void print(vector<pair<int,int> > t)
{
    for(int i=0;i<t.size();i++)
        cout<<t[i].first<<" "<<t[i].second<<endl;
}
bool compare(pair<int,int> a, pair<int,int> b)
{
    if(a.second<b.second)
        return true;
    else 
    return false;
}
int main()
{
    vector<pair<int,int> > hc;

    hc.push_back(make_pair(1,2));
    hc.push_back(make_pair(0,4));
    hc.push_back(make_pair(4,1));
    hc.push_back(make_pair(7,3));
    hc.push_back(make_pair(3,5));

    sort(hc.begin(),hc.end(),compare);
    print(hc);
}