//Heap is a complete binary tree that comes along with Heap order property
//Complete Binary tree can be defined its every level is comletely filled except the last level
//Nodes always added from the left .

 //left child always present at 2*i;
 //right child always be pressent at 2*i+1
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
 class heap{
    public:
        int arr[100];
        int size = 0;
    
    heap(){
        arr[0] = -1;
        size = 0;
    }

    //Time Complexity :O(log n)
    void insert(int val){
        size = size+1;
        int index = size;
        arr[index] = val;

        while(index > 1){
            int parent = index/2;

            if(arr[parent] < arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;
            }else{
                return;
            }
        }
    }

    //Time Compleixty: O(log n) 
    void deletefromHeap(){
        if(size == 0){
            cout<<"Nothing to delete"<<endl;
            return;
        }

        arr[1] = arr[size];
        size--;

        int i = 1;
        while(i <size){
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;

            if(leftIndex < size && arr[i] < arr[leftIndex]){
                swap(arr[i],arr[leftIndex]);
                i = leftIndex;
            }else if(rightIndex < size && arr[i] < arr[rightIndex]){
                swap(arr[i],arr[rightIndex]);
                i = rightIndex;
            }else{
                return;
            }
        }
    }

    void print(){
        for(int i = 1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
 };

 int main(){
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();
 }