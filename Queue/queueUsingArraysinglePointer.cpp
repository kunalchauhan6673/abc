#include<bits/stdc++.h>
using namespace std;
class que{
 private:
    // int fr;
     int rr;
     int size;
     int *Q;
 public:
    que(){
    rr=-1;
    size=0;
    Q = nullptr;
    }
    que(int size){
    this->size=size;
    rr=-1;
    Q = new int[this->size];
    }
    ~que(){
    delete[] Q;
     }
    void enqueue(int data){
    if(rr==size-1){
        cout<<"Queue is full..."<<endl;
        return;
    }
    Q[++rr]=data;
    }

    int dequeue(){
    if(rr==-1){
        cout<<"The queue is empty!"<<endl;
        return -1;
    }
    int x=Q[0]; // front most element
    for(int i=0;i<rr;i++){
        Q[i]=Q[i+1];
    }
    rr--;
    return x;
    }
    void display(){
    if(rr==-1){
        cout<<"The queue is empty!"<<endl;
        return;
    }
    for(int i=0;i<=rr;i++){
        cout<<Q[i]<<" ";
    }
    cout<<endl;
    }
};
int main(){
 que obj(5);

 obj.enqueue(10);
 obj.enqueue(20);
 obj.enqueue(30);
 obj.enqueue(40);
 obj.enqueue(50);
 obj.display();

 cout<<"The dequeued element is: "<<obj.dequeue()<<endl;
 obj.display();
}
// major limitation: not reusable!

