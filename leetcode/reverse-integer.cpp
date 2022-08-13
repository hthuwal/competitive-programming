/* -------------------------------------------------------------------------- */
/*                https://leetcode.com/problems/reverse-integer               */
/* -------------------------------------------------------------------------- */

#include <bits/stdc++.h>

using namespace std;

/**
 * Custom vector based representation of a 64 bit integer
 **/
class Int64 {
   public:
    vector<char> digits;
    bool isNegative = false;

    Int64(const Int64& other) {
        this->digits = other.digits;
        this->isNegative = other.isNegative;
    }

    Int64(int n) {
        if (n < 0) {
            isNegative = true;
        }

        while (n != 0) {
            int d = (n % 10);
            if (isNegative) {
                d = d * -1;
            }
            digits.push_back('0' + d);
            n = n / 10;
        }
    }

    friend ostream& operator<<(ostream& o, const Int64& num) {
        if (num.isNegative) {
            o << "-";
        }
        for (int i = num.digits.size() - 1; i >= 0; i--) {
            o << num.digits[i];
        }
        return o;
    }

    bool operator>(const Int64& other) {
        if (this->isNegative && !other.isNegative) {
            return false;
        }

        if (!this->isNegative && other.isNegative) {
            return true;
        }

        if (this->isNegative && other.isNegative) {
            Int64 temp_this(*this);
            Int64 temp_other(other);
            temp_this.isNegative = false;
            temp_other.isNegative = false;
            return !(temp_this > temp_other);
        }

        if (this->digits.size() > other.digits.size()) {
            return true;
        } else if (this->digits.size() < other.digits.size()) {
            return false;
        } else {
            int n = this->digits.size();
            for (int i = n - 1; i >= 0; i--) {
                if (this->digits[i] > other.digits[i]) {
                    return true;
                } else if (this->digits[i] < other.digits[i]) {
                    return false;
                }
            }
            return false;
        }
    }

    bool operator<(const Int64& other) { return !(this->operator>(other)); }

    void reverse() {
        int i = 0;
        int j = digits.size() - 1;
        while (i < j) {
            char temp = digits[i];
            digits[i] = digits[j];
            digits[j] = temp;
            i++;
            j--;
        }
    }

    int toInt() {
        int ans = 0;
        for (int i = digits.size() - 1; i >= 0; i--) {
            ans = ans * 10 + (digits[i] - '0');
        }
        if (isNegative) {
            ans = ans * -1;
        }
        return ans;
    }
};

Int64 nmax((int)INT_MAX);
Int64 nmin((int)INT_MIN);

class Solution {
   public:
    int reverse(int x) {
        Int64 num(x);
        num.reverse();
        if (num > nmax || num < nmin) {
            return 0;
        }
        return num.toInt();
    }
};

int main() {
    Solution sol;
    cout << sol.reverse(123456) << "\n";
}