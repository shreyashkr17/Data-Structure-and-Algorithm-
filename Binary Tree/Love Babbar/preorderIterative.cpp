#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data){
    struct Node* node = new struct Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

void iterativePreorder(Node* root){
    if(root == NULL){
        return;
    }

    stack<Node*> nodeStack;
    nodeStack.push(root);

    while(nodeStack.empty() == false){
        struct Node* node = nodeStack.top();
        cout<<node->data<<" ";
        nodeStack.pop();

        if(node->right){
            nodeStack.push(node->right);
        }

        if(node->left){
            nodeStack.push(node->left);
        }
    }
}

int main(){

    struct Node* root = newNode(10);
    root->left = newNode(8);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
    root->right->left = newNode(2);
    iterativePreorder(root);
    return 0;
}