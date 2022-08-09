/* -------------------------------------------------------------------------- */
/*            https://leetcode.com/problems/merge-two-sorted-lists/           */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*             https://leetcode.com/problems/merge-k-sorted-lists             */
/* -------------------------------------------------------------------------- */

#include "common-struct.h"

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr)
        {
            return list2;
        }
        else if (list2 == nullptr)
        {
            return list1;
        }

        ListNode *ptr1 = list1;
        ListNode *before_ptr1 = nullptr;
        ListNode *ptr2 = list2;

        while (ptr1 != nullptr && ptr2 != nullptr)
        {
            // Need to move node ptr2 to just before ptr1
            if (ptr1->val >= ptr2->val)
            {
                // If there's nothing before ptr1, ptr2 becomes the start of list1
                if (before_ptr1 == nullptr)
                {
                    ListNode *temp = ptr2->next;

                    ptr2->next = ptr1;
                    before_ptr1 = ptr2;
                    ptr2 = temp;

                    list1 = before_ptr1;
                }
                else // Move ptr2 between before_ptr1 and ptr1
                {
                    ListNode *temp = ptr2->next;
                    before_ptr1->next = ptr2;

                    ptr2->next = ptr1;
                    before_ptr1 = ptr2;
                    ptr2 = temp;
                }
            }
            else if (ptr1->val < ptr2->val)
            {
                before_ptr1 = ptr1;
                ptr1 = ptr1->next;
            }
        }

        // If list 2 hasn't been fully traversed i.e list 1 has finished (ptr1 == nullptr)
        // Append list 2 at the end of list1
        if (ptr2 != nullptr)
        {
            before_ptr1->next = ptr2;
        }
        return list1;
    }

    ListNode *mergeKListsLinearly(vector<ListNode *> &lists)
    {
        ListNode *ans = lists[0];
        for (int i = 1; i < lists.size(); i++)
        {
            ans = mergeTwoLists(ans, lists[i]);
        }
        return ans;
    }

    ListNode *mergeKListsRecursively(vector<ListNode *> &lists, int i, int j)
    {
        if (i == j)
        {
            return lists[i];
        }

        int m = (i + j) / 2;
        auto left = mergeKListsRecursively(lists, i, m);
        auto right = mergeKListsRecursively(lists, m + 1, j);
        return mergeTwoLists(left, right);
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
        {
            return nullptr;
        }
        if (lists.size() == 1)
        {
            return lists[0];
        }
        return mergeKListsRecursively(lists, 0, lists.size() - 1);
    }
};