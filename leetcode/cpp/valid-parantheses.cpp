/* -------------------------------------------------------------------------- */
/*              https://leetcode.com/problems/valid-parentheses/              */
/* -------------------------------------------------------------------------- */

#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    inline bool isClosingBrace(char c) { return c == ']' || c == ')' || c == '}'; }

    inline char isCorrectPair(char open, char close) {
        return (open == '(' && close == ')') || (open == '[' && close == ']') || (open == '{' && close == '}');
    }

    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (isClosingBrace(c)) {
                if (st.empty()) {
                    return false;
                }
                char top = st.top();
                st.pop();
                if (!isCorrectPair(top, c)) {
                    return false;
                }
            } else {
                st.push(c);
            }
        }
        return st.empty();
    }
};

void run(std::string&& pattern) { std::cout << pattern << ": " << Solution().isValid(pattern) << "\n"; }

int main() {
    run("[]{}()");
    run("[[({})]{}]");
    run("[}");
    run("[{}{{](]");
}