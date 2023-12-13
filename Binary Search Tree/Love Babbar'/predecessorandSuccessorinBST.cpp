#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long


//Time Complexity :O(n);
//Space Complexity: O(1)

pair<int,int> predecessorSuccessor(Node<int>* root, int key){
    Node<int>* temp = root;

    int pred = -1;
    int succ = -1;


    while(temp->data!= key){
        if(temp->data > key){
            succ = temp->data;
            temp = temp->left;
        }else{
            pred = temp->data;
            temp = temp->right;
        }
    } 


    //Pred and succesor of the node 

    //Predeccessor of the node
    Node<int>* leftTree = temp->left;
    while(leftTree != NULL){
        pred = leftTree->data;
        leftTree = leftTree->right;
    }
    //Successor of the node;

    Node<int>* rightTree = temp->right;
    while(rightTree != NULL){
        succ = rightTree->data;
        rightTree = rightTree->left;
    }

    pair<int,int> ans = make_pair(pred,succ);
    return ans;

}   

int main(){
    
    return 0;
}