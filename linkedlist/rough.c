#include<bits/stdc++.h>
using namespace std;
struct Node{
 int data;
 struct Node* next;
};
int main(){
 struct Node *p,*p1,*p2;
 p=new Node;
 p1=new Node;
 p2=new Node;
 p->data=100;
 p->next=p1;

 p1->data=101;
 p1->next=p2;

 p2->data=102;
 p2->next=0;

 struct Node *head=p;
 while(head!=NULL){
    cout<<head->data<<"|"<<head->next<<"  ";
    head=head->next;
 }
}
