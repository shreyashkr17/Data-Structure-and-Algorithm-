#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
#define ll long long

// TIme Complexity: O(n+2*e)
// Space Complexity: 

bool detect(int src,vector<vector<int>> &adj,vector<int> &vis){
    vis[src] = 1;
    queue<pair<int,int>> q;
    q.push({src, -1});

    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto adjacentNode: adj[node]){
            if(!vis[adjacentNode]){
                vis[adjacentNode] = 1;
                q.push({adjacentNode,node});
            }else if(parent != adjacentNode){
                return true;
            }
        }
    }

    return false;
}

bool isCycle(int v,vector<vector<int>> adj){
    vector<int> vis = {0};
    for(int i = 0;i<v;i++){
        if(!vis[i]){
            if(detect(i,adj,vis)) return true;
        }
    }
    return false;
}
 
int main(){
    
    return 0;
}