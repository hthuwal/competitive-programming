/**
 * Problem: https://leetcode.com/problems/next-greater-element-i/
 **/ 

#include<iostream>
#include<vector>
#include<stack>
#include <unordered_map>

using namespace std;

#define vi vector<int>

/**
 * O(n^2) algorithm
 *  
 * ## Python Code: Same Algorithm
 *  def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
 *      umap = {}
 *      for i in range(len(nums2)):
 *          umap[nums2[i]] = i
 *      
 *      answers = [-1] * len(nums1)
 *      for i in range(len(nums1)):
 *          if nums1[i] in umap:
 *              for j in range(umap[nums1[i]]+1, len(nums2)):
 *                  if nums2[j] > nums1[i]:
 *                      answers[i] = nums2[j]
 *                      break
 *      return answers
 **/
vector<int> nextGreaterElementBrute(vector<int>& nums1, vector<int>& nums2) {
    
    unordered_map<int, int> umap; 
    for(int i=0; i<nums2.size(); i++) {
        umap[nums2[i]] = i;
    }

    vector<int> answer(nums1.size(), -1);
    for(int i=0; i<nums1.size(); i++) {
        if (umap.find(nums1[i]) != umap.end()) {
            for(int j=umap[nums1[i]]+1; j<nums2.size(); j++) {
                if (nums2[j] > nums1[i]) {
                    answer[i] = nums2[j];
                    break;
                }
            }
        }
    }
    return answer;
}

/**
 * Some Stack based O(n) algorithm.
 * 
 * Iterate:
 *  For every number:
 *      if stack is empty: 
 *          push it into not answered stack
 *      else
 *          keep popping the stack untill either the stack is empty 
 *          or the top of the stack is greater thean the current number.
 *          For all of the popped numbers the current number is the answer.
 *  For the numbers that remain in stack. No answer exists.
 * 
 * Apparently this takes longer execution time than the above O(n^2) solution.
 * Fucked up test cases may be?
 * 
 * # Python
 * def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
 *       umap = {}
 *       stack = []
 *       for i in range(len(nums2)):
 *           umap[nums2[i]] = i
 *           if len(stack) == 0:
 *               stack.append(i)
 *           else:
 *               while(len(stack) != 0 and nums2[stack[-1]] < nums2[i]):
 *                   nums2[stack[-1]] = nums2[i]
 *                   stack.pop()
 *               stack.append(i)
 *       
 *       while(len(stack)!=0):
 *           nums2[stack[-1]] = -1
 *           stack.pop()
 *
 *       answers = [-1] * len(nums1)
 *       for i in range(len(nums1)):
 *           if nums1[i] in umap:
 *               answers[i] = nums2[umap[nums1[i]]]
 *       return answers
 **/
vector<int> nextGreaterElementStack(vector<int>&nums1, vector<int>&nums2) {
    stack<int> stack; // Indices for which we weren't able to find answers
    unordered_map<int, int> umap; 
    for(int i=0; i<nums2.size(); i++) {
        umap[nums2[i]] = i;
        if(stack.empty())
            stack.push(i);
        else {
            while(!stack.empty() && nums2[stack.top()] < nums2[i]) {
                nums2[stack.top()] = nums2[i];
                stack.pop();
            }
            stack.push(i);
        }
    }

    while(!stack.empty()) {
        nums2[stack.top()] = -1;
        stack.pop();
    }
    vector<int> answer(nums1.size(), -1);
    for(int i=0; i<nums1.size(); i++) {
        if(umap.find(nums1[i]) != umap.end()) {
            answer[i] = nums2[umap[nums1[i]]];
        }
    }
    return answer;
}

int main() {
    vector<int> nums1;
    vector<int> nums2;

    int n;
    cin>>n;
    nums1.resize(n);
    for(int i=0; i<n; i++)
        cin>>nums1[i];
    
    cin>>n;
    nums2.resize(n);
    for(int i=0; i<n; i++)
        cin>>nums2[i];
    
    vector<int> answer = nextGreaterElementStack(nums1, nums2);
    for (int i=0; i< answer.size(); i++)
        cout<<answer[i]<<" ";
}