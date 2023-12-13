#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

//Time Complexity: O(n*k^2);
//Time Complexity: O(k)

void findSmallestRange(vector<vector<int>> &arr, int K, int N){
    int i,minval,maxval,minrange,minel,maxel,flag,minind;

    vector<int> ptr(K);

    for(int i = 0;i<K;i++){
        ptr[i] = 0;
    }

    minrange = INT_MIN;

    while(1){
        minind = -1;
        minval = INT_MAX;
        maxval = INT_MIN;

        flag = 0;

        for(int i = 0;i<K;i++){
            if(ptr[i] == N){
                flag = 1;
                break;
            }

            if(ptr[i] < N && arr[i][ptr[i]] > minval){
                minind = i;
                minval = arr[i][ptr[i]];
            }

            if(ptr[i] < N && arr[i][ptr[i]] > maxval){
                maxval = arr[i][ptr[i]];
            }
        }

        if(flag){
            break;
        }

        ptr[minind]++;

        if((maxval-minval) < minrange){
            minel = minval;
            maxel = maxval;
            minrange = maxel-minel;
        }
    }

    cout<<"The smallest range is: "<<minel<<" "<<maxel<<endl;

}

int main(){
    vector<vector<int>> arr = {{ 4, 7, 9, 12, 15 },{ 0, 8, 10, 14, 20 },{ 6, 12, 16, 30, 50 }};

    int k = arr.size();
    int n = arr[0].size();

    findSmallestRange(arr,k,n);
    return 0;
}








//Time Complexity: O(n*k*log(k));
//Space Complexity: O(k)

class Node{
    public:
        int data;
        int row;
        int col;

    Node(int data, int row, int col){
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class comapre{
    public:
        bool operator()(Node* a, Node* b){
            return a->data > b->data;
        }
};

int kSorted(vector<vector<int>> &a, int k, int n){
    int mini = INT_MAX, maxi = INT_MIN;
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    for(int i = 0;i<k;i++){
        int element = a[i][0];
        mini = min(mini,element);
        maxi = max(maxi,element);
        minHeap.push(element);
    }

    int start = mini,end = maxi;

    while(!minHeap.empty()){
        Node* temp = minHeap.top();
        minHeap.pop();

        mini = temp->data;

        if(maxi-mini < end-start){
            start = mini;
            end = maxi;
        }

        if(temp->col+1 < n){
            maxi = max(maxi,a[temp->row][temp->col+1]);
            minHeap.push(new Node(a[temp->row][temp->col+1],temp->row,temp->col+1));
        }else{
            break;
        }
    }

    return (end-start+1);

}