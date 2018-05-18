#include <cstdio>
#include <vector>
#include <iostream>
#include <utility>
using namespace std;
#define N 111111
vector<pair<int,string> >list[26];
vector<bool> visited(N,false); 
vector<string> words(N,"");

void init()
{
    for(int i=0;i<26;i++)
        list[i].clear();
}
// void print(int n)
// {
//     for(int i=0;i<26;i++)
//     {
//         printf("%c :",'a'+i);
//         for(int j=0;j<list[i].size();j++)
//             cout<<list[i][j]<<" ";
//         cout<<endl;
//     }
//     for(int i=0;i<n;i++)
//         cout<<words[i]<<" ";
//     cout<<endl;
//     for(int i=0;i<n;i++)
//         cout<<visited[i]<<" ";
// }
bool sol_backtrack(string hc,int all)
{
    if(all==0)
        return true;
    int i = hc[hc.length()-1]-'a';
    for(int j=0;j<list[i].size();j++)
    {
        if(visited[list[i][j].first]==false)
        {
            visited[list[i][j].first]=true;
            if(sol_backtrack(list[i][j].second,all-1))
                return true;
            visited[list[i][j].first]=false;
        }
    }
    return false;
}
bool solve(int n)
{
    for(int i=0;i<n;i++)
    {
        visited[i]=true;
        if(sol_backtrack(words[i],n-1))
            return true;
        visited[i]=false;
    }
    return false;
}
int main()
{
    freopen("in.txt","r",stdin);
    int t,n;
    string hc;
    for(scanf("%d",&t);t--;)
    {
        init();
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            cin>>words[i];
            visited[i]=false;
            list[words[i][0]-'a'].push_back(make_pair(i,words[i]));
        }
        if(solve(n))
            cout<<"Ordering is possible.\n";
        else
            cout<<"The door cannot be opened.\n";
        
    }
}