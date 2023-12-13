#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Node{
    public:
        int data;
        Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        int val = this->data;
        if(this->next != NULL){
            delete next;
            next = NULL;
        }
    }
};

Node* reverse(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    while(curr != NULL){
        next = curr->next;
        curr->next = NULL;
        prev = curr;
        curr = next;
    }

    return prev;
}

void insertAtTail(Node* &head,Node* &tail,int val){
    Node* temp = new Node(val);

    if(head == NULL){
        head = temp;
        tail = temp;
        return ;
    }else{
        tail->next = temp;
        tail = temp;
    }
}

Node* add(Node* first,Node* second){
    int carry = 0;

    Node* ansHead = NULL;
    Node* ansTail = NULL;

    while(first != NULL || second != NULL || carry != 0){
        int val1 = 0;
        if(first != NULL){
            val1 = first->data;
        }

        int val2 = 0;
        if(second != NULL){
            val2 = second->data;
        }

        int sum = carry + val1 + val2;
        int digit = sum%10;

        //create node and add in answer Linked List
        insertAtTail(ansHead,ansTail,digit);

        carry = sum/10;

        if(first != NULL){
            first = first->next;
        } 

        if(second != NULL){
            second = second->next;
        }
    }

    return ansHead;
}

Node* addTwoList(Node* first,Node* second){
    first = reverse(first);
    second = reverse(second);

    //add two List
    Node* ans = add(first,second);

    //step3
    ans = reverse(ans);

    return ans;
}

int main(){
    
    return 0;
}