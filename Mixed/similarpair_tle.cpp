#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#define lli long long int
using namespace std;
set<lli> *allparents;
set<lli> *directchilds;
void add(lli a,lli b){
    set<lli>::iterator t1;
    if(allparents[b].count(a)==0)
    {
        allparents[b].insert(a);
        for(t1=directchilds[b].begin();t1!=directchilds[b].end();t1++){
            add(a,*t1);
        } 
    }
    if(directchilds[a].count(b)==0)
    {
        directchilds[a].insert(b);
           for(t1=allparents[a].begin();t1!=allparents[a].end();t1++){
            add(*t1,b);
        }
    }
}

int main() {
  
    lli n,k,a,b;
    cin>>n>>k;
    allparents = new set<lli>[n+1];
    directchilds = new set<lli>[n+1];
    
    for(lli i=0;i<n-1;i++){
       cin>>a>>b;
       add(a,b);
    }
    lli count=0;
    set<lli>::iterator t1;

    for(lli i=1;i<=n;i++)
    {
      for(t1=directchilds[i].begin();t1!=directchilds[i].end();t1++)
      {
           
            if(abs(i- (*t1))<=k)
            {
                count++;
            }
        }
    }
  
    cout<<count;
    return 0;
}