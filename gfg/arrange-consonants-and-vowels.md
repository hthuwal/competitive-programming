### [Arrange Consonants and Vowels](https://practice.geeksforgeeks.org/problems/arrange-consonants-and-vowels/1)

Given a singly linked list of size N containing only English Alphabets, your task is to complete the function arrange(), that arranges the consonants and vowel nodes of the list it in such a way that all the vowels nodes come before the consonants while maintaining the order of their arrival.

#### O(1) extra space, O(n) Time solution
```cpp 
struct Node* arrange(Node *head)
{
    struct Node* vb = NULL;
    struct Node* ve = NULL;
    struct Node* cb = NULL;
    struct Node* ce = NULL;
    
    while(head!=NULL)
    {
        struct Node* temp = head->next;
        
        if(isV(head->data))
        {
            if(vb == NULL)
            {
                head->next = NULL;
                vb = head;
                ve = vb;
            }
            else
            {
                head->next = NULL;
                ve->next = head;
                ve = head;
            }
        }
        else
        {
            if(cb == NULL)
            {
                head->next = NULL;
                cb = head;
                ce = cb;
            }
            else
            {
                head->next = NULL;
                ce->next = head;
                ce = head;
            }
        }
        
        head = temp;
    }
    if(vb == NULL)
        return cb;
    else
    {
        ve->next = cb;
        return vb;
    }
}
```