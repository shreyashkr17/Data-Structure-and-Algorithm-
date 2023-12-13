#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
#define ll long long

vector<int> topoSortKahn(int v, vector<vector<int>>& adj){
    vector<int> indegree(v,0);
    
    for(int i =0;i<v;i++){
        for(auto it:adj[i]){
            indegree[i]++;
        }
    }

    queue<int> q;
    for(int i =0;i<v;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }

    return topo;
}
 
int main(){
    
    return 0;
}