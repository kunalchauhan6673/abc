#include<bits/stdc++.h>
using namespace std;
class Node{
 public:
 int data;
 Node *next;
};
class que{
 private:
     Node *fr,*rr;
 public:
    que(){
    fr=rr=nullptr;
    }
    void enqueue(int data){
    Node *t=new Node();
    t->data=data;
    t->next=nullptr;
    if(rr==nullptr){
        fr=rr=t;
    }
    else{
    rr->next=t;
    rr=t;
    }
    }

    int dequeue(){
    if(fr==nullptr){
        cout<<"Queue is empty..."<<endl;
        return -1;
    }
    Node *ptr=fr;
    int x=ptr->data;
    fr=ptr->next;
   if(fr == nullptr){
    rr = nullptr;
   }
    delete ptr;
    return x;
    }

    void display(){
      if(fr==nullptr){
        cout<<"Queue is empty..."<<endl;
        return;
    }
   Node *ptr = fr;
   while(ptr){
    cout<<ptr->data<<" ";
    ptr = ptr->next;
    }
    cout<<endl;
    }
};
int main(){
 que obj;
 obj.enqueue(10);
 obj.enqueue(20);
 obj.enqueue(30);
 obj.enqueue(40);
 obj.enqueue(50);
 obj.display();

 cout<<"The dequeued element is: "<<obj.dequeue()<<endl;
 obj.display();
 obj.enqueue(10);
 obj.display();
}
