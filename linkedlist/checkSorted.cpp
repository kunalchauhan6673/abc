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
bool checkSorted(Node *ptr){
  if(ptr==nullptr){
    cout<<"Linklist is empty";
    return true;
  }
  // Node *ctr=nullptr; no need to use two pointers, instead use this: ptr->next->data!
  while(ptr->next!=nullptr){
    if(ptr->data>ptr->next->data){
        return false;
    }
    ptr=ptr->next;
  }
  return true;
}
int main(){
 insert(0,10);
 insert(1,20);
 insert(2,30);
 insert(3,40);
 insert(4,50);
 insert(5,60);
 display(head);
 bool flag = checkSorted(head);
 if(flag){
    cout<<"The list is sorted!";
 }
 else{
    cout<<"The list is not sorted";
 }
 return 0;
}

