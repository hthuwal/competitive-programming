/* -------------------------------------------------------------------------- */
/*              https://leetcode.com/problems/number-of-provinces             */
/* -------------------------------------------------------------------------- */
#include <stack>
#include <vector>
#include <iostream>

using namespace std;

int findCircleNum(vector<vector<int>>& isConnected) {
    int num_nodes = isConnected.size();
    auto visited = vector<bool>(num_nodes, false);

    int num_components = 0;
    for (int node = 0; node < num_nodes; node++) {
        if (visited[node]) {
            continue;
        }

        num_components++;

        stack<int> st;
        st.push(node);

        while (!st.empty()) {
            int top = st.top();
            st.pop();
            visited[top] = true;

            for (int nbr = 0; nbr < num_nodes; nbr++) {
                if (nbr != top && !visited[nbr] && isConnected[top][nbr] == 1) {
                    st.push(nbr);
                }
            }
        }
    }
    return num_components;
}
