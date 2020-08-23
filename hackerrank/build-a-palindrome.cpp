#include <bits/stdc++.h>

using namespace std;

struct Cell
{
    int v;
    char c;
    vector<Cell*> ptr;
    Cell()
    {
        v=0; c='#';
    }
};

vector<string> ans;
void get_all(Cell* root, string sofar)
{
    if(root == NULL)
        ans.push_back(sofar);
    else
    {
        if(root->c != '#')
            sofar += root->c;
        if(root->ptr.size() == 0)
            ans.push_back(sofar);
        else
        {
            for(auto each: root->ptr)
            {
                get_all(each, sofar);
            }
        }
    }
}

int lcsubstring(string &a, string &b)
{
    int n = a.length();
    int m = b.length();

    int dp[n+1][m+1];
    int maxi = 0;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j] = 0;
            }
            else
            {
                if(a[i-1] == b[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    if(dp[i][j] > maxi)
                        maxi = dp[i][j];
                }
                else
                    dp[i][j] = 0;
            }
        }
    }

    return maxi;
}
void lcs(string &a, string &b)
{
    int n = a.length();
    int m = b.length();
    
    Cell dp[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j].v = 0;
            }
            else
            {
                if(a[i-1] == b[j-1])
                {
                    dp[i][j].v = dp[i-1][j-1].v + 1;
                    dp[i][j].c = a[i-1];
                    dp[i][j].ptr.push_back(&dp[i-1][j-1]);
                }
                else
                {
                    if(dp[i-1][j].v > dp[i][j-1].v)
                    {
                        dp[i][j].v = dp[i-1][j].v;
                        dp[i][j].ptr.push_back(&dp[i-1][j]);
                    }
                    else if(dp[i][j-1].v > dp[i-1][j].v)
                    {
                        dp[i][j].v = dp[i][j-1].v;
                        dp[i][j].ptr.push_back(&dp[i][j-1]);   
                    }
                    else
                    {
                        dp[i][j].v = dp[i][j-1].v;
                        dp[i][j].ptr.push_back(&dp[i-1][j]);
                        dp[i][j].ptr.push_back(&dp[i][j-1]);   
                    }
                }
            }
        }
    }

    get_all(&dp[n][m], "");
    set<string> temp(ans.begin(), ans.end());
    ans.assign(temp.begin(),temp.end());
}
/*
 * Complete the buildPalindrome function below.
 */
string buildPalindrome(string a, string b) {
    /*
     * Write your code here.
     */
    string c = string(a + b);
    string crev = string(c.rbegin(), c.rend());
    lcs(c, crev);
    for(auto each: ans)
    {
        // cout<<each<<" "<<a<<" "<<b<<" "<<lcsubstring(a, each)<<" "<<lcsubstring(b, each)<<endl;
        if(each.length() > 1 and lcsubstring(a, each) > 0 and lcsubstring(b, each) > 0)
        {
            return each;
        }
    }
    return "-1";
}

int main()
{
    int t;
    string a, b;
    scanf("%d",&t);
    while(t--)
    {
        ans.clear();
        cin>>a>>b;
        // cout<<lcsubstring(a, b);
        cout<<buildPalindrome(a, b)<<endl;
    }
}