| Feature                    | Array           | Linked List                     |
| -------------------------- | --------------- | ------------------------------- |
| **Memory Allocation**      | Contiguous      | Non-contiguous                  |
| **Size**                   | Fixed (usually) | Dynamic                         |
| **Access by Index**        | O(1)            | O(n)                            |
| **Traversal**              | O(n)            | O(n)                            |
| **Insertion at Beginning** | O(n)            | O(1)                            |
| **Insertion at End**       | O(1)*           | O(n) (or O(1) with tail)        |
| **Deletion at Beginning**  | O(n)            | O(1)                            |
| **Deletion at End**        | O(1)            | O(n) (or O(1) with tail in DLL) |
| **Extra Memory**           | No              | Yes (pointer(s))                |
| **Cache Performance**      | Better          | Poorer                          |
| **Random Access**          | Supported       | Not Supported                   |

Array advantages and disavd:
1. Direct access using index (O(1))
2. Better cache locality
3. Less memory overhead
4. Simpler implementation

1. Fixed size
2. Insertion is costly
3. Deletion is costly
4. May waste memory


linkedlist adv and disadv:
1. Dynamic size
2. Easy insertion
3. Easy deletion
4. Memory allocated as needed

1. No direct indexing
2. Extra memory for pointers
3. Slower traversal due to pointer chasing
4. More complex implementation

                Array      Linked List

Access          O(1)       O(n)

Search          O(n)       O(n)

Insert Front    O(n)       O(1)

Insert End      O(1)*      O(n)

Delete Front    O(n)       O(1)

Delete End      O(1)       O(n)
