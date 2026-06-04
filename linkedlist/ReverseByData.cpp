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
void reversebydata(Node *ptr){
 if(head==nullptr){
    cout<<"The linklist is empty!"<<endl;
    return;
 }
 int size=0;
 while(ptr!=nullptr){
    size++;
    ptr=ptr->next;
 }
 int a[size]={0};
 ptr=head;
 for(int i=size-1;i>=0&&ptr;i--){
    if(ptr){
        a[i]=ptr->data;
        ptr=ptr->next;
    }
 }
 ptr=head;
 for(int i=0;i<size&&ptr;i++){
    if(ptr){
       ptr->data=a[i];
       ptr=ptr->next;
    }
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
 reversebydata(head);
 display(head);
 return 0;
}


