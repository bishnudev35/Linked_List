

#include<iostream>
using namespace std;
 class Node{
    public:
    int data;
   Node* next;

   //constructor
   Node(int data){
    this -> data=data;
    this -> next=NULL;
   } 
 };
 
 void insertAtHead(Node* &head,int d){
    //new node creation
    Node* temp=new Node(d);
    temp -> next = head;
    head=temp;
 }
 void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
cout<<temp -> data<<" ";
temp=temp -> next;
    }
    cout<< endl;
 }
 void insertAtTail(Node* &tail, int d){
    //new node creation
    Node* temp=new Node(d);
    tail -> next=temp;
    tail = temp;
 }

 void insertAtPosition(Node* &head,Node* &tail,int position,int d){
    //insert at start
    if (position==1){
        insertAtHead(head,d);
        return;
    }
    
    Node* temp=head;
    int cnt=1;
    while(cnt<position-1){
        temp=temp -> next;
        cnt++;
    }
//if the position is the last position
if(temp -> next==NULL){
    insertAtTail(tail,d);
    return;
}
//creat a node for d
Node* nodeToInsert=new Node(d);
nodeToInsert -> next=temp -> next;
temp -> next=nodeToInsert;
 }
 void deleteNode(int position, Node* &head, Node* &tail){
    //deliting first or start node
    if(position==1){
        Node* temp=head;
        head=head -> next;
        //memory free start node
        temp -> next=NULL;
        delete temp;
    }
    else{
        //deliting any middle or last node
        Node*curr=head;
        Node* prev=NULL;
        int cnt=1;
        while(cnt<position){
            prev=curr;
            curr=curr -> next;
            cnt++;
        }
        //update tail
        if(curr ->next==NULL){
            tail=prev;
        }
        prev -> next=curr -> next;

        curr -> next=NULL;
        delete curr;
    }
 }

int main(){
    //creat a new node
    Node* node1 = new Node(10);
  //  cout<<node1-> data<<" ";
    //cout<<node1 ->next<<endl;
    //head point to node 1
    Node* head=node1;
    Node* tail=node1;
    print(head);
    
    insertAtHead(head,12);
    print(head);
    insertAtTail(tail,15);
    print(head);
     insertAtPosition(head,tail,4,19);
     print (head);
cout<<head -> data<<endl;
cout<<tail-> data<<endl;
 deleteNode(4,head,tail);
     print (head);
cout<<head -> data<<endl;
cout<<tail-> data<<endl;
    return 0;
}