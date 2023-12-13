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

vector<int> djikstra(int v,vector<vector<int>> adj[],int src){
    set<pair<int,int>> st;
    vector<int> dist(v,1e9);

    st.insert({0,src});
    dist[src] = 0;

    while(!st.empty()){
        auto it = *(st.begin());
        int node = it.second;
        int dis = it.first;

        st.erase(it);

        for(auto it: adj[node]){
            int adjNode = it[0];
            int adjWeight = it[1];

            if(dis+adjWeight < dist[adjNode]){
                // erase if it existed
                if(dist[adjNode] != 1e9){
                    st.erase({dist[adjNode],adjNode});
                }

                dist[adjNode] = dis+adjWeight;
                st.insert({dist[adjNode],adjNode});

            }
        }
    }

    return dist;
}
 
int main(){
    
    return 0;
}