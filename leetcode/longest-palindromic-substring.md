### [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring)

Given a string s, find the longest palindromic substring in s.

---

#### Solution: O(n^2)

**Recurrence Relation:**

```
lps -> length of the longest palindromic substring

                {
                    2 + lps(s,i+1, j-1) if s[i]==s[j] and s[i+1:j-1] is palindrome
lps(s, i, j) = 
                    max(lps(s,i,j-1), lps(s,i+1,j)) else
                }
```


**Dynamic programming C++ code**
```c++
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        
        // dp_start[i][j] denotes the starting index of longest palindromic substring in s[i-1:j-1]
        int dp_start[n+2][n+2];

        // dp_length[i][j] denotes the length of longest palindromic substring in s[i-1:j-1] 
        int dp_length[n+2][n+2];

        memset(dp_start, 0, sizeof(dp_start));
        memset(dp_length, 0, sizeof(dp_length));
       
        /*Each single letter is a palindrome*/
        for(int i=1;i<=n;i++)
        {
            dp_start[i][i] = i-1;
            dp_length[i][i] = 1;
        }
        
        /*bottom up filling the matrix*/
        for(int i=n;i>=1;i--)
        {
            for(int j=i+1;j<=n;j++)
            {
                /*if first and last letters are same and rest in between is a palindrome*/
                if(s[i-1]==s[j-1] and dp_length[i+1][j-1] == (j-1-i-1+1))
                {
                    dp_length[i][j] = dp_length[i+1][j-1] + 2;
                    dp_start[i][j] = i-1;
                }
                else
                {
                    if (dp_length[i+1][j] > dp_length[i][j-1])
                    {
                        dp_length[i][j] = dp_length[i+1][j];
                        dp_start[i][j] = dp_start[i+1][j];
                    }
                    else
                    {
                        dp_length[i][j] = dp_length[i][j-1];
                        dp_start[i][j] = dp_start[i][j-1];
                        
                    }
                        
                }
            }
        }
        cout<<dp_start[1][n]<<" "<<dp_length[1][n];
        return s.substr(dp_start[1][n], dp_length[1][n]);
    }
};
```