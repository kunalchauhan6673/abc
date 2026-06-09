#include<bits/stdc++.h>
using namespace std;
class Node{
 public:
 int data;
 Node *next;
};
class Stack{
 Node *top;
 public:
     Stack(){
         top=nullptr;
     }
     ~Stack(){
      while(top!=nullptr){
        Node *temp=top;
        top=top->next;
        delete temp;
      }
     }

    // we generally dont need isFull in linklist implementation because
    // linklist becomes full only when no more heap memory is available.

    int isEmpty(){
     return top==nullptr;
    }

    void push(int data){
    Node *t= new Node;
    t->data=data;
    t->next=top;
    top=t;
    }
    int pop(){
    if(isEmpty()){
        cout<<"linklist is empty!"<<endl;
        return -1;
    }
    Node *t=top;
    int data = top->data;
    top=top->next;
    delete t;
    return data;
    }
    void display(){
    if(isEmpty()){
        cout<<"Linklist is empty"<<endl;
        return;
    }
    Node *ptr=top;
    while(ptr!=nullptr){
        cout<<ptr->data<<endl;
        ptr=ptr->next;
    }
    }
};
int main(){
 Stack s;
 s.push(10);
 s.push(20);
 s.push(30);
 s.push(40);
 cout<<"Popped element is: "<<s.pop()<<endl;
 s.display();
 return 0;
}
