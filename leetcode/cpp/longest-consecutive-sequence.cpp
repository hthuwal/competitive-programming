/* -------------------------------------------------------------------------- */
/*         https://leetcode.com/problems/longest-consecutive-sequence/        */
/* -------------------------------------------------------------------------- */

#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;
int biggestConnectedComponent(unordered_map<int, vector<int>>& graph) {
    unordered_map<int, bool> visited;
    visited.reserve(graph.size());

    int ans = 0;
    for (const auto& each : graph) {
        int node = each.first;
        if (visited.count(node)) {
            continue;
        }

        int size = 0;
        stack<int> st;
        st.push(node);
        while (!st.empty()) {
            int top = st.top();
            st.pop();
            visited[top] = true;
            size++;
            for (const auto& nbr : graph[top]) {
                if (visited.count(nbr) == 0) {
                    st.push(nbr);
                }
            }
        }

        if (size > ans) {
            ans = size;
        }
    }
    return ans;
}

void insertIfNotPresent(vector<int>& vec, int n) {
    for (const int& num : vec) {
        if (num == n) {
            return;
        }
    }
    vec.push_back(n);
}

// O(n): Gives a runtime of 300ms?
int longestConsecutive(vector<int>& nums) {
    unordered_map<int, vector<int>> graph;

    for (const auto& num : nums) {
        int prev = num - 1;
        int after = num + 1;

        if (graph.count(num) == 0) {
            graph[num].reserve(2);
        }

        if (graph.count(prev)) {
            insertIfNotPresent(graph[prev], num);
            insertIfNotPresent(graph[num], prev);
        }

        if (graph.count(after)) {
            insertIfNotPresent(graph[after], num);
            insertIfNotPresent(graph[num], after);
        }
    }
    return biggestConnectedComponent(graph);
}

// O(nlogn): Gives a runtime of 58ms
int longestConsecutive(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    if (nums.size() == 0) {
        return 0;
    }

    int ans = 0;
    int ca = 1;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i - 1] + 1) {
            ca++;
        } else if (nums[i] != nums[i - 1]) {
            if (ca > ans) {
                ans = ca;
            }
            ca = 1;
        }
    }

    if (ca > ans) {
        return ca;
    }

    return ans;
}

// O(n): Using hashing
int longestConsecutive(vector<int>& nums) {
    unordered_set<int> hash(nums.begin(), nums.end());
    int ans = 0;
    for (auto num : hash) {
        // Does a number smaller than this exist?
        // No: Then this is the beginning of a sequence. Find the length of sequence starting from this number.
        // Yes: Then this is not the beginning of a sequence and will be counted in the sequence starting from the
        // smaller number.
        if (hash.find(num - 1) == hash.end()) {
            int length = 1;
            // Iterate as long as we keep finding larger and larger number
            while (hash.find(num + length) != hash.end()) {
                length++;
            }
            ans = max(ans, length);
        }
    }
    return ans;
}