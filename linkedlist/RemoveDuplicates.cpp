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
void RemoveDup(Node *ctr){
  if(head==nullptr){
    cout<<"The list is empty!";
    return;
  }
  Node *ptr=ctr->next; //forward pointer and ctr is tail pointer
  while(ptr!=nullptr){
    if(ctr->data==ptr->data){
        ctr->next=ptr->next;
        cout<<"The data deleted is: "<<ptr->data<<endl;
        delete ptr;
        ptr = ctr->next;
    }
    else{
        ctr=ptr;
        ptr=ctr->next;
    }
  }
}
int main(){
 insert(0,10);
 insert(1,10);
 insert(2,30);
 insert(3,30);
 insert(4,50);
 insert(5,60);
 insert(6,70);
 display(head);
 RemoveDup(head);
 display(head);
 return 0;
}


