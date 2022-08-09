/* -------------------------------------------------------------------------- */
/*       https://leetcode.com/problems/remove-nth-node-from-end-of-list/      */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    ListNode *head = nullptr, *curr = nullptr;
    for (const auto &ele : eles)
    {
        if (head == nullptr)
        {
            curr = new ListNode(ele);
            head = curr;
        }
        else
        {
            curr->next = new ListNode(ele);
            curr = curr->next;
        }
    }

    ListNode *new_head = Solution().removeNthFromEnd(head, 2);
    while (new_head != nullptr)
    {
        cout << new_head->val << " ";
        new_head = new_head->next;
    }
}