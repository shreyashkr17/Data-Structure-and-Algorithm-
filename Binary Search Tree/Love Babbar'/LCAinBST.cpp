#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

Node<int>* LCAinBST(Node<int>* root,Node<int>* p,Node<int>* q){
    if(root == NULL){
        return NULL;
    }

    if(root->data < p->data && root->data < q->data){
        return LCAinBST(root->right, P, Q);
    }
    if(root->data > p->data && root->data > q->data){
        return LCAinBST(root->left, P, Q);
    }

    return root;
}

int main(){
    
    return 0;
}