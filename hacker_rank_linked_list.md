### Reverse a doubly linked list

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

### Detect cycle in singly linked list
```python
def has_cycle(head):
    slow = head
    fast = Node(head.data, head.next)
 
    # if they reach the end implies there is no cycle
    while slow is not None and fast is not None:  # while none of them reach the end
        # incrementing pointers
        slow = slow.next
        if fast.next is None:
            return False
        fast = fast.next.next

        if slow == fast and slow is not None:
            return True

    return False
```