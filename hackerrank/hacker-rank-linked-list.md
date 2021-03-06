### Reverse a doubly linked list

```cpp
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
### Insert in a single link list at index i

- assuming the index given is valid and belongs to [0, n]

```cpp
#define sll SinglyLinkedListNode

sll* insertNodeAtPosition(sll* head, int data, int position) {
    sll* temp = head; //iski jagah pe daalna hai
    sll* temp2 = head; //iske aage dalna hai
    
    while(position--)
    {
        temp2 = temp;
        temp = temp->next;            
    }
    
    sll *cur_node = new sll(data);
    if(temp == head)
    {
        cur_node->next = head;
        head = cur_node;
    }
    else
    {
        temp2->next = cur_node;
        cur_node->next = temp;
    }
    return head;
}
```

### Insert in a sorted Doubly Linked List

```cpp
#define dbl DoublyLinkedListNode

dbl* sortedInsert(dbl* head, int data) {
    // If list already empty return new node
    if(head == nullptr) 
        return new dbl(data);
    else
    {
        dbl *temp = head; // First number who is greater than data
        dbl *temp2 = head; // Last number less than equal to data
        
        // keep moving pair of pointers unless 
        // you find a node with data > mydata or list ends
        while(temp!=nullptr and temp->data < data)
        {
            temp2 = temp;
            temp = temp -> next;
        }
        
        dbl *cur_node = new dbl(data);
        
        // node to be inserted at beginning
        if(temp == head)
        {
            cur_node->next=head;
            head->prev = cur_node;
            return cur_node;
        } 
        // node to be inserted at end
        else if(temp == nullptr)
        {
            temp2 -> next = cur_node;
            cur_node->prev = temp2;
            return head;
        }
        // node to be inserted at the beginning
        else
        {
            temp2->next = cur_node;
            cur_node -> prev = temp2;
            cur_node -> next = temp;
            temp->prev = cur_node;
            return head;
        }
    }
}
```