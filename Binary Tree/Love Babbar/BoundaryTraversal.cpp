#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val){
    Node* temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
}

void TraversalLeft(Node* root,vector<int> &ans){
    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return;
    }

    ans.push_back(root->data);

    if(root->left){
        TraversalLeft(root->left,ans);
    }else{
        TraversalLeft(root->right,ans);
    }
}

void TraversalLeaf(Node* root,vector<int>& ans){
    if(root == NULL){
        return;
    }

    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
        return;
    }

    TraversalLeaf(root->left,ans);
    TraversalLeaf(root->right,ans);
}

void TraversalRight(Node* root,vector<int> &ans){
    if(root == NULL || (root->left == NULL && root->right)){
        return;
    }

    if(root->right){
        TraversalRight(root->right,ans);
    }else{
        TraversalRight(root->left,ans);
    }

    ans.push_back(root->data);
}

vector<int> boundary(Node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }

    ans.push_back(root);

    TraversalLeft(root->left,ans);
    
    TraversalLeaf(root->left,ans);
    TraversalLeaf(root->right,ans);

    TraversalRight(root->right,ans);

    return ans;
}

int main(){
    
    return 0;
}