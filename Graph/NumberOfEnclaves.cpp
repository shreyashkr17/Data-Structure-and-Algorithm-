#include <iostream>
// #include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;
#define ll long long

// Time Complexity : O(N*m*4)
// Space COmplexity : O(N*M)

int numberOfEnclave(vector<vector<int>> &grid){
    queue<pair<int,int>> q;
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> visited(n,vector<int>(m,0));

    for(int i=0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(i == 0 || j==0 || i== n-1 || j == m-1){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    visited[i][j] = 1;
                }
            }
        }
    }

    vector<int> delRow = {-1,0,+1,0};
    vector<int> delCol = {0,+1,0,-1};

    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().first;

        q.pop();

        // traverse all four direction
        for(int i =0;i<4;i++){
            int nRow = row+delRow[i];
            int nCol = col+delCol[i];

            if(nRow >=0 && nRow < n && nCol >=0 && nCol < m && visited[nRow][nCol] == 0 && grid[nRow][nCol] == 1){
                q.push({nRow,nCol});
                visited[nRow][nCol] = 1;
            }
        }
    }

    int cnt = 0;

    for(int i =0;i<n;i++){
        for(int j= 0;j<m;j++){
            if(grid[i][j] == 1 && visited[i][j] == 0){
                cnt++;
            }
        }
    }

    return cnt;
}
 
int main(){
    
    return 0;
}