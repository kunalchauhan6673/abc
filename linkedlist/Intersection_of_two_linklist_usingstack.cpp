#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
};

Node* findIntersection(Node *first, Node *second)
{
    stack<Node*> stk1;
    stack<Node*> stk2;

    Node *p = first;

    while(p)
    {
        stk1.push(p);
        p = p->next;
    }

    p = second;

    while(p)
    {
        stk2.push(p);
        p = p->next;
    }

    Node *q = nullptr;

    while(!stk1.empty() && !stk2.empty() &&
          stk1.top() == stk2.top())
    {
        q = stk1.top();

        stk1.pop();
        stk2.pop();
    }

    return q;
}

int main()
{
    // First List
    Node *first = new Node{8};
    first->next = new Node{6};
    first->next->next = new Node{3};
    first->next->next->next = new Node{9};
    first->next->next->next->next = new Node{10};
    first->next->next->next->next->next = new Node{4};
    first->next->next->next->next->next->next = new Node{2};
    first->next->next->next->next->next->next->next = new Node{12};

    // Second List
    Node *second = new Node{20};
    second->next = new Node{30};
    second->next->next = new Node{40};

    // Intersection at node 10
    second->next->next->next =
        first->next->next->next->next;

    Node *ans = findIntersection(first, second);

    if(ans)
        cout << "Intersection Node: "
             << ans->data << endl;
    else
        cout << "No Intersection Found!" << endl;

    return 0;
}
