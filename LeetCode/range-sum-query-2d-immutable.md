## Range Sum Query 2D

Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

[Reference to calculate matrix prefix sum](https://www.geeksforgeeks.org/prefix-sum-2d-array/)


```cpp
#define vi vector<int>
#define vvi vector<vi>
#define fs(i,s,n) for(int i=s;i<n;i++)
#define f(i,n) for(int i=0;i<n;i++)

class NumMatrix {
public:
    vvi dp;
    NumMatrix(vector<vector<int>> arr) {
        int n = arr.size();
        if(n==0)
            return;
        int m = arr[0].size();
        
        dp = *(new vvi(n, vi(m, 0)));
        
        dp[0][0] = arr[0][0];
    
        fs(i,1,m) dp[0][i] = dp[0][i-1] + arr[0][i];
        fs(i,1,n) dp[i][0] = dp[i-1][0] + arr[i][0];
    
        fs(i,1, n) 
            fs(j,1,m)
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + arr[i][j];
    }
    int sumRegion(int si, int sj, int ei, int ej) {
        int ans = 0;
        ans += dp[ei][ej];
        if(si == 0 and sj == 0)
            return ans;
        else if(si == 0)
            ans -= dp[ei][sj-1];
        else if(sj == 0)
            ans -= dp[si-1][ej];
        else
            ans = ans - dp[ei][sj-1] - dp[si-1][ej] + dp[si-1][sj-1];
        return ans;
    }
};
```