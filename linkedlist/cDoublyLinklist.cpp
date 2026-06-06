// circular double linked list
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
int countNodes(){
 if(first==nullptr){
    return 0;
 }
 int c=0;
 Node *ptr = first;
 while(ptr!=nullptr){
    ptr=ptr->next;
    c++;
 }
 return c;
}
void insertAtpos(int pos, int data){
 if(first==nullptr){
    cout<<"The linklist is empty"<<endl;
    return;
 }
 if(pos<0||pos>countNodes()){
    cout<<"invalid index!"<<endl;
    return;
 }else{

  if(pos==0){
    Node *ptr=new Node;
    ptr->data=data;
    ptr->next=first;
    ptr->prev=nullptr;
    first->prev=ptr;
    first=ptr;
    return;
  }
  if(pos>0){
    Node *ptr=first;
    Node *t= new Node;
    t->data=data;
    for(int i=0;i<pos-1;i++){
     ptr=ptr->next;
    }
    Node *ctr=ptr->next;
    t->next=ctr;
    t->prev=ptr;
    ptr->next=t;

    if(ctr){
        ctr->prev=t;
    }else{
    last=t;
    }
  }
 }
}
int deleteFrompos(int pos){
    if(first==nullptr){
        cout<<"Link list is empty"<<endl;
        return -1;
    }
    if(pos<0||pos>=countNodes()){
        cout<<"invalid position"<<endl;
        return -1;
    }
    else{
        int key;
        if(pos==0){
            if(first==last){
                key=first->data;
                delete first;
                first=last=nullptr;
                return key;
            }
            key=first->data;
            Node *ptr=first;
            first=ptr->next;
            first->prev=nullptr;
            delete ptr;
            return key;
        }
        else{

            Node *ptr=first;
            for(int i=0;i<pos-1;i++){
                ptr=ptr->next;
            }
            Node *del=ptr->next;
            key=del->data;
            ptr->next=del->next;

            if(del->next){
               del->next->prev=ptr;
            }else{
               last=ptr;
            }
            delete del;
            return key;
        }
    }
}
int main(){
 int a[]={1,2,3,4,5};
 create(a,5);
 display();
 insertAtpos(0,10);
 display();
 insertAtpos(4,70);
 display();
 cout<<"Deleted: "<<deleteFrompos(0)<<endl;
 display();
 cout<<"Deleted: "<<deleteFrompos(3)<<endl;
 display();
 cout<<"Deleted: "<<deleteFrompos(4)<<endl;
 display();
}
// index are from 0 so keep that in mind!
