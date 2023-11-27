#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    ///construvctor
    Node(int d){
        this-> data=d;
        this -> prev=NULL;
        this -> next=NULL;
    }
};
//traversing linkd list
void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp -> data<<" ";
        temp=temp -> next;

    }cout<<endl;

}

//insert at head
void insertAtHead( Node* &head,Node* &tail,int d){
    //if list is empty
    if(head==NULL){
        Node* temp=new Node(d);
        head=temp;
        tail=head;
    }
    else{
        Node* temp=new Node(d);
        temp ->next=head;
        head ->prev=temp;
        head =temp;
    }
}
// insert at tail
void insertAtTail(Node* &head,Node* &tail, int d) {
    if(tail == NULL) {
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else{
        Node* temp = new Node(d);
        tail -> next  = temp;
        temp -> prev = tail;
        tail = temp;
    }

}
void deleteNode(int position, Node* & head,Node* &tail) { 

    //deleting first or start node
    if(position == 1) {
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp ->next;
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

       if(curr->next==NULL){
        tail=prev;
        prev->next=NULL;
        curr->prev=NULL;
       }
      
      //  curr -> prev = NULL;
        prev -> next = curr -> next;
        curr->next->prev=prev;
        curr -> next = NULL;
        curr->prev=NULL;
        delete curr;

    }
}





int main(){

Node* node1=new Node(10);
Node* head=node1;
Node* tail=node1;
print (head);
cout<<head;
cout<<endl<<head -> next;
for(int i=0;i<5;i++){
    insertAtTail(head,tail,i+10);
    print (head);

}
print (head);

deleteNode(4,head,tail);
deleteNode(3,head,tail);
print (head);
cout<<tail->prev->data;
cout<<endl;
cout<<head->next->next->data;

}