#include <iostream>
// #include <bits/stdc++.h>
#include <set>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;
#define ll long long

int shortestPath(vector<vector<int>>& grid,pair<int,int>& source,pair<int,int>& dest){
    queue<pair<int,pair<int,int>>> q;
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dist(n,vector<int>(m,1e9));
    dist[source.first][source.second] = 0;
    q.push({0,{source.first,source.second}});

    vector<int> delRow = {-1,0,1,0};
    vector<int> delCol = {0,1,0,-1};

    while(!q.empty()){
        auto it = q.front();

        q.pop();
        int dis = it.first;
        int r = it.second.first;
        int c = it.second.second;

        for(    int i =0;i<4;i++){
            int newRow = r+delRow[i];
            int newCol = c+delCol[i];

            if(newRow>=0 && newRow<n && newCol>=0 && newCol < m && grid[newRow][newCol] == 1 && dis+1 < dist[newRow][newCol]){
                dist[newRow][newCol] =  1+dis;
                if(newRow == dest.first && newCol == dest.second){
                    return dis+1;
                }
                q.push({1+dis,{newRow,newCol}});
            }
        }

    }

    return -1;
}
 
int main(){
    
    return 0;
}