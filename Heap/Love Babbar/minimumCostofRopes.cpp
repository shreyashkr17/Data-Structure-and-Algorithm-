#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

//Time Compleixty: O(nlogn);
//Space Complexity: O(n); 

long long minCost(int arr[],long long n){
    priority_queue<long,long, vector<long long>, greater<long long>()> pq;

    for(int i = 0;i<n;i++){
        pq.push(arr[i]);
    }

    long long cost = 0;

    while(pq.size()>1){
        long long a = pq.top();
        pq.pop();

        long long b = pq.top();
        pq.pop();

        long long sum = a+b;
        cost += sum;
        pq.push(sum);
    }

    return cost;
}
 
int main(){
    return 0;
}