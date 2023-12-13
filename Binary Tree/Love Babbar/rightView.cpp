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
    int val = temp->data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

vector<int> rightView(Node* root,int level){
    vector<int> ans;

    if(root == NULL){
        return ans;
    }
    // int level = 0;

    if(level == ans.size()){
        ans.push_back(root->data);
    }

    rightView(root->right,level+1);
    rightView(root->left,level+1);

    return ans;
}

int main(){
    
     return 0;
}