### [Check if BST or not](https://www.hackerrank.com/challenges/ctci-is-binary-search-tree/problem)

- The  value of every node in a node's left subtree is less than the data value of that node.   
- The  value of every node in a node's right subtree is greater than the data value of that node.   
- The  value of every node is distinct.  

```cpp
/*
    root: root of the current subtree
    lbound: minimum value the nodes in this subtree can have
    rbound: maximum value the nodes in this subtree can have
*/
bool checkBST_Util(Node* root, int lbound, int ubound) {
    // no tree is a bst
    if(root == nullptr) 
        return true;

    // if roots's value doesn't satisifes the bounds
    if(root->data <= lbound || root->data >= ubound)
        return false;
    
    // else check if the left and right subtrees satisfy their bounds or not
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

### [Find height of tree](https://www.hackerrank.com/challenges/tree-height-of-a-binary-tree/problem)

```cpp
int height(Node* root) {
    if(root == nullptr)
        return 0;
    int hl = height(root->left);
    int hr = height(root->right);

    hl = root->left != nullptr?(hl+1): 0;
    hr = root->right != nullptr?(hr+1): 0;

    return max(hl, hr);
}
```

### [Lowest Common Ancestor](https://www.hackerrank.com/challenges/binary-search-tree-lowest-common-ancestor/problem)

- Assuming the tree always contains the two values
- values in tree are all unique

```cpp
Node *lca(Node *root, int v1,int v2) {
    // You reached end without encountering v1 or v2, therefor no common ancestor
    if(root == nullptr)
        return nullptr;

    // if the root is equal to v1 or v2 then it must be the common ancestor
    if(root->data == v1 || root->data == v2)
        return root;

    // if root is not equal to either one of them
    else
    {
        Node* cand_from_left = lca(root->left, v1, v2); // find either of them in left subtree
        Node* cand_from_right = lca(root->right, v1, v2); // find either of them in right subtree
        
        // if both tree say they found something then you are the common ancestor
        if(cand_from_left != nullptr and cand_from_right != nullptr)
            return root;

        // if only left tree says it find something then and right didn't
        // then left's candidate is the answer
        else if(cand_from_left != nullptr)
            return cand_from_left;
        else
            return cand_from_right;
    }
}
```
### [Huffman Decoding](https://www.hackerrank.com/challenges/tree-huffman-decoding/problem)

```cpp
void decode_huff(node * root, string s) {
    node * head = root; //start from the root

    for(int i=0; i<s.length(); i++)
    {
        if(s[i] == '0') // if current code is zero go left
            head = head->left;
        else // else go right
            head = head->right;
        
        // if the node you reached is a leaf print the value and start from root again
        if(head->left == NULL && head->right == NULL)
        {
            cout<<head->data;
            head = root;
        }
    }
}
```