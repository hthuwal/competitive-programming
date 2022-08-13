/* -------------------------------------------------------------------------- */
/*                https://leetcode.com/problems/remove-element/               */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    // Idea: Two pointer approach.
    // Keep throwing the not needed number from the beginning
    // the end of the array
    int removeElementTwoPointer(vector<int>& nums, int val) {
        int i = 0;                // left pointer
        int j = nums.size() - 1;  // right pointer

        while (i < j) {
            // If the number at left pointer is not Val
            // Leave it as it is and move forward.
            if (nums[i] != val) {
                i++;
            }
            // If the number at the right pointer (end) is Val
            // Leave it as it is, we want all Vals towards right
            else if (nums[j] == val) {
                j--;
            }
            // If the left pointer is Val and right pointer is not Val
            // Swap them, so that val goes to the right
            else {
                swap(nums[i], nums[j]);
            }
        }

        // Find the limit beyond which all numbers are Val
        for (int k = 0; k < nums.size(); k++) {
            if (nums[k] == val) {
                return k;
            }
        }
        return nums.size();
    }

    // Idea: Use the positions of vals as you enounter them as
    // Linked list to point to next availalbe val, linking all positions available to be replaced
    int removeElementLinkedList(vector<int>& nums, int val) {
        // Count of how many vals we encounter
        int count = 0;

        int head = -1;
        int tail = -1;
        for (int i = 0; i < nums.size(); i++) {
            // Found a position that can be replaced
            if (nums[i] == val) {
                count++;

                // If its the first availalbe position
                if (head == -1) {
                    head = i;
                    tail = i;
                }
                // Change the value of the last available position
                // to point to the new tail
                else {
                    nums[tail] = i;
                    tail = i;
                }
            }
            // Found a candidate that can move
            else {
                // There is no available position, linked list is empty
                if (head == -1) {
                    continue;
                }

                // If head == tail, there's only one valid position
                if (head == tail) {
                    // Fill the position
                    nums[head] = nums[i];

                    // The current position now becomes empty and the only element in linked list
                    head = i;
                    tail = i;
                }
                // There are more than 1 element in the linked list
                else if (head < tail) {
                    int temp = head;

                    // move the head by one node
                    head = nums[head];

                    // relace the previous head with the candidate
                    nums[temp] = nums[i];

                    // The current position now becomes empty and the only element in linked list
                    // Make the previous tail point to new tail.
                    nums[tail] = i;
                    tail = i;
                }
            }
        }
        return nums.size() - count;
    }
};