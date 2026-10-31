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
Node* insertAfter(Node* head, int key, int x){
    Node* curr=head;
    while(curr!=nullptr && curr->data!=key){
        curr=curr->next;
    }
    if(curr==nullptr){
        cout<<key<<" paowa jayni"<<endl;
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

    int key=3;
    int x=10;
    head=insertAfter(head, key, x);
    printList(head);
    
}