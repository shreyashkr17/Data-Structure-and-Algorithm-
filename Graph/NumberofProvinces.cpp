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

class Disjoint{
    // vector<int> rank,parent,size;
    public:
        vector<int> rank,parent,size;
        Disjoint(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            size.resize(n+1);
            for(int i = 0;i<=n;i++){
                parent[i] = i;
                size[i] = i;
            }
        }

        int findPar(int node){
            if(node == parent[node]){
                return node;
            }
            return parent[node] = findPar(parent[node]);
        }

        void unionByRank(int u,int v){
            int ulp_u = findPar(u);
            int ulp_v = findPar(v);

            if(ulp_u == ulp_v){
                return;
            }

            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_v] = ulp_u;
            }else if(rank[ulp_v] < rank[ulp_u]){
                parent[ulp_v] = ulp_u;
            }else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }

        void unionBySize(int u,int v){
            int ulp_u = findPar(u);
            int ulp_v = findPar(v);

            if(ulp_u == ulp_v){
                return;
            }

            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v]+=size[ulp_u];
            }else{
                parent[ulp_v] = ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
        }
};


int numberOfProvinces(vector<vector<int>>& adj,int v){
    Disjoint ds(v);
    for(int i =0;i<v;i++){
        for(int j = 0;j<v;j++){
            if(adj[i][j] == 1){
                ds.unionBySize(i,j);
            }
        }
    }

    int cnt = 0;
    for(int i =0;i<v;i++){
        if(ds.parent[i] == i){
            cnt++;
        }
    }
    return cnt;
}
 
int main(){
    
    return 0;
}