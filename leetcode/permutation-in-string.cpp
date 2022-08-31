/* -------------------------------------------------------------------------- */
/*             https://leetcode.com/problems/permutation-in-string            */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
   public:
    void print(unordered_map<char, int>& ref) {
        for (auto each : ref) {
            printf("(%c: %d) ", each.first, each.second);
        }
        printf("\n");
    }

    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }

        unordered_map<char, int> freqs1;
        for (auto ch : s1) {
            freqs1[ch]++;
        }

        int i = 0;
        int j = 0;
        unordered_map<char, int> freqs2;
        while (j < s1.size()) {
            freqs2[s2[j]]++;
            j++;
        }

        if (freqs1 == freqs2) {
            return true;
        }

        i++;
        while (j < s2.size()) {
            freqs2[s2[i - 1]]--;
            if (freqs2[s2[i - 1]] == 0) {
                freqs2.erase(s2[i - 1]);
            }
            freqs2[s2[j]]++;

            if (freqs1 == freqs2) {
                return true;
            }

            i++;
            j++;
        }

        return false;
    }
};