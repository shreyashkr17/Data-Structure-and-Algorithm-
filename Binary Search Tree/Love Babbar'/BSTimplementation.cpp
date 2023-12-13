#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long


// Insertion Time Complexity: O(log n)
 
class Node{
    public :
        int data;
        Node* left;
        Node* right;


    Node(int d){
        this->left = NULL;
        this->right = NULL;
        this->data = d;
    }
};

Node* insertIntoBST(Node* &root,int data){
    if(root == NULL){
        root= new Node(data);
        return root; 
    }

    if(data >root->data){
        root->right = insertIntoBST(root->right,data);
    }else{
        root->left = insertIntoBST(root->left,data);
    }
}

void takeInput(Node* &root){
    int data;
    cin>>data;

    while(data != -1){
        insertIntoBST(root,data);
        cin>>data;
    }
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

void InOrder(Node* root){

}

void PreOrder(Node* root){

}

void PostOrder(Node* root){

}


int main(){
    
    return 0;
}