#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
#define ll long long

bool dfs(int node,int parent,vector<vector<int>>& adj,vector<int> &visited){
    visited[node] = 1;
    for(auto it:adj[node]){
        if(!visited[node]){
            if(dfs(it,node,adj,visited) == true){
                return true;
            }
        }else if(it!=parent){
            return true;
        }
    }
    return false;
}

bool isCycle(int v,vector<vector<int>> adj){
    vector<int> visited(v,0);
    for(int i = 0;i<v;i++){
        if(!visited[i]){
            if(dfs(i,-1,adj,visited) == true){
                return true;
            }
        }
    }
    return false;
}
 
int main(){
    
    return 0;
}