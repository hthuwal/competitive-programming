### [Delete N nodes after skipping M nondes untill end](https://practice.geeksforgeeks.org/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/1)

```cpp
void linkdelete(struct node  *head, int m, int n)
{
    while(head!=NULL)
    {
        int count = 1;
        while(head->next != NULL && count<m)
        {
            count++;
            head = head->next;
        }
        
        // not enough elements
        if(count != m)
            return;
            
        struct node* pivot = head;
        struct node* last = head->next;
        
        count = 0;
        while(last!=NULL && count<n)
        {
            struct node* temp = last;
            last = last->next;
            free(temp);
            count++;
        }
        pivot->next = last;
        head = last;
    }
    
}
```