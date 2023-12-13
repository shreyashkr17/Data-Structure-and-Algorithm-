#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

//Time Complexity: O()
//Sapce Complexity: O(k)

int kthSmallest(int arr[],int l,int r,int k){
    priority_queue<int> pq;


    //step 1
    for(int i =0 ;i<k;i++){
        pq.push(arr[i]);
    }

    //step2
    for(int i = k;i<=r;i++){
        if(arr[i] < pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    //ans = pq.top();

    int ans = pq.top();
    return ans;
}

int main(){
    
    return 0;
}