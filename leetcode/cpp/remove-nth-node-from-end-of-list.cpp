/* -------------------------------------------------------------------------- */
/*       https://leetcode.com/problems/remove-nth-node-from-end-of-list/      */
/* -------------------------------------------------------------------------- */

#include "common-struct.h"

class Solution {
   public:
    int findNumberOfNodes(ListNode* head) {
        int numberOfNodes = 0;
        ListNode* ptr = head;
        while (ptr != nullptr) {
            ptr = ptr->next;
            numberOfNodes++;
        }
        return numberOfNodes;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int numberOfJumpsFromStart = findNumberOfNodes(head) - n;
        if (numberOfJumpsFromStart <= 0) {
            return head->next;
        }

        ListNode *ptr2, *ptr;
        ptr = head;
        for (int i = 0; i < numberOfJumpsFromStart; i++) {
            ptr2 = ptr;
            ptr = ptr->next;
        }

        ptr2->next = ptr->next;
        return head;
    }

    ListNode* removeNthFromEndSingleTraversal(ListNode* head, int n) {
        if (head == nullptr) {
            return head;
        }

        int i = 1;
        ListNode* tail = head;
        while (i < n && tail->next != nullptr) {
            tail = tail->next;
            i++;
        }

        if (i != n) {
            return head;
        }

        ListNode* t1 = head;
        ListNode* t2 = nullptr;

        while (tail->next != nullptr) {
            t2 = t1;
            t1 = t1->next;
            tail = tail->next;
        }

        if (t2 != nullptr) {
            t2->next = t1->next;
            return head;
        } else {
            return t1->next;
        }
    }
};

int main() {
    vector<int> eles({1, 2, 3, 4, 5});
    ListNode* head = CreateLinkedList(eles);
    PrintLinkedList(Solution().removeNthFromEnd(head, 2));
}