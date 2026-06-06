#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int coeff;
    int exp;
    Node *next;
};

Node *head = nullptr;

// Create Polynomial
void create()
{
    int n;

    cout<<"Enter number of terms: ";
    cin>>n;

    Node *last = nullptr;

    for(int i=0;i<n;i++)
    {
        Node *t = new Node;

        cout<<"Enter coefficient and exponent: ";
        cin>>t->coeff>>t->exp;

        t->next = nullptr;

        if(head == nullptr)
        {
            head = last = t;
        }
        else
        {
            last->next = t;
            last = t;
        }
    }
}

// Display Polynomial
void display()
{
    Node *p = head;

    while(p)
    {
        cout<<p->coeff<<"x^"<<p->exp;

        if(p->next)
            cout<<" + ";

        p = p->next;
    }

    cout<<endl;
}

// Evaluate Polynomial
double evaluate(int x)
{
    double sum = 0;

    Node *q = head;

    while(q)
    {
        sum += q->coeff * pow(x,q->exp);
        q = q->next;
    }

    return sum;
}

int main()
{
    create();

    cout<<"\nPolynomial: ";
    display();

    int x;
    cout<<"\nEnter value of x: ";
    cin>>x;

    cout<<"Result = "<<evaluate(x)<<endl;

    return 0;
}
