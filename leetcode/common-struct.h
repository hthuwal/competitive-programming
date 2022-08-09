#include <vector>
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *CreateLinkedList(vector<int> &eles)
{
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
    return head;
}

void PrintLinkedList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
}