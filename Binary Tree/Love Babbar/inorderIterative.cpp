#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

void InorderIterative(struct Node* root){
    stack<Node*> s;
    Node *curr = root;

    while(curr!=NULL || s.empty()){
        while(curr!=NULL){
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();

        cout<<curr->data<<" ";

        curr = curr->right;
    }
} 

int main(){
    
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    InorderIterative(root);
    
    return 0;
}