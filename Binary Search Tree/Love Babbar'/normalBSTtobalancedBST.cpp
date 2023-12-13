#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void inorder(TreeNode<int>* root, vector<int> &in){
    if(root==NULL){
        return;
    }

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right,in);
}

TreeNode<int>* inorderToBST(int s, int e, vector<int> &in){
    //basecase
    if(s > e){
        return NULL;
    }

    int mid = (s+e)>>1;

    TreeNode<int>* root = new TreeNode<int>(in(mid));
    root->left = inorderToBST(s,mid-1, in);
    root->right = inorderToBST(mid+1,e,in);
    return root;
}

TreeNode<int>* balancedBST(TreeNode<int>* root){
    vector<int> inorderVal;

}

int main(){
    
    return 0;
}