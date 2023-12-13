#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

class info{
    public:
        int maxi;
        int mini;
        bool isBST;
        int size;
};

info solve(TreeNode<int>* root, int &ans){
    if(root == NULL){
        return {INT_MIN,INT_MAX,true,0};
    }

    info left = solve(root->left,ans);
    info right = solve(root->right,ans);

    info currNode;

    currNode.size = left.size + right.size+1;
    currNode.maxi = max(root->data,right.maxi);
    currNode.mini = min(root->data,left.mini);

    if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)){
        currNode.isBST = true;
    }else{
        currNode.isBST = false;
    }

    if(currNode.isBST){
        ans = max(ans,currNode.size);
    }

    return currNode;
}

int largestBST(TreeNode<int>* root){
    int maxSize = 0;
    info temp = solve(root,maxSize);

    return maxSize;

}

int main(){
    
    return 0;
}