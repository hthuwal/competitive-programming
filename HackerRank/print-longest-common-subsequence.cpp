/**
 * https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence/problem
 */

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

struct Cell{
    int value;
    int c;
    Cell *parent;
    Cell()
    {
        value=0;
        c=-1;
        parent=NULL;
    }
};

vector<int> longestCommonSubsequence(vector<int> a, vector<int> b) {
    int n = a.size();
    int m = b.size();
    
    Cell dp[n+1][m+1];
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
                dp[i][j].value = 0;
            else
            {
                if(a[i-1] == b[j-1])
                {
                    dp[i][j].value = dp[i-1][j-1].value + 1;
                    dp[i][j].c = a[i-1];
                    dp[i][j].parent = &(dp[i-1][j-1]);
                }
                else
                {
                    Cell *ans = (dp[i-1][j].value > dp[i][j-1].value ? &dp[i-1][j] : &dp[i][j-1]);
                    dp[i][j].value = ans->value;
                    dp[i][j].parent = ans;
                }
            }
        }
    }
    
    vector<int> ans;
    Cell *root = &dp[n][m];
    while(root != NULL)
    {
        if(root->c!=-1)
            ans.push_back(root->c);
        root = root->parent;
    }
    reverse(begin(ans), end(ans));
    return ans;
}

int main()
{
    int n, m;
    scanf("%d %d",&n,&m);
    vector<int> a(n,0);
    vector<int> b(m,0);
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    for(int i=0;i<m;i++) scanf("%d", &b[i]);
    vector<int> ans = longestCommonSubsequence(a, b);
    for(int i=0;i<ans.size();i++) printf("%d ", ans[i]);
    printf("\n");
}