#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
} ;

Node* newNode(int value){
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

int findPosition(vector<int>& inorder,int element,int n){
    for(int i = 0;i<n;i++){
        if(inorder[i] == element){
            return i;
        }
    }
    return -1;
}

Node* solve(vector<int> &inorder,vector<int> &preOrder,int &index,int inOrderStart,int inOrderEnd){
    if(index >= n || inOrderStart > inOrderEnd){
        return NULL;
    }

    int element = preOrder[index++];
    Node* root = new Node(element);

    int position = findPostion(inorder,element,n);

    //Recursive calls
    root->left = solve(inorder,preOrder,index,inOrderStart,inOrderEnd);
    root->right = solve(inorder,preOrder,index,inOrderStart,inOrderEnd);

    return root;

}

Node* buildTree(vector<int> &inorder,vector<int> &preOrder,int n){
    int preOrderIndex = 0;
    Node* ans = solve(inorder,preOrder,preOrderIndex,0,n-1);
    return ans;
}

int main(){
    
    return 0;
}