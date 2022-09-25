#include <iostream>

#include "common-struct.h"

using namespace std;

class Solution {
   public:
    /* ----- https://leetcode.com/problems/remove-nth-node-from-end-of-list ----- */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
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

    /* ------------- https://leetcode.com/problems/linked-list-cycle ------------ */
    bool hasCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }

        ListNode* hare = head->next->next;
        ListNode* tortoise = head;

        while (true) {
            if (hare == nullptr) {
                return false;
            }

            if (hare == tortoise) {
                return true;
            }

            if (hare->next == nullptr) {
                return false;
            }

            hare = hare->next->next;
            tortoise = tortoise->next;
        }

        return false;
    }

    /* --------- https://leetcode.com/problems/middle-of-the-linked-list -------- */
    ListNode* middleNode(ListNode* head) {
        if (head->next == nullptr) {
            return head;
        }

        ListNode* t1 = head;
        ListNode* t2 = head;

        while (t2 != nullptr && t2->next != nullptr) {
            t1 = t1->next;
            t2 = t2->next->next;
        }
        return t1;
    }

    /* ---- https://leetcode.com/problems/remove-duplicates-from-sorted-list ---- */
    ListNode* deleteDuplicates(ListNode* head, int target) {
        if (head == nullptr) {
            return head;
        }

        if (head->val == target) {
            return deleteDuplicates(head->next, target);
        } else {
            head->next = deleteDuplicates(head->next, head->val);
            return head;
        }
    }

    ListNode* deleteDuplicates(ListNode* head) { return deleteDuplicates(head, -200); }

    /* -------- https://leetcode.com/problems/remove-linked-list-element -------- */
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) {
            return nullptr;
        }

        if (head->val != val) {
            head->next = removeElements(head->next, val);
            return head;
        }
        return removeElements(head->next, val);
    }

    /* ------------ https://leetcode.com/problems/reverse-linked-list ----------- */
    ListNode* reverseList(ListNode* head, ListNode*& newHead) {
        if (head->next == nullptr) {
            newHead = head;
            return head;
        }

        ListNode* tail = reverseList(head->next, newHead);
        tail->next = head;
        head->next = nullptr;
        return head;
    }

    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode* ans;
        reverseList(head, ans);
        return ans;
    }

    ListNode* reverseListIterative(ListNode* head) {
        if (head == nullptr) {
            return head;
        }

        ListNode* prev = nullptr;
        while (head != nullptr) {
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }

        return prev;
    }

    /* ----------- https://leetcode.com/problems/linked-list-cycle-ii/ ---------- */
    ListNode* detectCycle(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        if (head->next == nullptr) {
            return nullptr;
        }

        ListNode* tortoise = head->next;
        ListNode* hare = head->next->next;

        while (hare != nullptr && hare->next != nullptr) {
            if (tortoise == hare) {
                break;
            }

            tortoise = tortoise->next;
            hare = hare->next->next;
        }

        if (tortoise != hare) {
            return nullptr;
        }

        tortoise = head;
        while (tortoise != hare) {
            tortoise = tortoise->next;
            hare = hare->next;
        }

        return tortoise;
    }
};