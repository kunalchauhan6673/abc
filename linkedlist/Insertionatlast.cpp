#include<bits/stdc++.h>
using namespace std;
class Node{
 public:
 int data;
 Node *next;
};
Node *head = nullptr;
Node *last = nullptr;
void insert(int data){
    Node *ptr=new Node;
    ptr->data=data;
    ptr->next=nullptr;
    // for first node
    if(head==nullptr){
        head=last=ptr;
        return;
    }
    // for other nodes
    last->next=ptr;
    last = ptr;
}

void display(Node *p){
 while(p!=nullptr){
    cout<<p->data<<" ";
    p=p->next;
 }
 cout<<endl;
}
int main(){
 insert(10);
 display(head);
 insert(100);
 insert(1000);
 display(head);
}
