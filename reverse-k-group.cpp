#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(NULL) {}
};

bool cheack(Node* head,int k){
    int len=0;
    Node*temp=head;
while(temp!=NULL){
    len++;
    temp=temp->next;
    if(len==k){
        return true;
        break;}
}
     return false;
}
Node* kReverse(Node* head, int k) {
    //base call
    if(head == NULL) {
        return NULL;
    }
    
    //step1: reverse first k nodes
    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int count= 0;
    if(cheack(curr,k)){
        while (curr != NULL && count < k) {
           next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
        }
    }
    else
    return head;
    //  else{
    //     while (curr != NULL) {
    //       head->next = curr;
    //       prev=curr;
    //       curr=curr->next;
    //     }
    // }

    //step2: Recursion dekhlega aage ka
    if (next != NULL) {
        head->next = kReverse(next, k);
    }

    // step3: return head of reversed list
    return prev;
}

void printList(Node* head) {
    while (head != NULL) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    Node* head = new Node(6);
    head->next = new Node(5);
    head->next->next = new Node(4);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(7);
    head->next->next->next->next->next = new Node(9);
    head->next->next->next->next->next->next = new Node(2);

    std::cout << "Original List: ";
    printList(head);

    int k = 4;  // Set the value of k

    head = kReverse(head, k);

    std::cout << "Reversed List: ";
    printList(head);

    return 0;
}
