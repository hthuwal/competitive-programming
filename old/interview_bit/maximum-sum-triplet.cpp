/**
 * https://www.interviewbit.com/problems/maximum-sum-triplet/
 * Solution: https://www.geeksforgeeks.org/find-maximum-sum-triplets-array-j-k-ai-aj-ak/
 **/
#include<bits/stdc++.h>
using namespace std;

int getLargestNumberSmallerThan(set<int> &numbersToTheLeft, int key) {
    // Number just greater than or equal to key
    auto it = numbersToTheLeft.lower_bound(key);
    it--;
    return (*it);
}

int solve(vector<int> &A) {
    vector<int> maxSuffix(A.size());
    maxSuffix[A.size()-1] = A[A.size()-1];
    for(int i=A.size()-2; i>=0;i--) {
        maxSuffix[i] = max(A[i], maxSuffix[i+1]);
    }

    set<int> numbersToTheLeft;
    numbersToTheLeft.insert(INT_MIN);
    numbersToTheLeft.insert(A[0]);
    int ans = 0;
    for(int i=1; i<A.size()-1; i++) {
        int me = A[i]; // O(1)
        int largestNumberSmallerThanMeTillNow = getLargestNumberSmallerThan(numbersToTheLeft, me); // O(log N)
        int largestNumberToMyRight = maxSuffix[i+1]; // O(1)

        if (largestNumberSmallerThanMeTillNow != INT_MIN && largestNumberToMyRight > me) {
            ans = max(ans, me + largestNumberSmallerThanMeTillNow + largestNumberToMyRight);
        }
        numbersToTheLeft.insert(A[i]);
    }
    return ans;
}


int main() {
    vector<int> A{32592, 18763, 1656, 17411, 6360, 27625, 20538, 21549, 6484, 27596};
    cout<<solve(A);
}