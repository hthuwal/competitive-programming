/* -------------------------------------------------------------------------- */
/*                   https://leetcode.com/problems/word-break                 */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Recursive solution with memoisation
class Solution {
   public:
    unordered_map<int, bool> cache;

    int endIndex(const string& word, string& s, int i) {
        int j = 0;
        while (i < s.size() && j < word.size()) {
            if (word[j] != s[i]) {
                return -1;
            }
            i++;
            j++;
        }

        if (j == word.size()) {
            return i;
        }
        return -1;
    }

    bool wordBreakRecursive(string& s, vector<string>& wordDict, int start) {
        if (start == s.size()) {
            return true;
        }

        if (cache.find(start) != cache.end()) {
            return cache[start];
        }

        bool possible = false;
        for (const string& word : wordDict) {
            int x = endIndex(word, s, start);
            if (x != -1) {
                possible = possible || wordBreakRecursive(s, wordDict, x);
            }
        }
        cache[start] = possible;
        return possible;
    }

    bool wordBreak(string s, vector<string>& wordDict) { return wordBreakRecursive(s, wordDict, 0); }
};

// Dynamic Programming Solution
class Solution {
   public:
    bool startsWith(string& s, int start, string& prefix) {
        int i = start;
        int j = 0;
        while (i < s.size() && j < prefix.size()) {
            if (s[i] != prefix[j]) {
                return false;
            }
            i++;
            j++;
        }
        return j == prefix.size();
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        // dp[i] indicates that if s[i:] is possible with wordDict or not
        bool dp[n + 1];
        memset(dp, false, n);

        dp[n] = true;
        for (int i = n - 1; i >= 0; i--) {
            for (auto& word : wordDict) {
                if (startsWith(s, i, word)) {
                    dp[i] = dp[i + word.size()];
                    if (dp[i]) {
                        break;
                    }
                }
            }
        }

        return dp[0];
    }
};