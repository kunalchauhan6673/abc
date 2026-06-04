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
int main(){
 insert(0,12);
 insert(1,11);
 insert(2,10);
 display(head);
 insert(10,01);
 display(head);
}

