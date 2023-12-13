#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair<bool,int> isSumTreeFast(Node* root){
    if(root == NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }

    if(root->left == NULL && root->right == NULL){
        pair<bool,int> p = make_pair(true,root->data);
        return p;
    }

    pair<bool,int> leftAns = isSumTreeFast(root->left);
    pair<bool,int> rightAns = isSumTreeFast(root->right);

    bool isleftSumTree = leftAns.first;
    bool isRightSumTree = rightAns.first;

    int leftSUm = leftAns.second;
    int rightSum = rightAns.second;

    bool condn = root->data == leftAns.second+rightAns.second;

    pair<bool,int> ans;

    if(isleftSumTree && isRightSumTree && condn){
        ans.first = true;
        ans.second = 2*root->data;
    }else{
        ans.first = false;
    }

    return ans;
}

bool isSumTree(Node* root){
    return isSumTreeFast(root).first;
}

int main(){
    
    return 0;
}