## Copy List With Random Pointer

### [Problem](https://leetcode.com/problems/copy-list-with-random-pointer/submissions/)

### Python Solution

```python
"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""


class Solution:
    def addNodeToList(self, end, val):
        new_node = Node(val)
        if (end == None):
            end = new_node
        else:
            end.next = new_node
            end = new_node
        return end

    def copyRandomList(self, head: 'Node') -> 'Node':
        og_list_index = {}
        new_list_reverse_index = {}
        current = head
        new_head = None
        new_current = None
        pos = 0
        while(current != None):
            new_current = self.addNodeToList(new_current, current.val)
            if new_head == None:
                new_head = new_current
            og_list_index[current] = pos
            new_list_reverse_index[pos] = new_current
            pos += 1
            current = current.next

        current = head
        new_current = new_head

        while(current != None):
            if current.random is not None:
                new_current.random = new_list_reverse_index[og_list_index[current.random]]
            current = current.next
            new_current = new_current.next

        return new_head
```

