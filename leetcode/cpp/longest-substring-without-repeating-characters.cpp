// https://leetcode.com/problems/longest-substring-without-repeating-characters

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
   public:
    // Sliding Window
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSawAt;
        int ans = 0;
        int i = 0;
        int j = 0;

        while (j < s.size()) {
            // If you see something that you already saw earlier
            // Move the start of the window to just ahead of where you last saw it, if the window is behind it
            if (lastSawAt.find(s[j]) != lastSawAt.end()) {
                i = max(i, lastSawAt[s[j]] + 1);
            }

            lastSawAt[s[j]] = j;
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};