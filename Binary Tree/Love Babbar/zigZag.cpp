#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Time Complexity: O(n)
// Space Complexity: O(n)

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val){
    Node* temp = new Node;
    temp->data = val;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}

vector<int> zigZagTraversal(Node* root){
    vector<int> result;
    if(root == NULL){
        return result;
    }

    queue<Node* > q;
    q.push(root);

    bool leftToRide = true;

    while(!q.empty()){
        int size = q.size();
        vector<int> ans(size);

        for(int i = 0;i<size;i++){
            Node* frontNode = q.front();

            q.pop();

            int index = leftToRight ? i:size-i-1;
            ans[index] = frontNode->data;

            if(frontNode->left){
                q.push(frontNode->left);
            }

            if(frontNode->right){
                q.push(frontNode->right);
            }
        }

        leftToRight = !leftToRide;

        for(auto i:ans){
            result.push_back(i);
        }
    }

    return result;
}

int main(){
    
    return 0;
}