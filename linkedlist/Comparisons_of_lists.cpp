| Feature                       | Singly LL         | Circular Singly LL | Doubly LL          | Circular Doubly LL |
| ----------------------------- | ----------------- | ------------------ | ------------------ | ------------------ |
| **Space per node**            | 1 pointer         | 1 pointer          | 2 pointers         | 2 pointers         |
| **Traversal**                 | Forward only      | Forward only       | Forward & Backward | Forward & Backward |
| **End Detection**             | `nullptr`         | Back to `head`     | `nullptr`          | Back to `head`     |
| **Insertion at Beginning**    | Easy              | Easy               | Easy               | Easy               |
| **Insertion at End**          | O(n) without tail | O(1) with tail     | O(1) with tail     | O(1) with tail     |
| **Deletion at Beginning**     | Easy              | Easy               | Easy               | Easy               |
| **Deletion at End**           | O(n)              | O(n)               | O(1) if last known | O(1) if last known |
| **Backward Traversal**        | ❌                 | ❌                  | ✅                  | ✅             |
| **Memory Usage**              | Lowest            | Low                | High               | Highest            |
| **Implementation Difficulty** | Easiest           | Easy               | Medium             | Hardest            |

Singly Linked List
+ Less memory
+ Simple implementation
- Cannot move backward

Circular Singly Linked List <- second best according to bari
+ No NULL at end
+ Good for round-robin scheduling
- Cannot move backward

Doubly Linked List
+ Traverse both directions
+ Easier insertion/deletion
- Extra memory for prev pointer

Circular Doubly Linked List <- best according to bari
+ Traverse both directions
+ No NULL links
+ Efficient insertion/deletion at both ends
- Most complex
- Highest memory usage



