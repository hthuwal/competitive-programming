/* -------------------------------------------------------------------------- */
/*                  https://leetcode.com/problems/clone-graph                 */
/* -------------------------------------------------------------------------- */

#include <queue>
#include <vector>

using namespace std;

// Definition for a Node.
class Node {
   public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
   public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return node;
        }

        vector<Node*> new_nodes(110, nullptr);

        queue<Node*> q;
        new_nodes[node->val] = new Node(node->val);
        q.push(node);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            Node* new_current = new_nodes[current->val];
            for (const auto nbr : current->neighbors) {
                if (new_nodes[nbr->val] == nullptr) {
                    new_nodes[nbr->val] = new Node(nbr->val);
                    q.push(nbr);
                }
                new_current->neighbors.push_back(new_nodes[nbr->val]);
            }
        }

        return new_nodes[1];
    }
};