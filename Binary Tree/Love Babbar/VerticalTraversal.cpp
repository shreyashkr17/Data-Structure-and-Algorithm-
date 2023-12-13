#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Time Complexity: O(nlogn);
// Space Complexity:O(1)+O(n) (Auxillary Space);

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val){
    Node* temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

vector<int> verticalTraversal(Node *root){
    map<int,pair<int,vector<int>>> nodeMap;
    queue<pair<Node*,pair<int,int>>> q;
    vector<int> ans;

    if(root == NULL){
        return ans;
    }

    q.push(root,make_pair(0,0));

    while(!q.empty()){
        pair<Node*,pair<int,int>> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int horizDist = temp.second.first;
        int level = temp.second.second;

        nodeMap[horizDist][level].push_back(frontNode->data);

        if(frontNode->left){
            q.push(make_pair(frontNode->left,make_pair(horizDist-1,level+1)));
        }

        if(frontNode->right){
            q.push(make_pair(frontNode->right,make_pair(horizDist+1,level+1)));
        }
    }

    for(auto it:nodeMap){
        for(auto jt:it.second){
            for(auto kt: jt.second){
                ans.push_back(jt);
            }
        }
    }

    return ans;
}

int main(){
    
    return 0;
}