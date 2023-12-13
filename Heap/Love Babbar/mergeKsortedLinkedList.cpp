#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

//Time COmplexity: O(n*klogk)
//Space COmplexity: O(k)

class compare{
    public:
        bool operator()(Node<int>* a, Node<int>* b){
            return a->data > b->data;
        }
};

Node*<int> mergeKList(vector<Node<int>*> &listArray){
    priority_queue<Node<int>* ,vector<Node<int>*>,compare> minHeap;

    int k = listArray.size();

    if(k == 0){
        return NULL;
    }

    for(int i = 0;i<k;i++){
        if(listArray[i] != NULL){
            minHeap.push(listArray[i]);
        }
    }

    Node<int>* head = NULL;
    Node<int>* tail = NULL;

    while(minHeap.size() > 0){
        Node<int>* temp = minHeap.top();

        minHeap.pop();

        if(temp->next != NULL){
            minHeap.push(temp->next);

        }

        if(head == NULL){
            head = temp;
            tail = temp;
        }else{
            tail->next = temp;
            tail = temp;
        }
    }

    return head;
}

int main(){
    
    return 0;
}