#include <iostream>
// #include <bits/stdc++.h>
#include <Vector>
#include <queue>
#include <set>
using namespace std;
#define ll long long

// Time Complexity: O(n*m + log(n*m) + (n*m*4))
// Space Complexity: O(n*m)

void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& visited,vector<pair<int,int>>& vec,int row0,int col0){
    visited[i][j] = 1;
    vec.push_back({i-row0,j-col0});

    int n = grid.size();
    int m = grid[0].size();

    vector<int> delRow = {-1,0,+1,0};
    vector<int> delCol = {0,-1,0,+1};

    for(int x = 0;x<4;x++){
        int nrow = i+delRow[x];
        int ncol = j+delCol[x];

        if(nrow >=0 && nrow < n && ncol >=0 && ncol < m && !visited[nrow][ncol] && grid[nrow][ncol] == 1)
        {
            dfs(nrow,ncol,grid,visited,vec,row0,col0);
        }
    }

}

int countDistinctIslands(vector<vector<int>>& grid){
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> visited(n,vector<int>(m,0));

    set<vector<pair<int,int>>> st;
    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(!visited[i][j] && grid[i][j] == 1){
                vector<pair<int,int>> vec;
                dfs(i,j,grid,visited,vec,i,j);
                st.insert(vec);
            }
        }
    }

    return st.size();

}
 
int main(){
    
    return 0;
}