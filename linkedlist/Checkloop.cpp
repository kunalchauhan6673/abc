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

// we are using tortoise and hare algorithm here
// also called slow and fast pointer
// also called floyd' algo
bool isLoop(Node *first){
 Node *p,*q;
 p=q=first;
 do{
    p=p->next;
    q=q->next;

    q=q?q->next:q; // if q is valid, then q=q->next
    // else q = nullptr, which it is in case of non valid
 }while(p&&q&&p!=q);
 return p==q;
}

int main(){
 insert(0,10);
 insert(1,20);
 insert(2,30);
 insert(3,40);
 insert(4,50);
 insert(5,60);
 display(head);

 Node *t1,*t2;
 t1=head->next->next;
 t2=head->next->next->next->next;
 t2->next=t1;

 if(isLoop(head)){
    cout<<"There is a loop!"<<endl;
 }
 else{
    cout<<"No loop exists!"<<endl;
 }
 return 0;
}


