#include<iostream>
using namespace std;
//Singly linked list node stucture
class Node{
    public:
    int data;
    Node* next;
    Node(int new_data){
        this->data=new_data;
        this->next=nullptr;
    }
};
int main(){
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next=new Node(30);
    head->next->next->next= new Node(40);
    head->next->next->next->next= new Node(50);
    head->next->next->next->next->next= new Node(60);


    Node* temp=head;
    while(temp !=nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}