#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    char data;
    Node *next;
};

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = nullptr;
    }

    ~Stack()
    {
        while (top != nullptr)
        {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    void push(char data)
    {
        Node *t = new Node;
        t->data = data;
        t->next = top;
        top = t;
    }

    char pop()
    {
        if (isEmpty())
        {
            return '\0';
        }

        Node *t = top;
        char data = t->data;

        top = top->next;
        delete t;

        return data;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty\n";
            return;
        }

        Node *ptr = top;

        while (ptr != nullptr)
        {
            cout << ptr->data << endl;
            ptr = ptr->next;
        }
    }

    char stackTop(){
        if(isEmpty()){
            return '/0';
        }
        return top->data;
    }
};

bool isMatching(char open, char close){
 return (open=='(' && close ==')') || (open=='[' && close ==']') || (open=='{' && close =='}');
}
bool isBalanced(string exp)
{
    Stack s;

    for(int i=0;exp[i]!='\0';i++){

    if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
 {
    s.push(exp[i]);
 }
else if(exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
  {
    if(s.isEmpty())
        return false;

    if(!isMatching(s.stackTop(), exp[i]))
        return false;

    s.pop();
  }
                                }
    return s.isEmpty();
}

int main()
{
    string exp;

    cout << "Enter Expression: ";
    cin >> exp;

    if (isBalanced(exp))
    {
        cout << "Balanced Parentheses\n";
    }
    else
    {
        cout << "Not Balanced Parentheses\n";
    }

    return 0;
}

