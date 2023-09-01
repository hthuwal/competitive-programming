/* -------------------------------------------------------------------------- */
/*                  https://leetcode.com/problems/add-binary/                 */
/* -------------------------------------------------------------------------- */

#include <iostream>

using namespace std;

class Solution {
   public:
    // b1 -> will contain sum
    // b2 -> will contain carry
    void addTwoBits(char& b1, char& b2) {
        if (b1 == '0' && b2 == '1') {
            b1 = '1';
            b2 = '0';
        } else if (b1 == '1' && b2 == '1') {
            b1 = '0';
            b2 = '1';
        }
    }

    // b1 -> will contain sum
    // b2 -> will contain carry
    void addThreeBits(char& b1, char& b2, char b3) {
        addTwoBits(b1, b2);
        if (b1 == '0') {
            addTwoBits(b1, b3);
        } else {
            b2 = b3;
            addTwoBits(b1, b2);
        }
    }

    string addBinary(string a, string b) {
        string ans;
        char b1, b2, carry;
        int na = a.size() - 1;
        int nb = b.size() - 1;

        carry = '0';
        while (na >= 0 && nb >= 0) {
            b1 = a[na];
            b2 = b[nb];
            addThreeBits(b1, b2, carry);
            ans += b1;
            carry = b2;
            na--;
            nb--;
        }

        while (na >= 0) {
            b1 = a[na];
            addTwoBits(b1, carry);
            ans += b1;
            na--;
        }

        while (nb >= 0) {
            b2 = b[nb];
            addTwoBits(b2, carry);
            ans += b2;
            nb--;
        }

        if (carry == '1') {
            ans += carry;
        }

        string final_ans;
        for (int i = ans.size() - 1; i >= 0; i--) {
            final_ans += ans[i];
        }
        return final_ans;
    }
};

int main() {
    Solution s;
    string a("1010");
    string b("1011");
    cout << a << "\n" << b << "\n";
    cout << Solution().addBinary(a, b) << "\n";
}