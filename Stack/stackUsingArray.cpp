#include<bits/stdc++.h>
using namespace std;
class Stack{
 int top;
 int size;
 int *s;

 public:
     Stack(int size){
      this->size=size;
      top=-1;
      s = new int[size];
     }
     ~Stack(){
      delete[] s;
     }

     int isFull(){
      return top==size-1;
     }

     int isEmpty(){
      return top==-1;
     }

     void push(int data){
      if(isFull()){
        cout<<"Stack overflow.."<<endl;
      }
      else{
        top++;
        s[top]=data;
      }
     }

     int pop(){
      if(isEmpty()){
        cout<<"Stack underflow.."<<endl;
        return -1;
      }
       int x=s[top];
       top--;
       return x;
     }

     int peek(int pos){
      int index=top-pos+1;
      if(pos<=0||index<0){
        cout<<"invalid position\n";
        return -1;
      }
      return s[index];
     }

     int StackTop(){
      if(isEmpty()){
        cout<<"Stack is empty.."<<endl;
        return -1;
      }
      return s[top];
     }

     void display(){
      if(isEmpty()){
        cout<<"Stack underflow!"<<endl;
      }
      else{
        for(int i=top;i>=0;i--){
            cout<<s[i]<<endl;
        }
        cout<<endl;
      }
     }
};
int main(){
 Stack obj(5);
 obj.push(1);
 obj.push(2);
 obj.push(3);
 obj.push(4);
 obj.push(5);
 obj.push(6); // stack overflow
 obj.display();
 cout<<"Popped element is "<<obj.pop()<<endl;
 obj.display();
 cout<<"Element at a pos is "<<obj.peek(4)<<endl;
 obj.display();
 cout<<"Top element is "<<obj.StackTop()<<endl;
 obj.display();
}
