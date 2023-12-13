#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long


//Time Complexity: O(n)
//Space Complexity: O(n)

void inorderTraversal(TreeNode* root,vector<int> arr){
    if(root == NULL){
        return;
    }

    inorderTraversal(root->left,arr);
    arr.push_back(root->data);
    inorderTraversal(root->right,arr);
}

void BSTtoMinHeap(TreeNode *root,vector<int> arr,int &i){
    if(root == NULL){
        return;
    }

    root->data = arr[++i];
    BSTtoMinHeap(root->left,arr,i);
    BSTtoMinHeap(root->data,arr,i);
}

void convertToMinHeapUtil(TreeNode* root){
    vector<int> arr;

    int i = -1;
    inorderTraversal(root,arr);
    BSTtoMinHeap(root,arr,i);
}

void BSTtoMinHeap(TreeNode* root){
    convertToMinHeapUtil(root);
    preOrderTraversal(root);
}

int main(){
    
    return 0;
}