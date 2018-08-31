## Reverse a doubly linked list

```cpp
// Complete the reverse function below.

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */
DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) {
    if(head==NULL || head->next == NULL) //No Node or only one node
        return head;
    else{
        DoublyLinkedListNode* mid = head;
        while(mid!=NULL)
        {
            head=mid;
            mid=mid->next;
            head->next = head->prev;
            head->prev = mid;
        }
    }
    return head;
}
```