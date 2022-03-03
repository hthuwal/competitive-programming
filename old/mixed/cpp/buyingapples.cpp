#include <bits/stdc++.h>
using namespace std;
int M_dp(vector<int> v,int C)
{
  vector<int> sol(v.size(),0);
  vector<int> mysol(v.size(),0);

  vector<int> M(C+1,0);

  M[0]=0;
  for(int c=1;c<=C;c++)
  {
    for(int i=0;i<v.size();i++)
    {
      if(c>=(i+1) && v[i]!=-1)
        sol[i]=M[c-i-1];

      else
        sol[i]=0;      
    }
    for(int i=0;i<v.size();i++)
    {
      if(c>=(i+1) && v[i]!=-1)
        mysol[i]=sol[i]+v[i];
      else
        mysol[i]=INT_MAX;
    }
    M[c]=INT_MAX;
    for(int i=0;i<v.size();i++)
    {
      if(mysol[i]<M[c] )
        M[c]=mysol[i];
    }
  }
  return M[C];
}
int main()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  int t;
  cin>>t;
  while(t--)
  {
    int n,k;
    cin>>n>>k;
    vector<int> a(k,0);
    for(int i=0;i<k;i++)
    {
      cin>>a[i];
    }
    int x = M_dp(a,k);
    if(x<0 || x==INT_MAX)
      cout<<"-1"<<endl;
    else
      cout<<x<<endl;
  }
}