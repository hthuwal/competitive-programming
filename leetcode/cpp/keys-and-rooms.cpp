/* -------------------------------------------------------------------------- */
/*                https://leetcode.com/problems/keys-and-rooms                */
/* -------------------------------------------------------------------------- */

#include<vector>
#include<stack>

using namespace std;

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int n = rooms.size();
    vector<bool> visited(n, false);

    stack<int> st;
    st.push(0);

    while (!st.empty()) {
        int top = st.top();
        st.pop();
        visited[top] = true;

        for (const auto& nbr : rooms[top]) {
            if (!visited[nbr]) {
                st.push(nbr);
            }
        }
    }

    for (const auto& each : visited) {
        if (!each) {
            return false;
        }
    }

    return true;
}