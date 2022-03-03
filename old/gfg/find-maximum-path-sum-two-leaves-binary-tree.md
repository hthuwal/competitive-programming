### [Find the maximum path sum between two leaves of a binary tree](https://practice.geeksforgeeks.org/problems/maximum-path-sum/1)

Given a binary tree in which each node element contains a number. Find the maximum possible sum from one leaf node to another.

#### Approach

Recursive function that takes in a pointer to a root and return maximum path sum from any leaf to root in it.

Whenever you encounter a non leaf node with both left and right not NULL you get a candidate for maximum path sum. left_max_path + right_max_path + me.

If this candidate path sum is greater than the maximum uptill now (ans), update the maximum.

#### Code

```cpp
int ans = INT_MIN;
int recursive(struct Node* root)
{
    if(root == NULL)
        return 0;
    else if(root->left == NULL and root->right == NULL)
        return root->data;
    else if(root->left == NULL)
        return recursive(root->right) + root->data;
    else if(root->right == NULL)
        return recursive(root->left) + root->data;
    else
    {
        int left_h = recursive(root->left);
        int right_h = recursive(root->right);
        int cand = left_h + right_h + root->data;
        if(cand > ans)
            ans = cand;
        return max(left_h, right_h) + root->data;    
    }
}

int maxPathSum(struct Node *root)
{
    ans = INT_MIN;
    recursive(root);
    return ans;
}
```