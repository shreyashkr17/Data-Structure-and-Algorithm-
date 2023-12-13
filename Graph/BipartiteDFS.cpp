#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <set>
using namespace std;
#define ll long long

bool dfs(int node, int col,vector<int>& color,vector<vector<int>>& adj){
    color[node] = col;

    for(auto it:adj[node]){
        if(color[it] == -1){
            if(dfs(it,!col,color,adj) == false) return false;
        }else if(color[it] == col){
            return false;
        }
    }

    return true;
}

bool isBipartite(vector<vector<int>> adj,int v){
    vector<int> color(v,-1);

    for(int i = 0;i<v;i++){
        if(color[i] == -1){
            if(dfs(i,0,color,adj) == false) return false;
        }
    }
    return true;
}
 
int main(){
    
    return 0;
}