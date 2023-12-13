#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <stack>
using namespace std;
#define ll long long

bool isCyclic(int v,vector<vector<int>>& adj){
    vector<int> indegree(v,0);
    for(int i =0;i<v;i++){
        for(auto it:adj[i]){
            indegree[it]++;
        }
    }

    queue<int> q;
    for(int i =0;i<v;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    int cnt = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();

        cnt++;

        for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);
            }
        }
    }

    if(cnt == v){
        return false;
    }
    return true;
}
 
int main(){
    
    return 0;
}