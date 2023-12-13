#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long


//Time Complexity:O(log n); 


//Time complexity : O(n)

void heapify(int arr[],int n,int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left < n && arr[largest] < arr[left]){
        largest = left;
    }

    if(right < n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    } 
}

//Heap Sort
//Time Complexity: O(nlogn)
void heapSort(int arr[],int n){
    int size = n;

    while(size > 1){
        swap(arr[size],arr[1]);
        size--;

        heapify(arr,size,1);
    }
}

int main(){
    int arr[6] = {-1,54,53,55,52,50};
    int n = 5;

    for(int i=n/2; i>0 ;i--){
        heapify(arr,n,i);
    }

    cout<<"Printing the array now "<<endl;

    for(int i = 1;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;




    cout<<"Using Priority Queue:"<<endl;

    priority_queue<int> pq;

    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout<<"Element at top: "<<pq.top()<<endl;
    pq.pop();

    cout<<"Element at Top: "<<pq.top()<<endl;
    cout<<"Size is: "<<pq.size()<<endl;

    if(pq.empty()){
        cout<<"Priority queue is empty"<<endl;
    }else{
        cout<<"Pq is not empty"<<endl;
    }
    return 0;
}