/* -------------------------------------------------------------------------- */
/*                 https://leetcode.com/problems/reorder-list                 */
/* -------------------------------------------------------------------------- */

#include "common-struct.h"

class Solution {
   public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        ListNode* second_half = splitAndReturnSecondHalf(head);
        ListNode* reversed_second_half = reverseList(second_half);
        mergeList(head, reversed_second_half);
    }

    // Assumes at least two nodes
    // If even nodes, return pointer to (n/2) + 1th node
    // If odd nodes, returns pointer to ceil(n/2) + 1th node
    ListNode* splitAndReturnSecondHalf(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        // Two Pointers
        // Fast moves twice as fast as slow
        // When fast reaches end, slow will be at middle
        while (true) {
            if (fast->next == nullptr) {
                // 1 -> 2 -> 3 -> 4
                // Slow at 2, Fast at 4
                break;
            }
            fast = fast->next;

            if (fast->next == nullptr) {
                // 1 -> 2 -> 3 -> 4 -> 5
                // Slow at 2, Fast at 5
                // We want to be at 3 so we move slow again
                slow = slow->next;
                break;
            }
            fast = fast->next;

            slow = slow->next;
        }

        // We want to return the start of second half
        ListNode* start_of_second_half = slow->next;

        // Break the link between first and second half
        slow->next = nullptr;

        return start_of_second_half;
    }

    // Reverses a linked list
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* a = nullptr;
        ListNode* b = head;
        while (b != nullptr) {
            ListNode* temp = b->next;
            b->next = a;
            a = b;
            b = temp;
        }
        return a;
    }

    // Merges two lists
    void mergeList(ListNode* one, ListNode* two) {
        while (one != nullptr && two != nullptr) {
            ListNode* one_next = one->next;
            ListNode* two_next = two->next;

            one->next = two;
            two->next = one_next;

            one = one_next;
            two = two_next;
        }
    }

    void printList(ListNode* node) {
        while (node != nullptr) {
            cout << node->val << " ";
            node = node->next;
        }
        cout << "\n";
    }
};