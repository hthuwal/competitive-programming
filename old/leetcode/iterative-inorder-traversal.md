#### [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/)

```c++
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode* root) 
{
    vector<int> inorder;
    stack<pair<TreeNode *, bool> > st;
    st.push(make_pair(root, false));
    while(!st.empty())
    {
           pair<TreeNode*, bool> pr = st.top(); st.pop();
           if(pr.first != NULL)
           {
               if(pr.second)
                   inorder.push_back(pr.first->val);
               else
               {
                   pr.second = true;
                   st.push(make_pair(pr.first->right, false));
                   st.push(pr);
                   st.push(make_pair(pr.first->left, false));
               }
           }
    }
    return inorder;
}
```