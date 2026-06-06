#include<bits/stdc++.h>
using namespace std;
class Node{
 public:
 Node *prev;
 int data;
 Node *next;
};

Node *first=nullptr;
Node *last=nullptr;
void create(int a[],int size){

 first=new Node;
 first->data=a[0];
 first->prev=first->next=nullptr;
 last=first;

 for(int i=1;i<size;i++){
    Node *t=new Node;
    t->data=a[i];
    t->next=last->next;
    t->prev=last;
    last->next=t;
    last=t;
 }
}
void display(){
 if(first==nullptr){
    cout<<"Linklist is empty!"<<endl;
    return;
 }
 Node *ptr=first;
 while(ptr!=nullptr){
    cout<<ptr->data<<" ";
    ptr=ptr->next;
 }
 cout<<endl;
}
void reverseNodes(){
 Node *ptr= first;
 while(ptr!=nullptr){
    Node *t=ptr->next;
    ptr->next=ptr->prev;
    ptr->prev=t;

    if(ptr->prev==nullptr){
        first=ptr;
    }
    ptr=ptr->prev;
 }
}
int main(){
 int a[]={1,2,3,4,5};
 create(a,5);
 display();

 reverseNodes();
 display();
}
// index are from 0 so keep that in mind!

