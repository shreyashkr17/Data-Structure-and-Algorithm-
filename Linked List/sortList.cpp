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
        if(this->next!=NULL){
            delete next;
            next = NULL;
        }
    }
};

void insertAtTail(Node* &tail,Node* curr){
    tail->next = curr;
    tail = curr;
}

Node* sortList(Node* head){
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;

    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;

    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head;

    while(curr != NULL){
        int value = curr->data;

        if(value == 0){
            insertAtTail(zeroTail,curr);
        }else if(value == 1){
            insertAtTail(oneTail,curr);
        }else if(value == 2){
            insertAtTail(twoTail,curr);
        }

        curr = curr->next;
    }

    //merge 3 sublist

    //1s list not empty
    if(oneHead->next != NULL){
        zeroTail->next = oneHead->next;
    }else{
        zeroTail->next = twoHead->next;
    }

    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    head = zeroHead;
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}

int main(){
    
    return 0;
}