### [Sum of Leaf Nodes at Min Level] https://practice.geeksforgeeks.org/problems/sum-of-leaf-nodes-at-min-level/1

```cpp
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

map<int, int> scores;
void recursive(Node* root, int height)
{
    if(root == NULL)
	    return;
	else if(root->left == NULL and root->right == NULL)
	{
	    scores[height] += root->data;   
	}   
	else
	{
	    recursive(root->left, height + 1);
	    recursive(root->right, height + 1);
	}
}

int minLeafSum(Node* root)
{
    if(root == NULL)
        return 0;
	scores.clear();
	recursive(root, 0);
	return (*begin(scores)).second;
}
```