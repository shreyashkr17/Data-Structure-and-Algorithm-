#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
using namespace std;
#define ll long long

// Space complexity: O(n)
// Time COmplexity: O(n+e)

void dfs(int node, vector<int> &adj,vector<int> &visited,vector<int> &ls){
    visited[node] = 1;
    ls.push_back(node);
    for(auto it: adj[node]){
        if(!visited[it]){
            dfs(it,adj,visited,ls);
        }
    }
}

vector<int> dfsOfGraph(int v, vector<int> &adj){
    vector<int> visited(v,0);
    int start = 0;
    vector<int> ls;
    dfs(start,adj,visited,ls);
}
 
int main(){
    
    return 0;
}