#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long


//Time Complexity: O(klogk)
//Space Complexity: O(k)


class Node{
    public:
        int data;
        int i;
        int j;

    Node(int data, int row, int col){
        this->data = data;
        i = row;
        j = col;
    }
};

class compare{
    public:
        bool operator()(Node* a, Node* b){
            return a->data > b->data;
        }
};

vector<int> mergeKsortedArrays(vector<vector<int>> &kArrays,int k){
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    //step1: saare arrays K first element insert h

    for(int i = 0;i<k;i++){
        Node* tmp = new Node(kArrays[i][0], i , 0);
        minHeap.push(tmp);
    } 

    vector<int> ans;

    //step 2:
    while(minHeap.size() > 0){
        Node* tmp = minHeap.top();
        ans.push_back(tmp->data);

        minHeap.pop();

        int i = tmp->i;
        int j = tmp->j;

        if(j+1 < kArrays[i].size()){
            Node* next = new Node(kArrays[i][j+1], i, j+1);

            minHeap.push(next);
        }
    }

    return ans;
}

int main(){
    
    return 0;
}