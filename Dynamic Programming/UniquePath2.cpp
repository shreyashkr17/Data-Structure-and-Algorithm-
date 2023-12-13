#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define ll long long
// Time Complexity: O(m*n)
// Space Complexity: O((N-1)+(M-1)) + O(M*N)

int countWaysUtil(int i,int j,vector<vector<int>>& dp,vector<vector<int>>& mat){
    if(i>=0 && j>=0 && mat[i][j] == -1){
        return 0;
    }
    if(i==0 && j==0){
        return 1;
    }
    if(i <0 || j<0){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int up = countWaysUtil(i-1,j,dp,mat);
    int left = countWaysUtil(i,j-1,dp,mat);

    return dp[i][j] = up+left;
}

int countWays(int m,int n,vector<vector<int>>& mat){
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return countWaysUtil(m-1,n-1,dp,mat);
}
 
int main(){
    
    return 0;
}