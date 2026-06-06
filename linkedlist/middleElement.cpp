#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
};

Node *head = nullptr;

// Insert at end
void insert(int data)
{
    Node *t = new Node;
    t->data = data;
    t->next = nullptr;

    if(head == nullptr)
    {
        head = t;
        return;
    }

    Node *p = head;

    while(p->next != nullptr)
        p = p->next;

    p->next = t;
}

// Display
void display()
{
    Node *p = head;

    while(p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// Find Middle using Slow and Fast Pointer
Node* middleNode()
{
    if(head == nullptr)
        return nullptr;

    Node *slow = head;
    Node *fast = head->next;

    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main()
{
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    insert(60);

    cout << "Linked List: ";
    display();

    Node *mid = middleNode();

    if(mid)
        cout << "Middle Element: " << mid->data << endl;

    return 0;
}
