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

    /* ---- https://leetcode.com/problems/binary-tree-level-order-traversal/ ---- */
    int depthOfTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return max(1 + depthOfTree(root->left), 1 + depthOfTree(root->right));
    }

    void levelOrderUtil(TreeNode* root, vector<vector<int>>& ans, int d) {
        if (root == nullptr) {
            return;
        }
        ans[d].push_back(root->val);
        levelOrderUtil(root->left, ans, d + 1);
        levelOrderUtil(root->right, ans, d + 1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        int d = depthOfTree(root);
        vector<vector<int>> ans;

        if (d != 0) {
            ans.resize(d);
            levelOrderUtil(root, ans, 0);
        }
        return std::move(ans);
    }

    /* -------------- https://leetcode.com/problems/symmetric-tree -------------- */
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        return isMirrorImage(root->left, root->right);
    }

    bool isMirrorImage(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        } else if (p == nullptr) {
            return false;
        } else if (q == nullptr) {
            return false;
        }
        return isMirrorImage(p->left, q->right) && isMirrorImage(p->right, q->left) && p->val == q->val;
    }

    /* ------------ https://leetcode.com/problems/invert-binary-tree ------------ */
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }

        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        root->left = right;
        root->right = left;

        return root;
    }

    /* ----------------- https://leetcode.com/problems/path-sum ----------------- */
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }

        if (root->left == nullptr && root->right == nullptr) {
            if (targetSum == root->val) {
                return true;
            }
            return false;
        }

        int newTarget = targetSum - root->val;
        return hasPathSum(root->left, newTarget) || hasPathSum(root->right, newTarget);
    }

    /* ------ https://leetcode.com/problems/search-in-a-binary-search-tree ------ */
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return nullptr;
        }

        if (root->val == val) {
            return root;
        } else if (root->val > val) {
            return searchBST(root->left, val);
        } else {
            return searchBST(root->right, val);
        }
    }

    /* ----- https://leetcode.com/problems/insert-into-a-binary-search-tree ----- */
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }

        if (root->val > val) {
            root->left = insertIntoBST(root->left, val);
        } else {
            root->right = insertIntoBST(root->right, val);
        }

        return root;
    }

    /* -------- https://leetcode.com/problems/validate-binary-search-tree ------- */
    bool isValidBST(TreeNode* root, long ul, long ll) {
        if (root == nullptr) {
            return true;
        }

        if (root->val >= ul || root->val <= ll) {
            return false;
        }

        return isValidBST(root->left, root->val, ll) && isValidBST(root->right, ul, root->val);
    }

    bool isValidBST(TreeNode* root) { return isValidBST(root, (long)INT_MAX + 1, (long)INT_MIN - 1); }

    // https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // You reached a leaf without finding either p or q
        if (root == nullptr) {
            return nullptr;
        }

        // You found either of the values
        // If you encounter either of the values that itself is the lca in the subtree
        if (root->val == p->val || root->val == q->val) {
            return root;
        }

        // Recursively search for left or right
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If you found something on both left and right, this is the common ancestor
        if (left != nullptr && right != nullptr) {
            return root;
        }

        if (left != nullptr) {
            return left;
        }

        return right;
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