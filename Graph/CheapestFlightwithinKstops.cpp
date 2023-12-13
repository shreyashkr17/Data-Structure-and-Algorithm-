#include <iostream>
// #include <bits/stdc++.h>
#include <queue>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define ll long long

int cheapestFlight(int n,vector<vector<int>>& flights,int src,int dst,int k){
    vector<vector<pair<int,int>>> adj(n);
    for(auto it: flights){
        adj[it[0]].push_back({it[1],it[2]});
    }

    queue<pair<int,pair<int,int>>> q;
    q.push({0,{src,0}});
    vector<int> dist(n,1e9);

    while(!q.empty()){
        auto it = q.front();
        q.pop();

        int stops = it.first;
        int node = it.second.first;
        int cost = it.second.second;

        if(stops > k){
            continue;
        }

        for(auto it:adj[node]){
            int adjNode = it.first;
            int adjWeight = it.second;

            if(cost+adjWeight < dist[adjNode] && stops <= k){
                dist[adjNode] = cost+adjWeight;
                q.push({stops+1,{adjNode,cost+adjWeight}});
            }
        }
    }

    dist[src] = 0;
    if(dist[dst] == 1e9){
        return -1;
    }

    return dist[dst];


}
 
int main(){
    
    return 0;
}