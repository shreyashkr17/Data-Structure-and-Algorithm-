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

void insertNode(Node* &tail,int element,int d){
    if(tail == NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }else{
        Node* curr =tail;
        while(curr->data != element){
            curr = curr->next;
        }

        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(Node* tail){
    Node* temp = tail;
    if(tail == tail){
        cout<<"List is Empty"<<endl;
        return;
    }

    do{
        cout<<tail->data<<" ";
        tail = tail->next;
    }while(tail!=temp);

    cout<<endl;
}

void dleeeteNode(Node* &tail,int value){
    if(tail == NULL){
        cout<<"List is empty"<<endl;
        return;
    }else{
        Node* prev = tail;
        Node* curr = prev->next;

        while(curr->data != value){
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        if(curr == prev){
            tail = NULL;
        }

        else if(tail == curr){
            tail = prev;
        }

        curr->next = NULL;
        delete curr;
    }
}

bool isCircular(Node* head){
    if(head == NULL){
        return false;
    }

    map<Node*,bool> visited;

    Node* temp = head;


    while(temp != NULL){
        if(visited[temp] == true){
            return true;
        }

        visited[temp] = true;
        temp = temp->next;
    }

    return false;
}

int main(){
    
    return 0;
}