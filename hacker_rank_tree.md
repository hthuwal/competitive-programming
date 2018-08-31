### [Check if BST or not](https://www.hackerrank.com/challenges/ctci-is-binary-search-tree/problem)

- The  value of every node in a node's left subtree is less than the data value of that node.   
- The  value of every node in a node's right subtree is greater than the data value of that node.   
- The  value of every node is distinct.  

```cpp
bool checkBST_Util(Node* root, int lbound, int ubound) {
    if(root == nullptr)
        return true;

    if(root->data <= lbound || root->data >= ubound)
        return false;
    
    return checkBST_Util(root->left, lbound, root->data) 
       and checkBST_Util(root->right, root->data, ubound);
}

bool checkBST(Node* root)
{
    return checkBST_Util(root, INT32_MIN, INT32_MAX);
}
```

```python
def hc(root, lower_bound_node, upper_bound_node):
    if root is None:
        return True
    if lower_bound_node is not None and root.data <= lower_bound_node.data:
        return False
    if upper_bound_node is not None and root.data >= upper_bound_node.data:
        return False
    
    return hc(root.left, lower_bound_node, root) and hc(root.right, root, upper_bound_node)

def checkBST(root):
    return hc(root, None, None)
```