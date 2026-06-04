// delete first node
// delete a node from pos
#include<bits/stdc++.h>
using namespace std;
class Node{
 public:
 int data;
 Node *next;
};
Node *head = nullptr;
void insert(int pos,int data){

  if(pos==0){
    Node *ptr= new Node;
    ptr->data=data;
    ptr->next=head;
    head=ptr;
  }
  else if(pos>0){

        Node *p = head;
        for(int i=0;i<pos-1&&p;i++){
            p=p->next;
        }
        if(p){
        Node *ptr= new Node;
        ptr->data=data;
        ptr->next=p->next;
        p->next=ptr;
        }
  } else{
     cout<<"Invalid Index!";
  }
 }
int deleteNode(int pos){
 if(head==nullptr){
    cout<<"Linkedlist is empty!";
    return -1;
 }
 Node *ptr=head;
 int d=0;
 if(pos==0){
    head=ptr->next;
    d=ptr->data;
    delete(ptr);
    return d;
 }
 if(pos>0){
    Node *ctr = nullptr;
    for(int i=0;i<pos&&ptr;i++){
       ctr=ptr;
       ptr=ptr->next;
    }
    if(ptr){
    ctr->next=ptr->next;
    d=ptr->data;
    delete(ptr);
    }
    return d;
 } else{
 cout<<"Invalid pos!";
 return -1;
 }
}
void display(Node *p){
 while(p!=nullptr){
    cout<<p->data<<" ";
    p=p->next;
 }
 cout<<endl;
}
int main(){
 insert(0,12);
 insert(1,11);
 insert(2,10);
 display(head);
 insert(3,13);
 display(head);
 int a= deleteNode(0);
 cout<<"Data deleted: "<<a<<endl;
 display(head);
 int b = deleteNode(2);
 cout<<"Data deleted: "<<b<<endl;
 display(head);
 return 0;
}

