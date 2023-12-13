#include <iostream>
// #include <bits/stdc++.h>
#include <queue>
#include <set>
#include <vector>
#include <map>
#include <unordered_set>
#include <unordered_map>
using namespace std;
#define ll long long

// Time Complexity: O(ElogV) ---> E= Total Number of edges, v = number of nodes
// We use min heap in Dijkstra’s Algorithm because a node can have multiple weighted edges but for the shortest path, we have to consider the smallest weighted edge associated with a node. For this, we use a priority queue (min-heap) which gives us the minimum element on the top of the priority queue.

vector<int> dijkstra(int v,vector<vector<int>> adj[],int src){
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(v);
    for(int i =0;i<v;i++){
        dist[i] = 1e9;
    }

    dist[src] = 0;
    pq.push({0, src});
    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it: adj[node]){
            int edgeWeight = it[1];
            int adjNode = it[0];

            if(dis+edgeWeight < dist[adjNode]){
                dist[adjNode] = dis+edgeWeight;
                pq.push({dist[adjNode],adjNode});
            }
        }
    }

    return dist;
}
 
int main(){
    
    return 0;
}