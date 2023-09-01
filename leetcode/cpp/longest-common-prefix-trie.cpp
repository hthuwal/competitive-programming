/* -------------------------------------------------------------------------- */
/*             https://leetcode.com/problems/longest-common-prefix            */
/* -------------------------------------------------------------------------- */

#include <bits/stdc++.h>
using namespace std;

/**
 * Node of a Trie
 **/
class Node {
   private:
    char c;
    Node* children[26];
    int sfc;  // Number of sentences ending at this node.

   public:
    Node(char ch) {
        sfc = 0;
        c = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
    ~Node() {
        for (int i = 0; i < 26; i++) {
            if (children[i] != nullptr) {
                delete children[i];
            }
        }
    }

    friend class Trie;
};

/**
 * Class representing a trie
 **/
class Trie {
   private:
    Node* root;

   public:
    Trie() { root = new Node(' '); }

    void Add(string& str) {
        Node* current = root;
        for (char c : str) {
            int i = c - 'a';
            if (current->children[i] == nullptr) {
                current->children[i] = new Node(c);
            }
            current = current->children[i];
        }
        current->sfc++;
    }

    ~Trie() {
        if (root != nullptr) {
            delete root;
        }
    }

    // Find longest common prefix across all strings
    string lcp() {
        Node* curr = root;
        std::string ans;

        while (curr != nullptr) {
            if (curr != root) {
                ans += curr->c;
            }

            // Check if non zero strings end here
            if (curr->sfc > 0) {
                return ans;
            }

            // check if diversion occurs at this point
            // more than 1 children implies no longer common prefix
            int numChild = 0;
            int childIndex = -1;
            for (int i = 0; i < 26; i++) {
                if (curr->children[i] != nullptr) {
                    numChild++;
                    childIndex = i;
                }
            }

            if (numChild != 1) {
                return ans;
            } else {
                curr = curr->children[childIndex];
            }
        }
        return ans;
    }
};

class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie trie;
        for (auto str : strs) {
            trie.Add(str);
            if (str == "") {
                return "";
            }
        }
        return trie.lcp();
    }
};

int main() {
    vector<string> strs;
    strs.push_back("harish");
    strs.push_back("harry");
    strs.push_back("haridwar");
    cout << Solution().longestCommonPrefix(strs) << "\n";
}