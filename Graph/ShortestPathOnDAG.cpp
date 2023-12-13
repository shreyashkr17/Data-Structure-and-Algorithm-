#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <set>
#include <queue>
#include <stack>
using namespace std;
#define ll long long

void dfs(int node,vector<vector<pair<int,int>>>& adj,vector<int>& visited,stack<int>& st){
    visited[node] = 1;
    for(auto it: adj[node])
    {
        int v = it.first;
        if(!visited[v]){
            dfs(v,adj,visited,st);
        }
    }

    st.push(node);
}

vector<int> shortestPath(int n,int m,vector<vector<int>>& edges){
    vector<vector<pair<int,int>>> adj(n);

    for(int i =0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][wt];

        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }

    vector<int> visited(n,0);

    stack<int> st;
    for(int i =0;i<n;i++){
        if(!visited[i]){
            dfs(i,adj,visited,st);
        }
    }

    // Step 2 for the distance thing
    vector<int> dist(n);
    for(int i=0;i<n;i++){
        dist[i] = INT_MAX;
    }
    //if src  = 0
    dist[0] = 0;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        for(auto it: adj[node]){
            int v = it.first;
            int wt = it.second;
            if(dist[node]+wt < dist[v]){
                dist[v] = dist[node]+wt;
            }
        }
    }

    return dist;
}
 
int main(){
    
    return 0;
}