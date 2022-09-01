#include <iostream>
#include <stack>

#include "common-struct.h"

using namespace std;

class Solution {
   public:

    // https://leetcode.com/problems/binary-tree-inorder-traversal/submissions/
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        if (root == nullptr) {
            return std::move(ans);
        }

        stack<TreeNode*> st;
        auto left = root->left;
        auto right = root->right;

        // Mark root to be printed next time
        root->left = nullptr;
        root->right = nullptr;

        st.push(right);
        st.push(root);
        st.push(left);

        while (!st.empty()) {
            TreeNode* top = st.top();
            st.pop();

            if (top == nullptr) {
                continue;
            }

            if (top->left == nullptr && top->right == nullptr) {
                ans.push_back(top->val);
            } else {
                left = top->left;
                right = top->right;
                top->left = nullptr;
                top->right = nullptr;

                st.push(right);
                st.push(top);
                st.push(left);
            }
        }

        return std::move(ans);
    }

    /* ------ https://leetcode.com/problems/binary-tree-preorder-traversal ------ */
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;

        if (root == nullptr) {
            return std::move(ans);
        }

        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* top = st.top();
            st.pop();

            ans.push_back(top->val);
            if (top->right != nullptr) st.push(top->right);

            if (top->left != nullptr) st.push(top->left);
        }

        return std::move(ans);
    }

    /* ---------- https://leetcode.com/problems/merge-two-binary-trees ---------- */
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr) {
            return root2;
        } else if (root2 == nullptr) {
            return root1;
        }

        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }

    /* ---------------- https://leetcode.com/problems/same-tree/ ---------------- */
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        } else if (p == nullptr) {
            return false;
        } else if (q == nullptr) {
            return false;
        }
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right) && p->val == q->val;
    }
};

int main() {
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    cout << Solution().isSameTree(p, q) << "\n";
}