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

Node* floydDetection(Node* head){
    if(head == NULL){
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while(slow!=NULL && fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
        }

        slow = slow->next;

        if(slow == fast){
            return slow;
        }

    }

    return NULL;
}

Node* getStartingNode(Node* head){
    if(head == NULL){
        return NULL;
    }

    Node* intersection = floydDetection(head);

    if(intersection == NULL){
        return NULL;
    }

    Node* slow = head;

    while(slow!=intersection){
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}

Node* removeLoop(Node* head){
    if(head == NULL){
        return NULL;
    }

    Node* startLoop = getStartingNode(head);

    if(startLoop == NULL){
        return NULL;
    }

    Node* temp = startLoop;

    while(temp->next != startLoop){
        temp = temp->next;
    }

    temp->next = NULL;
    return head;
}

int main(){
    
    return 0;
}