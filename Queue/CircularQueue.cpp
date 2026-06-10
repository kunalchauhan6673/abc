#include<bits/stdc++.h>
using namespace std;

class que{
private:
    int fr;
    int rr;
    int size;
    int *Q;

public:
    que(int size){
        this->size = size;
        fr = rr = 0;
        Q = new int[size];
    }

    ~que(){
        delete[] Q;
    }

    void enqueue(int data){

        if((rr + 1) % size == fr){
            cout<<"Queue is full..."<<endl;
            return;
        }

        rr = (rr + 1) % size;
        Q[rr] = data;
    }

    int dequeue(){

        if(fr == rr){
            cout<<"Queue is empty!"<<endl;
            return -1;
        }

        fr = (fr + 1) % size;
        return Q[fr];
    }

    void display(){

    if(fr == rr){
        cout<<"Queue is empty!"<<endl;
        return;
    }

    int i = (fr + 1) % size;

    do{
        cout << Q[i] << " ";
        i = (i + 1) % size;
    }while(i != (rr + 1) % size);

    cout << endl;
}
};

int main(){

    que obj(6);   // Can store 5 elements

    obj.enqueue(10);
    obj.enqueue(20);
    obj.enqueue(30);
    obj.enqueue(40);
    obj.enqueue(50);

    obj.display();

    cout<<"Dequeued element is: "<<obj.dequeue()<<endl;

    obj.display();

    obj.enqueue(60);
    obj.display();
}
