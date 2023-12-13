#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void inorder(Node<int>* root, vector<int> &in){
    if(root == NULL){
        return;
    }

    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}

Node<int>* flatten(Node<int>* root){
    vector<int> inorderVal;

    inorder(root,inorderVal);
    Node<int>* newRoot = new Node<int>(inorderVal[0]);

    Node<int>* curr = newRoot;

    for(int i = 1;i<n;i++){
        Ndoe<int>* temp = new Node<int>(inorderVal[i]);

        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    curr->left = NULL;
    curr->right = NULL;

    return newRoot;
}
 
int main(){
    
    return 0;
}