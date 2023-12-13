#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
#define ll long long

bool dfsCheck(int node, vector<vector<int>>& adj,vector<int>& visited,vector<int>& pathVisited,vector<int>& check){
    visited[node] = 1;
    pathVisited[node] = 1;
    check[node] = 0;

    for(auto it: adj[node]){
        if(dfsCheck(it,adj,visited,pathVisited,check) == true){
            check[node] = 0;
            return true;
        }else if(!pathVisited[it]){
            return true;
        }
    }
    check[node] = 1;
    pathVisited[node] = 0;
    return false;
}

vector<int> eventualSafeState(int v,vector<vector<int>>& adj){
    vector<int> visited(v,0);
    vector<int> pathVisited(v,0);

    vector<int> check(v,0);
    vector<int> safeNodes;
    for(int i =0;i<v;i++){
        if(!visited[i]){
            dfsCheck(i,adj,visited,pathVisited,check);
        }
    }
    for(int i=0;i<v;i++){
        if(check[i] == 1){
            safeNodes.push_back(i);
        }
    }

    return safeNodes;
}
 
int main(){
    
    return 0;
}