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

void display(Node *p){
 while(p!=nullptr){
    cout<<p->data<<" ";
    p=p->next;
 }
 cout<<endl;
}

void insertSorted(int key){
 Node *ptr= new Node;
 ptr->data=key;
 ptr->next=nullptr;

 // if linklist is empty
  if(head==nullptr){
    head=ptr;
    return;
 }

 Node *p=head;
 Node *q=nullptr;

 // if data is less than the first node
 if(p->data>key){
    ptr->next=p;
    head=ptr;
    return;
 }
 // if data needs to be put at last or in between
 while(p&&p->data<key){
   q=p;
   p=p->next;
 }
 ptr->next=p;
 q->next=ptr;
}
int main(){
 insert(0,5);
 insert(1,10);
 insert(2,50);
 display(head);
 insert(3,100);
 display(head);
 insertSorted(1);
 display(head);
}
