#include<bits/stdc++.h>
using namespace std;
class Node{
 public:
 int data;
 Node *next;
};
Node *head=nullptr;
Node *last=nullptr;

// 1. Create
void create(int a[],int size){

 head = new Node;
 head->data=a[0];
 head->next=head;

 Node *t;
 last=head;
 for(int i=1;i<size;i++){
     t= new Node;
     t->data=a[i];
     t->next=head;

     last->next=t;
     last=t;
 }
}

// 2. Display
void display(){
 if(head==nullptr){
    cout<<"The list is empty!"<<endl;
    return;
 }
 Node *ptr=head;
  do{
    cout<<ptr->data<<" ";
    ptr=ptr->next;
  }while(ptr!=head);
  cout<<endl;
}

// 3. Count
int countNodes(){
 if(head==nullptr){
    return 0;
 }
 int c=0;
 Node *ptr=head;
 do{
     c++;
     ptr=ptr->next;
 }
 while(ptr!=head);
 return c;
}

// 4. Insert at a position
void insertAtpos(int pos,int data){
 if(head==nullptr){
    if(pos == 0)
    {
        Node *t = new Node;
        t->data = data;
        t->next = t;

        head = last = t;
    }
    return;
 }
 if(pos<0||pos>countNodes()){
    cout<<"Invalid index!"<<endl;
    return;
 }
 else{
    Node *ptr=head;
    Node *t= new Node;
    t->data=data;

    if(pos==0){
        t->next=head;
        head=t;
        last->next=t;
    }else{

    for(int i=0;i<pos-1;i++){
        ptr=ptr->next;
    }
    if(ptr == last){
       // if insertion at last
       last = t;
    }
    t->next=ptr->next;
    ptr->next=t;
    }
 }
}

// 5. delete from a position
int deleteFrompos(int pos)
{
  if(head==nullptr){
   cout<<"The linklist is empty"<<endl;
   return -1;
  }
  if(pos<0||pos>=countNodes()){
   cout<<"Invalid pos!"<<endl;
   return -1;
  }
  else{
  int key;
  if(pos==0){
    if(head==last){
        // if that node is the only node
        key=head->data;
        delete head;
        head=last=nullptr;
        return key;
    }
    Node *ptr=head;
    key=ptr->data;
    head=ptr->next;
    last->next=head;
    delete ptr;
    return key;
  }
  else{
    Node *ptr=head;
    for(int i=0;i<pos-1;i++){
        ptr=ptr->next;
    }
    Node *del=ptr->next;
    key=del->data;

    if(del==last){
        // if that node is the last
        last=ptr;
    }
    ptr->next=del->next;
    delete del;
    return key;
  }
  }
}
int main(){
 int a[]={1,2,3,4,5};
 create(a,5);
 display();
 insertAtpos(0,100);
 insertAtpos(3,10);
 insertAtpos(6,1000);
 display();
 cout<<"The Element popped is: "<<deleteFrompos(1)<<endl;
 display();
 return 0;
}

