/* -------------------------------------------------------------------------- */
/*           https://leetcode.com/problems/top-k-frequent-elements/           */
/* -------------------------------------------------------------------------- */

#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    // Time: O(n) + O(nlogn) = O(nlogn)
    // Space: O(n) + O(n) = O(n)
    // 6ms
    vector<int> topKFrequentSort(vector<int>& nums, int k) {
        unordered_map<int, int> freqCount;
        for (auto num : nums) {
            freqCount[num]++;
        }

        vector<pair<int, int>> countPairs;
        for (auto freq : freqCount) {
            countPairs.push_back({freq.first, freq.second});
        }

        sort(countPairs.begin(), countPairs.end(), [](auto& a, auto& b) { return a.second > b.second; });

        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(countPairs[i].first);
        }
        return ans;
    }

    // Time: O(n) + O(nlogk) = O(nlogk)
    // Space: O(n) + O(k) = O(n)
    // 0ms
    vector<int> topKFrequentHeap(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (const auto& num : nums) {
            freq[num]++;
        }

        // O(nlogk)
        // log(k) because we are using a min heap of size k. We remove the top element if the size exceeds k.
        // Essentially at the end we will have the k largest elements in the heap.

        // Alternate way of crating priority_queue with custom comparator
        // struct cmp{
        //     bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        //         return a.second > b.second;
        //     }
        // } ;
        // priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> min_heap;

        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) { return a.second > b.second; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> min_heap;
        for (const auto& each : freq) {
            min_heap.push({each});

            if (min_heap.size() > k) {
                min_heap.pop();
            }
        }

        // Extract the elements from the heap
        vector<int> ans;
        ans.reserve(k);
        while (!min_heap.empty()) {
            ans.push_back(min_heap.top().first);
            min_heap.pop();
        }

        return ans;
    }

    // Time: O(n) + O(n) = O(n)
    // Space: O(n) + O(n) = O(n)
    vector<int> topKFrequentBucketSort(vector<int>& nums, int k) {
        unordered_map<int, int> freqCount;
        for (auto num : nums) {
            freqCount[num]++;
        }

        int n = nums.size();
        vector<vector<int>> freqBuckets(n + 1);
        for (const auto p : freqCount) {
            freqBuckets[p.second].push_back(p.first);
        }

        vector<int> ans;
        for (int i = n; i > 0; i--) {
            for (int n : freqBuckets[i]) {
                ans.push_back(n);
                if (ans.size() == k) {
                    return ans;
                }
            }
        }
        return ans;
    }
};
