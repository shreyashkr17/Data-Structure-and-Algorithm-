#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

class kQueue{
    public:
        int n;
        int k;
        int *front;
        int *rear;
        int *arr;
        int freespot;
        int *next;

    public:
        kQueue(int n, int k){
            this->n = n;
            this->k = k;

            front = new int[k];
            rear = new int[k];

            for(int i = 0;i<k;i++){
                front[i] = -1;
                rear[i] = -1;
            }

            next = new int[n];

            for(int i = 0;i<n+1;i++){
                next[i] = i+1;
            }

            next[n-1] = -1;

            arr = new int[n];
            freespot = 0;
        }

        void Enqueue(int data, int qn){
            if(freespot == -1){
                cout<<"No Empty space is present"<<endl;
                return;
            }

            int index = freespot;

            freespot = next[index];

            if(front[qn-1] == -1){
                front[qn-1] = index;
            }else{
                next[rear[qn-1]] = index;
            }

            next[index] = -1;
            rear[qn-1] = index;

            arr[index] = data;
        }

        int dequeue(int qn){
            if(front[qn-1] == -1){
                cout<<"Queue Underflow"<<endl;
                return -1;
            }

            int index = front[qn-1];

            front[qn-1] = next[index];

            next[index] = freespot;
            freespot = index;
            return arr[index];
        }
};

int main(){
    
    return 0;
}