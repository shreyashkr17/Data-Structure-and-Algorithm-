#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

Node* newNode(int data){
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

int findPosition(vector<int> &inOrder,int element,int n){
    for(int i = 0;i<n;i++){
        if(inOrder[i] == element){
            return i;
        }
    }

    return -1;
}

Node* solve(vector<int> &inOrder,vector<int> &postOrder,int &index,int inOrderStart,int inOrderEnd){
    if(index < 0 || inOrderStart > inOrderEnd){
        return NULL;
    }

    int element = postOrder[index--];
    Node* temp = new Node(element);

    int position = findPosition(inOrder,element,n);


    // Recursive call
    root->right = solve(inOrder,postOrder,index,inOrderStart,inOrderEnd);
    root->left = solve(inOrder,postOrder,index,inOrderStart,inOrderEnd);

    return root;
}

Node* buildTree(vector<int> &inOrder,vector<int> &postOrder,int n){
    int postOrderIndex = n-1;
    Node* and = solve(inOrder,postOrder,postOrderIndex,0,n-1);

    return ans;
}

int main(){
    
    return 0;
}