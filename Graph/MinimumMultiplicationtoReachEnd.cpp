#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;
#define ll long long

int multiplicationMinimum(vector<int>& arr,int start,int end){
    queue<pair<int,int>> q;
    vector<int> dist(100000,1e9);

    dist[start] = 0;

    int mod = 100000;
    while(!q.empty()){
        int node = q.front().first;
        int steps = q.front().second;

        q.pop();

        for(auto it:arr){
            int num = (it*node)%mod;
            if(steps+1 < dist[num]){
                dist[num] = steps+1;

                if(num == end){
                    return steps+1;
                }
                q.push({num,steps+1});
            }
        }
    }
    return -1;

}
 
int main(){
    
    return 0;
}