#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <set>
#include <queue>
#include <stack>
using namespace std;
#define ll long long

// Time Complexity: O(v+e)
// Space complexity: O(v) 

void dfs(int node,vector<int>& visited,stack<int>& st,vector<vector<int>>& adj){
    visited[node] = 1;

    for(auto it: adj[node]){
        if(!visited[it]){
            dfs(it,visited,st,adj);
        }
    }

    st.push(node);
}

vector<int> topoSort(int v, vector<vector<int>>& adj){
    vector<int> visited(v,0);
    stack<int> st;

    for(int i =0;i<v;i++){
        if(!visited[i]){
            dfs(i,visited,st,adj);
        }
    }

    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    return ans;

}
 
int main(){
    
    return 0;
}