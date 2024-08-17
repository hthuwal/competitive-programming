/* -------------------------------------------------------------------------- */
/*           https://leetcode.com/problems/top-k-frequent-elements/           */
/* -------------------------------------------------------------------------- */

#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> topKFrequent2(vector<int>& nums, int k) {
        // O(n)
        unordered_map<int, int> freq;
        for (const auto& num : nums) {
            freq[num]++;
        }

        // What is the maximum freq that can be there? -> n
        // So if we store numbers with freq as index, we can get the top k frequent elements in O(n) time.
        vector<vector<int>> freq_to_num(nums.size() + 1);
        for(const auto& each : freq) {
            // Add the number to the freq_to_num vector at the index of the freq.
            freq_to_num[each.second].push_back(each.first);
        }

        // Extract the top k frequent elements
        // Iterate from the end (max freq) to the start (min freq) and collect numbers.
        vector<int> ans;
        ans.reserve(k);
        for (int i = freq_to_num.size() - 1; i >= 0 && ans.size() < k; i--) {
            for (const auto& each : freq_to_num[i]) {
                ans.push_back(each);
                if (ans.size() == k) {
                    break;
                }
            }
        }
        return ans;
    }
    
    
    
    // Time: O(n) + O(nlogk) = O(nlogk)
    // Space: O(n) + O(k) = O(n)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // O(n)
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
            // log(k);
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
};