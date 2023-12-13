#include <iostream>
// #include <bits/stdc++.h>
#include <queue>
#include <set>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define ll long long

// Time Complexity: O(ElogV)
//  n x m x 4 x log(n x m)

int minimumEffort(vector<vector<int>>& heights){
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    int n = heights.size();
    int m = heights[0].size();

    vector<vector<int>> dist(n,vector<int>(m,1e9));
    dist[0][0] = 0;

    pq.push({0,{0,0}});
    vector<int> delRow = {-1,0,+1,0};
    vector<int> delCol = {0,1,0,-1};

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();

        int diff = it.first;
        int row = it.second.first;
        int col = it.second.second;

        if(row == n-1 && col == m-1){
            return diff;
        }

        for(int i =0;i<4;i++){
            int newRow = row+delRow[i];
            int newCol = col+delCol[i];

            if(newRow >=0 && newCol >= 0 && newRow < n && newCol<m ){
                int neweffort = max(abs(heights[row][col] - heights[newRow][newCol]),diff);
                if(neweffort < dist[newRow][newCol]){
                    dist[newRow][newCol] = neweffort;
                    pq.push({neweffort,{newRow,newCol}});
                }
            }
        }
    }

    return 0;
}

int main(){
    
    return 0;
}