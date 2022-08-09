/* -------------------------------------------------------------------------- */
/*       https://leetcode.com/problems/remove-nth-node-from-end-of-list/      */
/* -------------------------------------------------------------------------- */

#include "common-struct.h"

class Solution
{
public:
    int findNumberOfNodes(ListNode *head)
    {
        int numberOfNodes = 0;
        ListNode *ptr = head;
        while (ptr != nullptr)
        {
            ptr = ptr->next;
            numberOfNodes++;
        }
        return numberOfNodes;
    }

    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        int numberOfJumpsFromStart = findNumberOfNodes(head) - n;
        if (numberOfJumpsFromStart <= 0)
        {
            return head->next;
        }

        ListNode *ptr2, *ptr;
        ptr = head;
        for (int i = 0; i < numberOfJumpsFromStart; i++)
        {
            ptr2 = ptr;
            ptr = ptr->next;
        }

        ptr2->next = ptr->next;
        return head;
    }
};

int main()
{
    vector<int> eles({1, 2, 3, 4, 5});
    ListNode *head = CreateLinkedList(eles);
    PrintLinkedList(Solution().removeNthFromEnd(head, 2));
}