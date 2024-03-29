#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
#define ll long long

// Time COmplexity:O(n)+O(n*m*4)
// Space Complexity:  ((n*m))

void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>> &mat,vector<int> &delRow,vector<int> &delCol){
    vis[row][col] = 1;
    int n = mat.size();
    int m = mat[0].size();

    // check for the top, right, left, bottom
    vector<int> delRow = {-1,0,+1,0};
    vector<int> delCol = {0,+1,0,-1};

    for(int i = 0;i<4;i++){
        int nrow = row+delRow[i];
        int ncol = row+delCol[i];
        if(nrow >=0 && nrow < n && ncol >=0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] == 'O'){
            dfs(nrow,ncol,vis,mat,delRow,delCol);
        }
    }
}

vector<vector<char>> fill(int n,int m,vector<vector<char>> &mat){
     vector<vector<int>> vis(n,vector<int>(m,0));

    vector<int> delRow = {-1,0,+1,0};
    vector<int> delCol = {0,+1,0,-1};

     for(int j = 0;j<m;j++){
        if(!vis[0][j] && mat[0][j] == 'O'){
            dfs(0,j,vis,mat,delRow,delCol);
        }

        if(!vis[n-1][j] && mat[n-1][j] == 'O'){
            dfs(n-1,j,vis,mat,delRow,delCol);
        }
     }

     for(int i =0;i<n;i++){
        if(!vis[i][0] && mat[i][0] == 'O'){
            dfs(i,0,vis,mat,delRow,delCol);
        }
        if(!vis[i][m-1] && mat[i][m-1] == 'O'){
            dfs(i,m-1,vis,mat,delRow,delCol);
        }
     }

    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(!vis[i][j] && mat[i][j] == 'O'){
                mat[i][j] = 'X';
            }
        }
    }
}
 
int main(){
    
    return 0;
}