#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

//Time COmpleity: O(m+n);
//Space COmplexity: O(m+n);  

void inorder(TreeNode<int>* root,vector<int>& in){
    if(root == NULL){
        return ;
    }

    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}

vector<int> mergeArray(vector<int> &a,vector<int> &b){
    vector<int> ans (a.size()+b.size());
    int i = 0;,j = 0;
    int k = 0;

    while(i < a.size() && j< b.size()){
        if(a[i] < b[j]){
            ans[k++] = a[i];
            i++
        }else{
            ans[k++] = b[i];
        }
    }

    while(i < a.size()){
        ans[k++] = a[i];
        i++;
    }
    while(j < b.size()){
        ans[k++] = b[j];
        j++;
    }

    return ans;
}

TreeNode<int> *inorderToBST(int start, int end,vector<int> &in){
    if(start > end){
        return NULL;
    }

    int mid = (s+e)/2;
    TreeNode<int>* root = new TreeNode<inty>(in[mid]);
    root->left = inorderToBST(s,mid-1,in);
    root->right = inorderToBST(mid+1,end,in);
    return root;
}


int main(){
    vector<int> bst1,bst2;
    inorder(root1,bst1);
    inorder(root2,bst2);

    vector<int> mergedArray = mergeArrays(bst1,bst2);

    int start = 0,end = mergedArray.size()-1;
    return inorderToBST(start,end,mergedArray); 
    return 0;
}