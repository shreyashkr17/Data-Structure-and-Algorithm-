#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
#define ll long long

// Time cOmplexity: O(n+2E)
// Space complexity :O(n) 

vector<int> bfsOfGraph(int v,vector<int> &adj){
    vector<int> visited(v,0);

    visited[0] = 1;
    queue<int> q;
    q.push(0);
    vector<int> bfs;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        bfs.push_back(node);
        for(auto it: adj[node]){
            if(!visited[it]){
                visited[it] = 1;
                q.push(it);
            }
        }
    }

    return bfs;

}

int main(){
    
    return 0;
}