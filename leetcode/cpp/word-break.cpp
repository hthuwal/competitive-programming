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
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        bool dp[n];
        memset(dp, false, sizeof(dp));

        for (int i = n - 1; i >= 0; i--) {
            const string& str = s.substr(i);
            for (int j = 0; j < wordDict.size(); j++) {
                const string& word = wordDict[j];
                if (str.size() >= word.size() && word == str.substr(0, word.size())) {
                    int left_from = i + word.size();

                    // Nothing is left
                    if (left_from >= n || dp[left_from]) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[0];
    }
};