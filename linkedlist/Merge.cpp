#include<bits/stdc++.h>
using namespace std;
class Node{
 public:
 int data;
 Node *next;
};
Node *head1 = nullptr;
Node *head2 = nullptr;
void insert(Node *&head, int pos,int data){

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
Node* mergelists(Node *first, Node *second){
 Node *last=nullptr;
 Node *third=nullptr;
 if(first->data<second->data){
    last=third=first;
    first=first->next;
    last->next=nullptr;
 }else{
   last=third=second;
   second=second->next;
   last->next=nullptr;
 }
 while(first&&second){
    if(first->data<second->data){
        last->next=first;
        last=first;
        first=first->next;
        last->next=nullptr;
    }else{
        last->next=second;
        last=second;
        second=second->next;
        last->next=nullptr;
    }
 }
 if(first){
    last->next=first;
 }
 else{
    second->next=second;
 }
 return third;

}
int main(){
 insert(head1,0,10);
 insert(head1,1,20);
 insert(head1,2,30);
 insert(head2,0,5);
 insert(head2,1,15);
 insert(head2,2,25);
 display(head1);
 display(head2);

 Node *newhead = mergelists(head1,head2);
 display(newhead);
 return 0;
}



