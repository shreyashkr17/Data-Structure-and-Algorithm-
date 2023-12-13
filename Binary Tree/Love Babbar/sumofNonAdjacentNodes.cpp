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

pair<int,int> solve(Node* root){
    if(root == NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int,int> tempLeft = solve(root->left);
    pair<int,int> tempRight = solve(root->right);

    pair<int,int> res;

    res.first = root->data+left.second+right.second;
    res.second = max(tempLeft.first,tempLeft.second) + max(tempRight.first,tempRight.second);

    return res; 
}

int getMaxSumofNonAdjacent(Node *root){
    pair<int,int> ans = solve(root);
    return max(ans.first,ans.second);
}

int main(){
    
    return 0;
}