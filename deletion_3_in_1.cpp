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
Node* deleteFirst(Node* head){
    if(head == nullptr){
        cout<<"List is empty"<<endl;
        return nullptr;
    }
    Node* temp=head;
    head=head->next;
    delete temp;
    return head;
}
Node* deleteLast(Node* head){
    if(head == nullptr){
        cout<<"List is empty"<<endl;
        return nullptr;
    }
    if(head->next == nullptr){
        delete head;
        return nullptr;
    }
    Node* secondLast=head;
    while(secondLast->next->next!=nullptr){
        secondLast=secondLast->next;
    }
    delete secondLast->next;
    secondLast->next=nullptr;
    return head;
}
Node* deleteAfter(Node* head, int key){
    Node* curr=head;
    while(curr!=nullptr && curr->data!=key){
        curr=curr->next;
    }
    if(curr==nullptr){
        cout<<key<<" not found"<<endl;
        return head;
    }
    if(curr->next==nullptr){
        cout<<"No node after "<<key<<endl;
        return head;
    }
    Node* temp=curr->next;
    curr->next=temp->next;
    delete temp;
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
    Node* head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);
    head->next->next->next->next->next=new Node(6);

    cout<<"Original: ";
    printList(head);

    head=deleteFirst(head);
    cout<<"After deleteFirst(): ";
    printList(head);

    head=deleteLast(head);
    cout<<"After deleteLast(): ";
    printList(head);

    head=deleteAfter(head, 3);
    cout<<"After deleteAfter(3): ";
    printList(head);

    return 0;
}