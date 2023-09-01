/* -------------------------------------------------------------------------- */
/*              https://leetcode.com/problems/swap-nodes-in-pairs             */
/* -------------------------------------------------------------------------- */

#include "common-struct.h"

class Solution {
   public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Recursively swapPairs of the list after the first two nodes
        ListNode* swappedRestList = swapPairs(head->next->next);

        // Swap the first two nodes
        ListNode* firstNode = head;
        ListNode* secondNode = head->next;
        secondNode->next = firstNode;
        firstNode->next = swappedRestList;

        // SecondNode is now head
        head = secondNode;
        return head;
    }
};

int main() {
    vector<int> eles({1, 2, 3, 4, 5});
    ListNode* head = CreateLinkedList(eles);
    PrintLinkedList(Solution().swapPairs(head));
}