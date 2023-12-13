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

int solve(Node* root,int sum,int &maxSum, int len,int &maxLen){
    if(root == NULL){
        if(len > maxLen){
            maxLen = len;
            maxSum = sum;
        }else if(len == maxlen){
            maxSum = max(sum,maxSum);
        }
        return;
    }

    sum = sum+root->data;

    solve(root->left,sum,maxSum,len+1,maxLen);
    solve(root->right,sum,maxSum,len+1,maxLen);
}
 
int sumofLongRootToLeafPath(Node* root){
    int len = 0;
    int maxLen = 0;

    int sum = 0;
    int maxSum = 0;

    solve(root,sum,maxSum,len,maxLen);

    return maxSum;
}