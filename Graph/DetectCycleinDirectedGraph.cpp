#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
#define ll long long

bool dfsCheck(int node,vector<vector<int>>& adj,vector<int>& visited,vector<int>& pathVisited){
    visited[node] = 1;
    pathVisited[node] = 1;
    for(auto it: adj[node]){
        if(!visited[it]){
            if(dfsCheck(it,adj,visited,pathVisited) == true){
                return true;
            }else if(pathVisited[it]){
                return true;
            }
        }
    }

    pathVisited[node] = 0;
    return false;
}

bool isCyclic(int v,vector<vector<int>>& adj){
    vector<int> visited(v,0);
    vector<int> pathVisted(v,0);

    for(int i =0;i<v;i++){
        if(!visited[i]){
            if(dfsCheck(i,adj,visited,pathVisited) == true)    
                return true;
        }
    }

    return false;
}
 
int main(){
    
    return 0;
}