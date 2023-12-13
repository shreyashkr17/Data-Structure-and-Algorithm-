#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;
#define ll long long

// Why N-1?
// Soln:        since in a graph of n nodes, in worst case, you will take n-1 edges to reach from the first to the last, thereby we iterate for n-1 iterations. 

vector<int> bellman_ford(int v,vector<vector<int>>& edges,int src){
    vector<int> dist(v,1e8);
    dist[src] = 0;

    for(int i =0;i<v-1;i++){
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if(dist[u] != 1e8 && dist[u] +wt < dist[v]){
                dist[v] = dist[u]+wt;
            }
        }
    }

    // Nth relaxation to check negative cycle
    for(auto it:edges){
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        if(dist[u] != 1e8 && dist[u]+wt < dist[v]){
            return {-1};
        }
    }

    return dist;
}
 
int main(){
    
    return 0;
}