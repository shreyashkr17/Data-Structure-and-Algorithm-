#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <set>
#include <stack>
using namespace std;
#define ll long long

bool isPossible(int n,vector<pair<int,int>>& prerequisite){
    vector<vector<int>> adj(n);

    for(auto it:prerequisite){
        adj[it.first].push_back(it.second);
    }

    vector<int> indegree(n,0);

    for(int i =0;i<n;i++){
        for(auto it:adj[i]){
            indegree[i]++;
        }
    }

    queue<int> q;
    for(int i =0;i<n;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();

        topo.push_back(node);
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);
            }
        }
    }

    if(topo.size() == n){
        return false;
    }
    return true;
}

int main(){
    
    return 0;
}