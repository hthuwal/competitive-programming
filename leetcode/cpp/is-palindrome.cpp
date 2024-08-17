#include <string>

using namespace std;

class Solution {
   public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i <= j) {
            // Ignore all non-alpha numeric chars from i
            while (!isalnum(s[i]) && i < s.size()) {
                i++;
            }
            // If all chars are non-alpha numeric return true
            if (i >= s.size()) {
                return true;
            }

            // Ignore all non-alpha numeric chars from end
            while (!isalnum(s[j]) && j >= i) {
                j--;
            }
            // If all chars till i are non-alpha numeric return true
            if (i >= j) {
                return true;
            }

            // Compare the chars
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }

            i++;
            j--;
        }
        return true;
    }
};
