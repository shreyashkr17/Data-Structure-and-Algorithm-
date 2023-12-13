#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Node{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

//Time COmplexity: O(n)
//Space COmplexity: O(H)
 bool searchInBst(Node* root, int x){
    if(root == NULL){
        return false;
    }

    if(root->data == x){
        return true;
    }

    if(root->data >  x){
        return searchInBst(root->left, data);
    }else{
        return searchInBST(root->right, data);
    }
 }


 //Time Complexitry: O(h);

 bool searchInBST(Node* root, int data){
    Node* temp = root;

    while(temp != NULL){
        if(temp->data){
            return true;
        }
        if(temp->data > x){
            temp = temp->left;
        }else{
            temp = temp->right;
        }
    }

    return false; 
 }

 //Note: Inorder of Binary search tree is sorted, which means the minimum value of Tree is present in the left most part of the tree, and the maximum value of the tree is pressent in the right most part of the tree.

Node* deleteBSTNode(Node* root, int val){
    if(root == NULL){
        return root;
    }

    if(root->data == val){

        //0 child
        if(root->left == NULL && root->right ==NULL){
            delete root;
            return NULL;
        }

        //1 child

        //left child
        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        //right child
        if(root->left == NULL && root->right != NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        //2 child
        if(root->data != NULL && root->right != NULL){
            int mini = minVal(root->right)->data;
            root->data  = mini;
            root->right = deleteBSTNode(root->right, mini);
            return root;
        }


    }else if(root->data > val){
        //left part me jao
        root->left = deleteBSTNode(root->left,val);
        return root;
    }else{
        //right part mein jao
        root->right = deleteBSTNode(root->right,val);
        return root;
    }
}




int main(){
    
    return 0;
}