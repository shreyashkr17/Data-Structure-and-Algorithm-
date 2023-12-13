#include <iostream>
// #include <bits/stdc++.h>
#include <queue>
#include <vector>
#include <set>
#include <stack>
using namespace std;
#define ll long long

// Time Complexity: O(v+2*e)

vector<int> shortestPath(vector<vector<int>>& edges,int n,int m,int src){
    vector<vector<int>> adj(n);

    for(auto it: edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<int> dist(n);

    for(int i=0;i<n;i++){
        dist[i] = INT_MAX;
    }

    dist[src] = 0;

    queue<int> q;

    q.push(src);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it:adj[node]){
            if(dist[node]+1 < dist[it]){
                dist[it] = 1+ dist[node];
                q.push(it);
            }
        }
    }

    vector<int> ans(n,-1);

    for(int i =0;i<n;i++){
        if(dist[i] != INT_MAX){
            ans[i] = dist[i];
        }
    }

    return ans;
}
 
int main(){
    
    return 0;
}