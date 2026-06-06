#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    Node *prev;
    int data;
    Node *next;
};

Node *first = nullptr;
Node *last = nullptr;

// Create
void create(int a[], int size)
{
    if(size == 0) return;

    first = new Node;
    first->data = a[0];
    first->next = first;
    first->prev = first;

    last = first;

    for(int i=1; i<size; i++)
    {
        Node *t = new Node;
        t->data = a[i];

        t->next = first;
        t->prev = last;

        last->next = t;
        first->prev = t;

        last = t;
    }
}

// Display
void display()
{
    if(first == nullptr)
    {
        cout << "Linked List is empty!" << endl;
        return;
    }

    Node *ptr = first;

    do{
        cout << ptr->data << " ";
        ptr = ptr->next;
    }while(ptr != first);

    cout << endl;
}

// Count
int countNodes()
{
    if(first == nullptr)
        return 0;

    int c = 0;
    Node *ptr = first;

    do{
        c++;
        ptr = ptr->next;
    }while(ptr != first);

    return c;
}

// Insert at Position
void insertAtpos(int pos, int data)
{
    if(pos < 0 || pos > countNodes())
    {
        cout << "Invalid index!" << endl;
        return;
    }

    // Empty List
    if(first == nullptr)
    {
        Node *t = new Node;
        t->data = data;

        t->next = t;
        t->prev = t;

        first = last = t;
        return;
    }

    // Insert at Beginning
    if(pos == 0)
    {
        Node *t = new Node;
        t->data = data;

        t->next = first;
        t->prev = last;

        first->prev = t;
        last->next = t;

        first = t;
        return;
    }

    Node *ptr = first;

    for(int i=0; i<pos-1; i++)
        ptr = ptr->next;

    Node *t = new Node;
    t->data = data;

    Node *ctr = ptr->next;

    t->next = ctr;
    t->prev = ptr;

    ptr->next = t;
    ctr->prev = t;

    if(ptr == last)
        last = t;
}

// Delete from Position
int deleteFrompos(int pos)
{
    if(first == nullptr)
    {
        cout << "Linked List is empty!" << endl;
        return -1;
    }

    if(pos < 0 || pos >= countNodes())
    {
        cout << "Invalid position!" << endl;
        return -1;
    }

    int key;

    // Delete First Node
    if(pos == 0)
    {
        if(first == last)
        {
            key = first->data;

            delete first;

            first = last = nullptr;

            return key;
        }

        Node *ptr = first;

        key = ptr->data;

        first = first->next;

        first->prev = last;
        last->next = first;

        delete ptr;

        return key;
    }

    Node *ptr = first;

    for(int i=0; i<pos-1; i++)
        ptr = ptr->next;

    Node *del = ptr->next;

    key = del->data;

    ptr->next = del->next;
    del->next->prev = ptr;

    if(del == last)
        last = ptr;

    delete del;

    return key;
}

int main()
{
    int a[] = {1,2,3,4,5};

    create(a,5);

    cout << "Original: ";
    display();

    insertAtpos(0,10);
    display();

    insertAtpos(4,70);
    display();

    insertAtpos(countNodes(),100);
    display();

    cout << "Deleted: " << deleteFrompos(0) << endl;
    display();

    cout << "Deleted: " << deleteFrompos(3) << endl;
    display();

    cout << "Deleted: " << deleteFrompos(countNodes()-1) << endl;
    display();

    return 0;
}

/*
DLL → CDLL Key Points

1. No nullptr at the ends
   DLL:
      first->prev = nullptr;
      last->next = nullptr;

   CDLL:
      first->prev = last;
      last->next = first;

--------------------------------------------------

2. Traversal
   DLL:
      while(ptr != nullptr)

   CDLL:
      do{
          ...
          ptr = ptr->next;
      }while(ptr != first);

--------------------------------------------------

3. Counting Nodes
   Stop when:
      ptr == first

   Not when:
      ptr == nullptr

--------------------------------------------------

4. Insert at Beginning
   Update 4 links:

      t->next = first;
      t->prev = last;

      first->prev = t;
      last->next = t;

      first = t;

--------------------------------------------------

5. Delete at Beginning
   Update 4 links:

      first = first->next;

      first->prev = last;
      last->next = first;

--------------------------------------------------

6. Detect Last Node
   DLL:
      if(node->next == nullptr)

   CDLL:
      if(node == last)

--------------------------------------------------

7. Single Node CDLL

      node->next = node;
      node->prev = node;

--------------------------------------------------

8. Empty List

      first = nullptr;
      last = nullptr;

--------------------------------------------------

Golden Rule:

After EVERY insertion/deletion, verify:

      first->prev == last;
      last->next == first;

If this invariant is true,
the Circular Doubly Linked List is usually correct.
*/
