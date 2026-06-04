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
void reversebylist(Node *q, Node *p){
 if(p!=nullptr){
    reversebylist(p,p->next);
    p->next=q;
 }
 else{
    // at the very last call, q=60 and p=Null, thats why we put head = q, not p
    head=q;
 }
}
int main(){
 insert(0,10);
 insert(1,20);
 insert(2,30);
 insert(3,40);
 insert(4,50);
 insert(5,60);
 display(head);
 reversebylist(nullptr,head);
 display(head);
 return 0;
}



