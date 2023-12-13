#include <iostream>
// #include <bits/stdc++.h>
#include <queue>
#include <vector>
#include <set>
using namespace std;
#define ll long long

// Time Complexity: O(n+E)
// Space COmplexity: O(v)

bool isBipartite(int v,vector<vector<int>>& adj){
    queue<int> q;
    q.push(0);

    vector<int> color(v,-1);
    color[0] = 0;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto it:adj[node]){
            // if the adjacent node is not color, then make it opposite of the color of node
            if(color[it] == -1){
                color[it] = !color[node];
                q.push(it);
            }else if(color[it] == color[node]){
                return false;
            }
        }
    }
    return true;

}
 
int main(){
    
    return 0;
}