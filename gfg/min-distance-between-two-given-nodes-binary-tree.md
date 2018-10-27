### [Min distance between two given nodes of a Binary Tree](https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1)

Given a binary tree and two node values your task is to find the minimum distance between them.

#### Solution. 3 Passes O(n)

Find LCA(a, b) = l

min_dist(a, b) = dist(root, a) + dist(root, b) - 2 * dist(root, l);

```cpp
int dist(Node *root, int a)
{
    if(root == NULL)
        return -1;
    if(root->data == a)
        return 0;
    else
    {
        int left = dist(root->left, a);
        int right = dist(root->right, a);
        
        if(left != -1)
            return left + 1;
        if(right != -1)
            return right + 1;
        return -1;
    }
}

int lca(Node* root, int a, int b)
{
    if(root == NULL)
        return -1;
    else if(root->data == a)
        return a;
    else if(root->data == b)
        return b;
    else
    {
        int left = lca(root->left, a, b);
        int right = lca(root->right, a, b);
        if(left != -1 and right != -1)
            return root->data;
        else if(left != -1)
            return left;
        else if(right != -1)
            return right;
        else 
            return -1;
    }
}
int findDist(Node* root, int a, int b)
{
    int lc = lca(root, a, b);
    int da = dist(root, a);
    int db = dist(root, b);
    return da + db - 2*dist(root, lc);
}
```