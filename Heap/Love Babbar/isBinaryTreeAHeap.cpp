#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long


//Time Compleixty: O(n);
//Space Compleity: O()
int countNode(TreeNode* root){
    if(root == NULL){
        return 0;
    }

    int ans = 1+countNode(root->left)+countNode(root->right);

    return ans;
}

bool isCBT(TreeNode *Node, int index, int cnt){
    if(root == NULL){
        return true;
    }

    if(index >= cnt){
        return false;
    }else{
        bool left = isCBT(root->left,2*index+1,cnt);
        bool right = isCBT(root->right,2*index+2,cnt);

        return (left && right);
    }
}

bool isMaxOrder(TreeNode* root){
    if(root->left == NULL && root->right == NULL){
        return true;
    }

    if(root->right == NULL){
        return (root->data > root->left->data);
    }else{
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);

        return (left && right  && (root->data > root->left->data && root->data > root->right->data))
    }
}

bool isHeap(TreeNode* root){
    int index = 0;
    int totalCount = countNode(root);

    if(isCBT(root,index,totalCount)  &&  isMaxOrder(root)){
        return true;
    }else{
        return false;
    }
}

int main(){
    
    return 0;
}