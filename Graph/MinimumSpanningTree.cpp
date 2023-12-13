#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;
#define ll long long

// A tree in which we have N nodes & n-1 edges and all nodes are reachable from each other

// Time complexity: ElogE
// Space Complexity: O(E)

int minimumSpanningTree(int v,vector<vector<int>>& adj){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    vector<int> visited(v,0);

    pq.push({0,0}); //{weight,node}
    int sum = 0;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int weight = it.first;


        if(visited[node] == 1){
            continue;
        }
        visited[node] = 1;
        sum+=weight;
        for(auto it:adj[node]){
            int adjNode = it[0];
            int adjWeight = it[1];
            if(!visited[adjNode]){
                pq.push({adjWeight,adjNode});
            }
        }
    }

    return sum;

}
 
int main(){
    
    return 0;
}