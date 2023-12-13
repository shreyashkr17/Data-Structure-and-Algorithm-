#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
//TIme COmplexity: O(n);
//Space Complexity: O(n);

void inorder(Node<int>* root, vector<int> &in){
    if(root == NULL){
        return;
    }

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right,in);
}

bool twoSUminBST(NODE<int>* root, int target){
    vector<int> inorderVal;
    inorder(root,inorderVal); 

    int i = 0,j=inorderVal.size()-1;

    while(i < j){
        int sum = inorderVal[i]+inorder[j];

        if(sum == target){
            return true;
        }else if(sum > target){
            j--;
        }else{
            i++;
        }
    }

    return false;

}

int main(){
    
    return 0;
}