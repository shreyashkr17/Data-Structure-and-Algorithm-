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
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

void solve(Node* root,int k,int &count,vector<int> &path){
    if(root == NULL){
        return ;
    }

    path.push_back(root->data);

    solve(root->left,k,count,path);
    solve(root->right,k,count,path);

    int size = path.size();
    int sum = 0;

    for(int i = size-1;i>=0;i--){
        sum += path[i];
        if(sum == k){
            count++;
        }
    }

    path.pop_back();
}

int sumK(Node* root,int k){
    vector<int> path;
    int count = 0;
    solve(root,k,count,path);
    return path;
}

int main(){
    
    return 0;
}