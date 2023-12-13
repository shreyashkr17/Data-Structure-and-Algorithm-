#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val){
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

vector<int> bottomView(Node* root){
    vector<int> ans;
    map<int,int> topNode;
    queue<pair<Node*,int>> q;

    if(root == NULL){
        return ans;
    }

    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<Node*,int> temp = q.front();

        q.pop();
        Node* frontNode = temp.first;
        int horizDist = temp.second;

        topNode[horizDist] = firstNode->data;

        if(firstNode->left){
            q.push(make_pair(frontNode->left,horizDist-1));
        }

        if(firstNode->right){
            q.push(make_pair(firstNode->right,horizDist+1));
        }
    }

    for(auto i:topNode){
        ans.push_back(i.second);
    }

    return ans;
}



int main(){
    
    return 0;
}