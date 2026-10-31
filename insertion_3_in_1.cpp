#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=nullptr;
    }
};
Node* insertAtFront(Node* head, int x){
    Node* newNode=new Node(x);
    newNode->next=head;
    return newNode;
}
Node* insertAtEnd(Node* head, int x){
    Node* newNode=new Node(x);
    if(head == nullptr){
        return newNode;
    }
    Node* last=head;
    while(last->next!=nullptr){
        last=last->next;
    }
    last->next=newNode;
    return head;
}
Node* insertAfter(Node* head, int key, int x){
    Node* curr=head;
    while(curr!=nullptr && curr->data!=key){
        curr=curr->next;
    }
    if(curr==nullptr){
        cout<<key<<" not found"<<endl;
        return head;
    }
    Node* newNode=new Node(x);
    newNode->next=curr->next;
    curr->next=newNode;
    return head;
}
void printList(Node* head){
    Node* curr=head;
    while(curr!=nullptr){
        cout<<curr->data;
        if(curr->next!=nullptr){
            cout<<"->";
        }
        curr=curr->next;
    }
    cout<<endl;
}
int main(){
    Node* head=new Node(2);
    head->next=new Node(3);
    head->next->next=new Node(4);
    head->next->next->next=new Node(5);

    cout<<"Original: ";
    printList(head);

    head=insertAtFront(head, 1);
    cout<<"After insertAtFront(1): ";
    printList(head);

    head=insertAtEnd(head, 6);
    cout<<"After insertAtEnd(6): ";
    printList(head);

    head=insertAfter(head, 3, 10);
    cout<<"After insertAfter(3, 10): ";
    printList(head);

    return 0;
}