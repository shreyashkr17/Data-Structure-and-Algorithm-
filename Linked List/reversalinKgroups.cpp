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

Node* kReverse(Node* head,int k){
    if(head == NULL){
        return NULL;
    }

    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int count = 0;

    while(curr != NULL && count<k){
        next = curr->next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if(next != NULL){
        head -> next = kReverse(next,k);
    }

    return prev;

}

int main(){
    
    return 0;
}