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

int countWaysUtil(int i,int j,vector<vector<int>>& dp){
    if(i==0 && j==0){
        return 1;
    }
    if(i <0 || j<0){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int up = countWaysUtil(i-1,j,dp);
    int left = countWaysUtil(i,j-1,dp);

    return dp[i][j] = up+left;
}

int countWays(int m,int n){
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return countWaysUtil(m-1,n-1,dp);
}


// Second Ways
// Time Complexity:O(m*n)
// Space Complexity:O(m*n)

int countWaysUtil2(int m,int n,vector<vector<int>>& dp){
    for(int i=0; i<m ;i++){
        for(int j=0; j<n; j++){
            
            //base condition
            if(i==0 && j==0){
                dp[i][j]=1;
                continue;
            }
            
            int up=0;
            int left = 0;
            
            if(i>0) 
                up = dp[i-1][j];
            if(j>0)
                left = dp[i][j-1];
                
            dp[i][j] = up+left;
        }
    }
  
    return dp[m-1][n-1];
}

int countWays2(int m,int n){
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return countWaysUtil2(m,n,dp);
}
 
int main(){
    
    return 0;
}