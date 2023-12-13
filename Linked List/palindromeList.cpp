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
        int value = this->data;

        if(this->next != NULL){
            delete next;
            next = NULL;
        }
    }
};

Node* getMid(Node* head){
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

Node* reverse(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

bool isPalindrome(Node* head){
    if(head->next == NULL){
        return true;
    }

    //step 1 -> find Middle
    Node* middle = getMid(head);


    //step 2->reverse List after Middle
    Node* temp = middle->next;
    middle->next = reverse(temp);

    //compare both halves
    Node* head1 = head;
    Node* head2 = middle->next;

    while(head2 != NULL){
        if(head2->data != head1->data){
            return 0;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    //step4 - repeat step 2
    temp = middle->next;
    middle->next = reverse(temp);

    return true;
}

Node* getMid(Node* head){

}

int main(){
    
    return 0;
}