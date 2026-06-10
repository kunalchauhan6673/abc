//output restricted dequeue
#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node *next;
};
class Deq{
  private:
      Node *fr,*rr;
  public:
    Deq(){
     fr=rr=nullptr;
    }
    void enqueuebyRear(int data){
     Node *t=new Node;
     t->data=data;
     t->next=nullptr;
     if(rr==nullptr){
        fr=rr=t;
     }else{
      rr->next=t;
      rr=t;
     }
    }
    void enqueuebyFront(int data){
     Node *t=new Node;
     t->data=data;
     t->next=nullptr;
     if(fr==nullptr){
        fr=rr=t;
     }else{
      t->next=fr;
      fr=t;
     }
    }
    int dequeueByFront(){
     if(fr==nullptr){
        cout<<"The queue is empty..."<<endl;
        return -1;
     }
     Node *ptr=fr;
     int x=ptr->data;

     if(fr==rr){
        fr=rr=nullptr;
     } else{
        fr=fr->next;
     }
     delete ptr;
     return x;
    }

int dequeueByRear()
{
    if(fr==nullptr)
    {
        cout<<"The queue is empty..."<<endl;
        return -1;
    }
    if(fr==rr)
    {
        int x=fr->data;
        delete fr;
        fr=rr=nullptr;
        return x;
    }

    Node *prev=nullptr;
    Node *curr=fr;
    while(curr->next)
    {
        prev=curr;
        curr=curr->next;
    }
    int x=curr->data;
    rr=prev;
    rr->next=nullptr;
    delete curr;
    return x;
}
    void display(){
    if(fr==nullptr){
        cout<<"The queue is empty..."<<endl;
        return;
    }
    Node *ptr = fr;
    while(ptr){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
    }
};

int main(){
  Deq obj;
  obj.enqueuebyFront(10);
  obj.enqueuebyFront(20);
  obj.enqueuebyFront(30);
  obj.enqueuebyRear(40);
  obj.enqueuebyRear(50);
  obj.enqueuebyRear(60);

  obj.display();

  cout<<"The element dequeued is : "<<obj.dequeueByFront()<<endl;
  obj.display();

  cout<<"The element dequeued is : "<<obj.dequeueByRear()<<endl;
  obj.display();
  return 0;
}
