#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

ListNode* CreateLinkedList(vector<int>& eles) {
    ListNode *head = nullptr, *curr = nullptr;
    for (const auto& ele : eles) {
        if (head == nullptr) {
            curr = new ListNode(ele);
            head = curr;
        } else {
            curr->next = new ListNode(ele);
            curr = curr->next;
        }
    }
    return head;
}

void PrintLinkedList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
}

template<typename T>
void PrintVector(vector<T> &&vec) {
    for (const auto &each: vec) {
        std::cout<<each<<" ";
    }
    std::cout<<"\n";
}