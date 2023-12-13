#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

Node* newNode(int val){
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

Node* solve(Node* root, int &k,int node){
    if(root == NULL){
        return NULL;
    }

    if(root->data == node){
        return root;
    }

    Node* leftAns = solve(root->left,k,node);
    Node* rightAns = solve(root->right,k,node);

    if(leftAns != NULL && rightAns== NULL){
        k--;
        if(k <= 0){
            k = INT_MAX;
            return root;
        }

        return leftAns;
    }

    if(leftAns == NULL && rightAns!=NULL){
        k--;
        if(k <= 0){
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }

    return NULL;
}

int kthAncestor(Node* root,int k,int node){
    Node* ans = solve(root,k,node);

    if(ans == NULL || ans->data == node){
        return -1;
    }else{
        return ans->data;
    }
}



int main(){
    
    return 0;
}