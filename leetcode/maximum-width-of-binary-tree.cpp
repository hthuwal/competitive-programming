/* ------- https://leetcode.com/problems/maximum-width-of-binary-tree ------- */

#include <iostream>
#include <queue>
#include <unordered_map>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

struct NodeDetails {
    TreeNode* node;
    int depth;
    int hzfr;  // horizontal_distance_from_root at the level
    NodeDetails(TreeNode* node, int depth, int hzfr) : node(node), depth(depth), hzfr(hzfr) {}
};

//                                               ┌───┐
//                                               │   │
//                        ┌──────────────────────┤ 0 ├───────────────────────┐
//                        │                      │   │                       │
//                        │                      └───┘                       │
//                        │                                                  │
//                        │                                                  │
//                        │                                                  │
//                      ┌─┴─┐                                              ┌─┴─┐
//                      │   │                                              │   │
//          ┌───────────┤-1 ├──────────┐                         ┌─────────┤ 1 ├───────────┐
//          │           │   │          │                         │         │   │           │
//          │           └───┘          │                         │         └───┘           │
//          │                          │                         │                         │
//          │                          │                         │                         │
//          │                          │                         │                         │
//          │                          │                         │                         │
//          │                          │                         │                         │
//        ┌─┴─┐                      ┌─┴─┐                     ┌─┴─┐                     ┌─┴─┐
//        │   │                      │   │                     │   │                     │   │
//   ┌────┤-2 ├────┐            ┌────┤-1 ├────┐           ┌────┤ 1 ├────┐           ┌────┤ 2 ├────┐
//   │    │   │    │            │    │   │    │           │    │   │    │           │    │   │    │
//   │    └───┘    │            │    └───┘    │           │    └───┘    │           │    └───┘    │
//   │             │            │             │           │             │           │             │
// ┌─┴─┐         ┌─┴─┐        ┌─┴─┐         ┌─┴─┐       ┌─┴─┐         ┌─┴─┐       ┌─┴─┐         ┌─┴─┐
// │   │         │   │        │   │         │   │       │   │         │   │       │   │         │   │
// │-4 │         │-3 │        │-2 │         │-1 │       │ 1 │         │ 2 │       │ 3 │         │ 4 │
// │   │         │   │        │   │         │   │       │   │         │   │       │   │         │   │
// └───┘         └───┘        └───┘         └───┘       └───┘         └───┘       └───┘         └───┘
//
// Calculate these values for each node in the tree.
// For each level keep track of the highest and lowest value.
// Find highest - lowest for each level and then maximum amongst those is the width.
class Solution {
   private:
    std::unordered_map<int, int> max_pdpl;  // max_positive_distance_per_level
    std::unordered_map<int, int> min_ndpl;  // min_negative_distance_per_level
    std::queue<NodeDetails> q;

   public:
    int widthOfBinaryTree(TreeNode* root) {
        // BFS For level order traversal
        max_pdpl[0] = 0;
        min_ndpl[0] = 0;
        q.push(NodeDetails(root, 0, 0));

        while (!q.empty()) {
            const auto front = q.front();
            q.pop();

            if (front.hzfr == 0) {
                handleChildren(front, [](long) -> std::pair<long, long> { return {-1, 1}; });
            } else if (front.hzfr < 0) {
                handleChildren(front, [](long x) -> std::pair<long, long> { return {2 * x, 2 * x + 1}; });
            } else {
                handleChildren(front, [](long x) -> std::pair<long, long> { return {2 * x - 1, 2 * x}; });
            }
        }

        return calculateMaxWidth();
    }

    int calculateMaxWidth() {
        int levels = max_pdpl.size();
        int max_width = 0;
        for (int i = 0; i < levels; i++) {
            int right = max_pdpl[i];
            int left = min_ndpl[i];

            bool same_sign = (right >= 0 && left >= 0) || (right < 0 && left < 0);
            int width_at_this_level = right - left;
            if (same_sign) {
                width_at_this_level++;
            }

            if (width_at_this_level > max_width) {
                max_width = width_at_this_level;
            }
        }
        return max_width;
    }

    void handleChildren(const NodeDetails& node_details, std::function<std::pair<int, int>(int)> func) {
        int depth = node_details.depth + 1;
        auto newhzfrs = func(node_details.hzfr);
        if (node_details.node->left != nullptr) {
            updateLevelMaps(depth, newhzfrs.first);
            q.push(NodeDetails(node_details.node->left, depth, newhzfrs.first));
        }

        if (node_details.node->right != nullptr) {
            updateLevelMaps(depth, newhzfrs.second);
            q.push(NodeDetails(node_details.node->right, depth, newhzfrs.second));
        }
    }

    void updateLevelMaps(int depth, int dist) {
        if (min_ndpl.count(depth) == 0 || dist < min_ndpl[depth]) {
            min_ndpl[depth] = dist;
        }

        if (max_pdpl.count(depth) == 0 || dist > max_pdpl[depth]) {
            max_pdpl[depth] = dist;
        }
    }
};