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
    temp->data = val;
    this->left = NULL;
    this->right = NULL;

    return temp; 
}

vector<int> leftView(Node* root){
    vector<int> ans;

    if(root == NULL){
        return ans;
    }

    if(level == ans.size()){
        ans.push_back(root->data);
    }

    solve(root->left,ans,level+1);
    solve(root->right,ans,level+1);

    return ans;
}

int main(){
    
    return 0;
}