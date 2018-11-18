/*
Journey to Moon

https://www.hackerrank.com/challenges/journey-to-the-moon/problem

 */

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int parent[111111];
int size[111111];
int find(int i)
{
    if(parent[i] == i)
        return i;
    return parent[i] = find(parent[i]);
}

void uni(int a, int b)
{
    int pa = find(a);
    int pb = find(b);
    if(pa != pb)
    {
        if(size[pa] > size[pb])
            swap(pa, pb);
        parent[pa] = pb;
        size[pb] += size[pa];
    }
}

long long int journeyToMoon(int n, vector<vector<int>> astronaut) {
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
        size[i]=1;
    }
    
    for(auto each: astronaut)
        uni(each[0], each[1]);
    
    vector<long long int> comp;
    for(int i=0;i<n;i++)
        if(parent[i] == i)
            comp.push_back(size[i]);
        
    long long int temp[comp.size()] = {0};
    temp[comp.size()-1] = comp[comp.size()-1];
    
    for(int i=comp.size()-2;i>=0;i--)
        temp[i] = temp[i+1]+comp[i];
    
    long long int ans = 0;
    for(int i=0;i<comp.size()-1;i++)
        ans += (comp[i]*temp[i+1]);   

    return ans;
}



int main()
{
    int n, p;
    cin>>n>>p;
    vector<vector<int>> edg(p, vector<int>(2, 0));
    for(int i=0;i<p;i++)
    {
        cin>>edg[i][0]>>edg[i][1];
    }
    cout<<journeyToMoon(n, edg);
}
