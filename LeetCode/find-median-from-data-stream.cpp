/**
 * Link to problem: https://leetcode.com/problems/find-median-from-data-stream/ 
 */

#include<iostream>
#include<queue>

using namespace std;

class MedianFinder {
private: 
    priority_queue<int> max_heap;
    priority_queue<int> min_heap;
    int running_median = 0;

public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if (num >= running_median) {
            if (min_heap.size() > max_heap.size()) {
                max_heap.push(-min_heap.top());
                min_heap.pop();
            }
            min_heap.push(-num);
        }
        else {
            if (max_heap.size() > min_heap.size()) {
                min_heap.push(-max_heap.top());
                max_heap.pop();
            }
            max_heap.push(num);
        }
        running_median = floor(findMedian());
    }
    
    double findMedian() {
        if (max_heap.size() == min_heap.size())
            return float(max_heap.top() - min_heap.top()) / 2.0;
        if (max_heap.size() > min_heap.size())
            return max_heap.top();
        return -min_heap.top();
    }
};