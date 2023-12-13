#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Node{
    public:
        int data;
        Node* next;

    Node(int d){
        this->data = d;
        this->next = NULL;
    }

    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            next = NULL;
        }

        cout<<"Memory is deleted"<<endl;
    }
};

Node* uniqueSortedList(Node* head){
    if(head == NULL){
        return NULL;
    }

    Node* curr = head;
    while(curr != NULL){
        if((curr->next != NULL) && curr->data == curr->next->data){
            Node* next_next = curr->next->next;
            Node* nodeToDelete = curr->next;
            delete nodeTodelete;
            curr->next = next_next;
        }else{
            curr = curr->next;
        }
    }
}

int main(){
    
    return 0;
}